#include "Map_Database_online_User.h"

Map_Database_online_User::Map_Database_online_User() {
}

Map_Database_online_User::Map_Database_online_User(int user_id, struct bufferevent *bev) {
    this->user_id = user_id;
    this->bev = bev;
}

Map_Database_online_User::~Map_Database_online_User() {
}

int Map_Database_online_User::get_user_id() const {
    return user_id;
}

void Map_Database_online_User::set_user_id(const int &user_id) {
    this->user_id = user_id;
}

struct bufferevent *Map_Database_online_User::getBev() const {
    return bev;
}

void Map_Database_online_User::setBev(struct bufferevent *bev) {
    this->bev = bev;
}

bool Map_Database_online_User::operator==(const Map_Database_online_User &other) const {
    return user_id == other.user_id;
}

bool Map_Database_online_User::operator<(const Map_Database_online_User &other) const {
    return user_id < other.user_id;
}

bool Map_Database_online_User::operator>(const Map_Database_online_User &other) const {
    return user_id > other.user_id;
}

