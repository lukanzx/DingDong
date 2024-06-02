#include "Chat_Server.h"

Map_Database_Logical_To_Online_User *
        Chat_Server::Map_DLTOUO = new Map_Database_Logical_To_Online_User();

database_Service_Layer *
        Chat_Server::Data_CONO = new database_Service_Layer();

Chat_Server::Chat_Server() {

    Data_CONO->set_Database_Name(MysqlInfo::database_name.c_str());
    Data_CONO->set_Host_And_Port(MysqlInfo::host.c_str(), MysqlInfo::port);
    Data_CONO->set_User_And_Password(MysqlInfo::user.c_str(), MysqlInfo::password.c_str());
    Data_CONO->init_database();

    base = event_base_new();

    struct sockaddr_in Chat_Server_addr;
    memset(&Chat_Server_addr, 0, sizeof(Chat_Server_addr));
    Chat_Server_addr.sin_family = AF_INET;
    Chat_Server_addr.sin_port = htons(ServerInfo::port);

    inet_pton(AF_INET, ServerInfo::ip.c_str(), &(Chat_Server_addr.sin_addr));

    listener = evconnlistener_new_bind(
            base,
            listener_cb,
            NULL,
            LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE,
            10,
            (struct sockaddr *) &Chat_Server_addr,
            sizeof(Chat_Server_addr)

    );

    if (listener == NULL) {
        cout << "evconnlistener_new_bind error!" << endl;
    }

    event_base_dispatch(base);
}

Chat_Server::~Chat_Server() {
    event_base_free(base);
}

void Chat_Server::listener_cb(
        struct evconnlistener *listener,
        evutil_socket_t fd,
        struct sockaddr *addr,
        int socklen,
        void *arg

) {
    thread client_thread(client_handler, fd);
    client_thread.detach();
}

void Chat_Server::client_handler(int fd) {

    struct event_base *base = event_base_new();

    struct bufferevent *bev = bufferevent_socket_new(
            base,
            fd,
            BEV_OPT_CLOSE_ON_FREE
    );
    if (bev == NULL) {
        return;
    }
    struct MyContext myCtx;
    myCtx.base = base;

    bufferevent_setcb(bev, read_cb, NULL, event_cb, &myCtx);
    bufferevent_enable(bev, EV_READ);
    event_base_dispatch(base);
    event_base_free(base);

}

void Chat_Server::read_cb(struct bufferevent *bev, void *ctx) {
    MyContext *myCtx = static_cast<MyContext *>(ctx);
    struct event_base *base = myCtx->base;

    std::string buffer;

    Json::Reader reader;
    Json::FastWriter writer;
    Json::Value val;
    int size;
    try {
        char buf[1024] = {0};

        size = bufferevent_read(bev, buf, sizeof(buf));
        if (size < 0) {
            throw std::runtime_error("bufferevent_read error");
        }
        buffer += std::string(buf, size);
        while (true) {
            size_t msgStartPos = buffer.find('{');
            size_t msgEndPos = buffer.find('}', msgStartPos);
            if (msgStartPos != std::string::npos && msgEndPos != std::string::npos) {
                std::string msg = buffer.substr(msgStartPos, msgEndPos - msgStartPos + 1);
                buffer.erase(0, msgEndPos + 1);
                if (!reader.parse(msg, val)) {
                    throw std::runtime_error("The server failed to parse the data sent by the client.");
                }
                string cmd = val["cmd"].asString();
                read_cb_handle(base, cmd, bev, val, ctx);
            } else {
                break;
            }
        }
    }
    catch (const std::exception &ex) {
        bufferevent_free(bev);
        event_base_loopbreak(base);
    }
    catch (...) {
        bufferevent_free(bev);
        event_base_loopbreak(base);
    }
}

void Chat_Server::event_cb(
        struct bufferevent *bev,
        short events, void *ctx

) {
    MyContext *myCtx = static_cast<MyContext *>(ctx);
    if (events & BEV_EVENT_CONNECTED) {
    } else if (events & BEV_EVENT_EOF) {
        Map_DLTOUO->delete_Online_User_From_online_User_Set(myCtx->user_id);
        bufferevent_free(bev);
    } else if (events & BEV_EVENT_ERROR) {
        bufferevent_free(bev);
    } else if (events & BEV_EVENT_TIMEOUT) {
        bufferevent_free(bev);
    } else if (events & BEV_EVENT_READING) {
    } else if (events & BEV_EVENT_WRITING) {
    } else {
        bufferevent_free(bev);
    }
}

void Chat_Server::read_cb_handle(
        event_base *base,
        string cmd,
        bufferevent *bev,
        Json::Value val,
        void *ctx

) {

    if (cmd == "RegisterAccountReq") {

    } else if (cmd == "DeleteFriendReq") {

    } else if (cmd == "LoginReq") {
        Login_Request(base, bev, val, ctx);
    } else if (cmd == "SearchFriendReq") {

    } else if (cmd == "SearchGroupReq") {

    } else if (cmd == "AddFriendReq") {

    } else if (cmd == "AddGroupReq") {

    } else if (cmd == "CreateGroupReq") {

    } else if (cmd == "OfflineReq") {

    } else if (cmd == "GetFriendsListReq") {

    } else if (cmd == "GetGroupsListReq") {

    } else if (cmd == "ChatWithFriendReq") {
        Chat_with_friend_Request(base, bev, val, ctx);
    } else if (cmd == "ChatWithGroupReq") {

    } else if (cmd == "GetFriendChatHistoryReq") {

    } else if (cmd == "GetGroupChatHistoryReq") {

    } else {
        std::cout << "Not Server" << endl;
    }
}

void Chat_Server::Register_account_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Delete_friend_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Login_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

    MyContext *myCtx = static_cast<MyContext *>(ctx);

    Data_CONO->connect();

    int user_id = val["id"].asInt();
    string user_password = val["password"].asString();

    if (Data_CONO->account_Of_User_Is_Exist(user_id) == false) {

        Json::Value val;
        val["cmd"] = "LoginResp";
        val["result"] = false;
        string s = Json::FastWriter().write(val);
        if (bufferevent_write(bev, s.c_str(), strlen(s.c_str())) < 0) {
            cout << "bufferevent_write error" << endl;
        }

        Data_CONO->disconnect();
        bufferevent_free(bev);
        event_base_loopbreak(base);
        return;
    } else {

        if (Data_CONO->verify_Account_Of_User_password_Is_True(user_id, user_password) == false) {

            Json::Value val;
            val["cmd"] = "LoginResp";
            val["result"] = false;
            string s = Json::FastWriter().write(val);
            if (bufferevent_write(bev, s.c_str(), strlen(s.c_str())) < 0) {
                cout << "bufferevent_write error" << endl;
            }

            Data_CONO->disconnect();
            bufferevent_free(bev);
            event_base_loopbreak(base);
            return;
        } else {
            if (Map_DLTOUO->add_Online_User_To_online_User_Set(user_id, bev) == true) {
                Json::Value v1 = Data_CONO->get_Account_Of_User_Information(user_id);
                string s = Json::FastWriter().write(v1);
                if (bufferevent_write(bev, s.c_str(), strlen(s.c_str())) < 0) {
                    cout << "bufferevent_write error" << endl;
                }
            }
            Data_CONO->disconnect();
        }
    }
}

void Chat_Server::Search_friend_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Search_group_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Add_friend_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx
) {

}

void Chat_Server::Add_group_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Create_group_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Offline_notification_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Get_friends_list_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Get_groups_list_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Chat_with_friend_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {
    int target = val["targetId"].asInt();
    struct bufferevent *target_bev = Map_DLTOUO->get_UserAccount_Bev_From_Online_User_Set(target);
    if (target_bev == NULL) {
        Data_CONO->connect();
        int sendId = val["sendId"].asInt();
        int targetId = val["targetId"].asInt();
        string time = val["time"].asString();
        string content = val["content"].asString();
        Data_CONO->insert_Friend_Messages(sendId, targetId, time, content, "0");
        Data_CONO->disconnect();
    } else {
        val["cmd"] = "ChatResp";
        val["groupId"] = 0;
        string s = Json::FastWriter().write(val);
        if (bufferevent_write(target_bev, s.c_str(), strlen(s.c_str())) < 0) {
            cout << "bufferevent_write error" << endl;
        } else {
        }
    }
}

void Chat_Server::Chat_with_group_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx

) {

}

void Chat_Server::Get_friend_chat_history_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx
) {

}

void Chat_Server::Get_group_chat_history_Request(
        struct event_base *base,
        struct bufferevent *bev,
        Json::Value val,
        void *ctx
) {

}
