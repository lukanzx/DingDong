#pragma once

#include "Map_Database_online_User.h"
#include <iostream>
#include <mutex>
#include <event2/bufferevent.h>
#include <string.h>
#include <set>
#include <shared_mutex>

#include "config.h"
#include "database_Service_Layer.h"

using std::cout;
using std::endl;
using std::set;
using std::shared_mutex;
using std::string;

class Server;

class database_Service_Layer;

class Map_Database_Logical_To_Online_User {
    friend class Server;

private:

    database_Service_Layer *data_con_obj = nullptr;

    set<Map_Database_online_User> *online_User_Set;

    shared_mutex mutex_Online_User_Set;

public:
    Map_Database_Logical_To_Online_User();

    ~Map_Database_Logical_To_Online_User();

public:

    bool add_Online_User_To_online_User_Set(int user_id, struct bufferevent *bev);

    set<Map_Database_online_User> *get_Online_User_Set();

    void set_Online_User_Set(set<Map_Database_online_User> *);

    bool delete_Online_User_From_online_User_Set(int);

    struct bufferevent *get_UserAccount_Bev_From_Online_User_Set(int);

    void set_UserAccount_Bev_To_Online_User_Set(int, struct bufferevent *);

};
