#pragma once

#include <jsoncpp/json/json.h>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Group_member_table;

class Group_message_history_table;

class Group_table;

class Friend_message_history_table;

class Friend_table;

class User_table;

class database_Service_Layer {

public:

    database_Service_Layer();

    bool create_Database();

    ~database_Service_Layer();

    bool connect();

    bool disconnect();

    bool is_Connected();

    void set_Database_Name(const char *database_name);

    void set_Host_And_Port(const char *host, unsigned int port);

    void set_User_And_Password(const char *user, const char *password);

    void init_database();

    bool create_A_New_Account_Of_User(int, string, string);

    Json::Value get_Account_Of_User_Information(int);

    bool account_Of_User_Is_Exist(int);

    bool verify_Account_Of_User_password_Is_True(int, string);

    bool accountA_And_AccountB_Is_Friend(int, int);

    Json::Value get_All_Friens_Of_One_Account(int);

    bool accountA_Adds_AccountB_As_Friend(int, int);

    bool insert_Friend_Messages(int, int, string, string, string);

    Json::Value get_Friends_Messages(int, int);

    bool delete_Rows_With_TargetId(int &);

    int get_All_Group_Chat_group_id(vector<int> &);

    int get_All_Group_Chat_group_name(vector<string> &);

    bool group_Is_Exist_by_group_id(int);

    bool group_Is_Exist_by_group_name(string);

    bool create_A_New_Group(string, int);

    Json::Value get_All_Groups_Of_One_Account(int);

    bool insert_Group_Messages(int, int, string, string, string);

    Json::Value get_Groups_Messages(int, int);

    bool user_Join_A_Group(int, int);

    int get_All_Group_Member_id_From_One_Group(int, vector<int> &);

private:

    Group_member_table *group_member_table = nullptr;
    Group_message_history_table *group_message_history_table = nullptr;
    Group_table *group_table = nullptr;
    Friend_message_history_table *friend_message_history_table = nullptr;
    Friend_table *friend_table = nullptr;
    User_table *user_table = nullptr;

    const char *database_name = nullptr;
    const char *host = nullptr;
    const char *user = nullptr;
    const char *password = nullptr;
    unsigned int port = 0;
    bool is_connected = false;
    bool is_created_database = false;

};
