#include "Global.h"

int generate_Random_Number() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(600001, 999999);

    return dist(gen);
}

bool readConfig(YAML::Node config) {

    ServerInfo::ip = config["server"]["ip"].as<std::string>();
    ServerInfo::port = config["server"]["port"].as<int>();

    MysqlInfo::host = config["mysql"]["host"].as<std::string>();
    MysqlInfo::port = config["mysql"]["port"].as<int>();
    MysqlInfo::database_name = config["mysql"]["database_name"].as<std::string>();
    MysqlInfo::user = config["mysql"]["user"].as<std::string>();
    MysqlInfo::password = config["mysql"]["password"].as<std::string>();

    return true;
}
