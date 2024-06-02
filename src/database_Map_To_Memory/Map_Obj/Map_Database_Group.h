#pragma once

#include <iostream>
#include <string.h>
#include "Map_Database_Group_User.h"
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

class Map_Database_Group {
private:

    int group_id;

    set<Map_Database_Group_User> *Map_Database_Group_User_Set;

public:

    Map_Database_Group();

    ~Map_Database_Group();

public:
    void set_group_id(int);

    int get_group_id() const;

    set<Map_Database_Group_User> *get_Map_Database_Group_User_Set() const;

    void set_Map_Database_Group_User_Set(set<Map_Database_Group_User> *);

    bool operator==(const Map_Database_Group &other) const;

    bool operator<(const Map_Database_Group &other) const;

    bool operator>(const Map_Database_Group &other) const;
};
