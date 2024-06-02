#include "Map_Database_Group.h"

Map_Database_Group::Map_Database_Group() {

}

Map_Database_Group::~Map_Database_Group() {
    if (Map_Database_Group_User_Set != nullptr) {
        delete Map_Database_Group_User_Set;
    }
}

void Map_Database_Group::set_group_id(int group_id) {
    this->group_id = group_id;
};

int Map_Database_Group::get_group_id() const {
    return group_id;
};

set<Map_Database_Group_User> *Map_Database_Group::get_Map_Database_Group_User_Set() const {
    return Map_Database_Group_User_Set;
};

void Map_Database_Group::set_Map_Database_Group_User_Set(set<Map_Database_Group_User> *Map_Database_Group_User_Set) {
    this->Map_Database_Group_User_Set = Map_Database_Group_User_Set;
};

bool Map_Database_Group::operator==(const Map_Database_Group &other) const {
    return group_id == other.group_id;
}

bool Map_Database_Group::operator<(const Map_Database_Group &other) const {
    return group_id < other.group_id;
}

bool Map_Database_Group::operator>(const Map_Database_Group &other) const {
    return group_id > other.group_id;
}
