#include "Map_Database_Logical_To_Group_Relate.h"

Map_Database_Logical_To_Group_Relate::Map_Database_Logical_To_Group_Relate() {

    this->data_con_obj = new database_Service_Layer();
    this->data_con_obj->set_Database_Name(MysqlInfo::database_name.c_str());
    this->data_con_obj->set_Host_And_Port(MysqlInfo::host.c_str(), MysqlInfo::port);
    this->data_con_obj->set_User_And_Password(MysqlInfo::user.c_str(), MysqlInfo::password.c_str());
    this->data_con_obj->init_database();

    this->data_con_obj->connect();

    all_Group_Set = new set<Map_Database_Group>;

    vector<int> group_user_id_vector;
    int group_num = this->data_con_obj->get_All_Group_Chat_group_id(group_user_id_vector);

    for (int i = 0; i < group_num; i++) {

        Map_Database_Group g;
        g.set_group_id(group_user_id_vector[i]);
        g.set_Map_Database_Group_User_Set(new set<Map_Database_Group_User>);
        all_Group_Set->insert(g);

        vector<int> group_member_user_id_vector;
        this->data_con_obj->get_All_Group_Member_id_From_One_Group(g.get_group_id(), group_member_user_id_vector);

        if (group_member_user_id_vector.size() == 0)
            continue;
        for (int i = 0; i < group_member_user_id_vector.size(); i++) {
            Map_Database_Group_User groupUser;
            groupUser.set_user_id(group_member_user_id_vector[i]);
            g.get_Map_Database_Group_User_Set()->insert(groupUser);
        }
    }

    this->data_con_obj->disconnect();

}

Map_Database_Logical_To_Group_Relate::~Map_Database_Logical_To_Group_Relate() {
}

set<Map_Database_Group> *Map_Database_Logical_To_Group_Relate::get_All_Group_Set() {
    std::shared_lock<std::shared_mutex> lock(mutex_All_Group_Set);
    return all_Group_Set;
};

void Map_Database_Logical_To_Group_Relate::set_All_Group_Set(set<Map_Database_Group> *) {
    std::unique_lock<std::shared_mutex> lock(mutex_All_Group_Set);
    this->all_Group_Set = all_Group_Set;
};

bool Map_Database_Logical_To_Group_Relate::groupA_In_All_Group_Set(int group_id) {
    std::shared_lock<std::shared_mutex> lock(mutex_All_Group_Set);
    for (set<Map_Database_Group>::iterator it = all_Group_Set->begin(); it != all_Group_Set->end(); it++) {
        if (it->get_group_id() == group_id) {
            return true;
        }
    }
    return false;
};

void Map_Database_Logical_To_Group_Relate::groupA_Join_All_Group_Set(int user_id, int group_id) {
    std::unique_lock<std::shared_mutex> lock(mutex_All_Group_Set);

    Map_Database_Group g;
    g.set_group_id(group_id);
    g.set_Map_Database_Group_User_Set(new set<Map_Database_Group_User>);

    all_Group_Set->insert(g);

    Map_Database_Group_User u;
    u.set_user_id(user_id);
    g.get_Map_Database_Group_User_Set()->insert(u);
};

void Map_Database_Logical_To_Group_Relate::groupA_Delete_From_All_Group_Set(string userName) {

};

void Map_Database_Logical_To_Group_Relate::get_The_Members_Of_GroupA_Of_All_Group_Set(vector<string> &) {

};

bool Map_Database_Logical_To_Group_Relate::userA_In_GroupA_Of_All_Group_Set(int user_id, int group_id) {
    std::shared_lock<std::shared_mutex> lock(mutex_All_Group_Set);
    for (set<Map_Database_Group>::iterator it = all_Group_Set->begin(); it != all_Group_Set->end(); it++) {
        if (it->get_group_id() == group_id) {

            for (set<Map_Database_Group_User>::iterator i = it->get_Map_Database_Group_User_Set()->begin();
                 i != it->get_Map_Database_Group_User_Set()->end(); i++) {
                if (i->get_user_id() == user_id) {
                    return true;
                }
            }
        }
    }
    return false;
};

bool Map_Database_Logical_To_Group_Relate::userA_Join_GroupA_Of_All_Group_Set(int user_id, int group_id) {
    std::unique_lock<std::shared_mutex> lock(mutex_All_Group_Set);
    for (set<Map_Database_Group>::iterator it = all_Group_Set->begin(); it != all_Group_Set->end(); it++) {
        if (it->get_group_id() == group_id) {


            Map_Database_Group_User u;
            u.set_user_id(user_id);
            it->get_Map_Database_Group_User_Set()->insert(u);

            return true;
        }
    }
    return false;
}