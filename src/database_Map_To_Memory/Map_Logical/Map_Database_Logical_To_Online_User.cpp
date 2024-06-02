#include "Map_Database_Logical_To_Online_User.h"

Map_Database_Logical_To_Online_User::Map_Database_Logical_To_Online_User() {

    this->data_con_obj = new database_Service_Layer();
    this->data_con_obj->set_Database_Name(MysqlInfo::database_name.c_str());
    this->data_con_obj->set_Host_And_Port(MysqlInfo::host.c_str(), MysqlInfo::port);
    this->data_con_obj->set_User_And_Password(MysqlInfo::user.c_str(), MysqlInfo::password.c_str());
    this->data_con_obj->init_database();
    this->online_User_Set = new set<Map_Database_online_User>;

}

Map_Database_Logical_To_Online_User::~Map_Database_Logical_To_Online_User() {
    delete data_con_obj;
    delete online_User_Set;
}

set<Map_Database_online_User> *Map_Database_Logical_To_Online_User::get_Online_User_Set() {
    return online_User_Set;
}

void Map_Database_Logical_To_Online_User::set_Online_User_Set(
        set<Map_Database_online_User> *online_User_Set

) {
    this->online_User_Set = online_User_Set;
}

bool Map_Database_Logical_To_Online_User::add_Online_User_To_online_User_Set(int user_id, struct bufferevent *bev) {
    std::unique_lock<std::shared_mutex> lock(mutex_Online_User_Set);

    Map_Database_online_User u;
    u.set_user_id(user_id);
    auto it = online_User_Set->find(u);


    if (it == online_User_Set->end()) {
        u.setBev(bev);
        online_User_Set->insert(u);
        return true;
    } else {
        return true;
    }
}

bool Map_Database_Logical_To_Online_User::delete_Online_User_From_online_User_Set(int user_id) {
    std::unique_lock<std::shared_mutex> lock(mutex_Online_User_Set);
    Map_Database_online_User u;
    u.set_user_id(user_id);
    auto it = online_User_Set->find(u);
    if (it != online_User_Set->end()) {
        online_User_Set->erase(it);
    }
    return true;
}

struct bufferevent *
Map_Database_Logical_To_Online_User::get_UserAccount_Bev_From_Online_User_Set(int user_id) {
    std::shared_lock<std::shared_mutex> lock(mutex_Online_User_Set);
    Map_Database_online_User u;
    u.set_user_id(user_id);
    auto it = online_User_Set->find(u);
    if (it != online_User_Set->end()) {
        return it->getBev();
    }
    return NULL;
}

void Map_Database_Logical_To_Online_User::set_UserAccount_Bev_To_Online_User_Set(
        int user_id,
        struct bufferevent *bev

) {
    std::unique_lock<std::shared_mutex> lock(mutex_Online_User_Set);
    Map_Database_online_User u = Map_Database_online_User();
    u.set_user_id(user_id);
    u.setBev(bev);
    online_User_Set->insert(u);
}