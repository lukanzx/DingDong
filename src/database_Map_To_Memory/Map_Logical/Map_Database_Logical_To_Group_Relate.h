#pragma once

#include <iostream>
#include <mutex>
#include <event2/bufferevent.h>
#include <string.h>
#include <set>
#include <shared_mutex>

#include "config.h"
#include "database_Service_Layer.h"
#include "Map_Database_Group_User.h"
#include "Map_Database_Group.h"

using std::cout;
using std::endl;
using std::set;
using std::shared_mutex;
using std::string;

class Server;

class database_Service_Layer;

class Map_Database_Logical_To_Group_Relate {
    friend class Server;

private:

    database_Service_Layer *data_con_obj = nullptr;

    Map_Database_Group_User *map_database_group_user_obj = new Map_Database_Group_User();
    Map_Database_Group *map_database_group = new Map_Database_Group();

    set<Map_Database_Group> *all_Group_Set;

    std::shared_mutex mutex_All_Group_Set;

public:
    Map_Database_Logical_To_Group_Relate();

    ~Map_Database_Logical_To_Group_Relate();

public:
    set<Map_Database_Group> *get_All_Group_Set();

    void set_All_Group_Set(set<Map_Database_Group> *);

    bool groupA_In_All_Group_Set(int);

    void groupA_Join_All_Group_Set(int, int);

    void groupA_Delete_From_All_Group_Set(string userName);

    void get_The_Members_Of_GroupA_Of_All_Group_Set(vector<string> &);

    bool userA_In_GroupA_Of_All_Group_Set(int, int);

    bool userA_Join_GroupA_Of_All_Group_Set(int, int);
};
