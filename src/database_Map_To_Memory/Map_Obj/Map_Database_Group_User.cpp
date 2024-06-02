#include "Map_Database_Group_User.h"

Map_Database_Group_User::Map_Database_Group_User() {

}

Map_Database_Group_User::~Map_Database_Group_User() {

}

int Map_Database_Group_User::get_user_id() const {
    return user_id;
}

void Map_Database_Group_User::set_user_id(int user_id) {
    this->user_id = user_id;
}

bool Map_Database_Group_User::operator==(const Map_Database_Group_User &other) const {
    return user_id == other.user_id;
}

bool Map_Database_Group_User::operator<(const Map_Database_Group_User &other) const {
    return user_id < other.user_id;
}

bool Map_Database_Group_User::operator>(const Map_Database_Group_User &other) const {
    return user_id > other.user_id;
}