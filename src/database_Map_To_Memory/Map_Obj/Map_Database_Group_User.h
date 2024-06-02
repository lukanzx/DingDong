#pragma once

#include <iostream>
#include <string.h>
#include <event2/bufferevent.h>

using std::cout;
using std::endl;
using std::string;

class Map_Database_Group_User {
private:
    int user_id;

public:

    Map_Database_Group_User();

    ~Map_Database_Group_User();

public:
    int get_user_id() const;

    void set_user_id(int);

    bool operator==(const Map_Database_Group_User &other) const;

    bool operator<(const Map_Database_Group_User &other) const;

    bool operator>(const Map_Database_Group_User &other) const;
};
