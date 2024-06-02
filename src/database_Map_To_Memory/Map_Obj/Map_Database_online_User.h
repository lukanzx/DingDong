#pragma once

#include <event2/bufferevent.h>
#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Map_Database_online_User {
private:

    int user_id = 0;

    struct bufferevent *bev = nullptr;

public:

    Map_Database_online_User();

    ~Map_Database_online_User();

public:

    Map_Database_online_User(int user_id, struct bufferevent *bev);

    int get_user_id() const;

    void set_user_id(const int &);

    struct bufferevent *getBev() const;

    void setBev(struct bufferevent *bev);

    bool operator==(const Map_Database_online_User &other) const;

    bool operator<(const Map_Database_online_User &other) const;

    bool operator>(const Map_Database_online_User &other) const;
};
