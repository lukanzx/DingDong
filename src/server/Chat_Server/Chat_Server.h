#pragma once

#include <iostream>
#include <string.h>
#include <event.h>
#include <random>
#include <set>
#include <event2/listener.h>
#include <thread>
#include <jsoncpp/json/json.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "Map_Database_Logical_To_Online_User.h"
#include "database_Service_Layer.h"

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::thread;
using std::vector;

class database_Service_Layer;

struct MyContext {
    struct event_base *base;
    int user_id;
};

class Chat_Server {

public:

    struct event_base *base;
    struct evconnlistener *listener;
    static Map_Database_Logical_To_Online_User *Map_DLTOUO;
    static database_Service_Layer *Data_CONO;

public:

    static void
    listener_cb(
            struct evconnlistener *listener,
            evutil_socket_t fd,
            struct sockaddr *addr,
            int socklen,
            void *arg

    );

    static void client_handler(int);

    static void read_cb(
            struct bufferevent *bev,
            void *ctx

    );

    static void
    read_cb_handle(
            struct event_base *base,
            string cmd,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void event_cb(
            struct bufferevent *bev,
            short what,
            void *ctx

    );

public:

    static void
    Register_account_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Delete_friend_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Login_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Search_friend_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Search_group_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Add_friend_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Add_group_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Create_group_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Offline_notification_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Get_friends_list_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Get_groups_list_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Chat_with_friend_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Chat_with_group_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Get_friend_chat_history_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

    static void
    Get_group_chat_history_Request(
            struct event_base *base,
            struct bufferevent *bev,
            Json::Value val,
            void *ctx

    );

public:

    Chat_Server();

    ~Chat_Server();
};
