#pragma once

#include <iostream>
#include <random>
#include <string>
#include <yaml-cpp/yaml.h>

using std::string;

class ServerInfo {
public:
    static string ip;
    static int port;
};

class MysqlInfo {
public:
    static string host;
    static int port;
    static string database_name;
    static string user;
    static string password;
};
