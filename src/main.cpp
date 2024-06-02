#include "Chat_Server.h"
#include <yaml-cpp/yaml.h>
#include "Global.h"

int main() {
    YAML::Node config;
    try {
        config = YAML::LoadFile("../config/config.yaml");
        readConfig(config);
    } catch (const YAML::BadFile &e) {
        std::cerr << "Unable to find config.yaml: " << e.what() << std::endl;
        return 0;
    }

    Chat_Server *c = new Chat_Server();
    
    return 0;
}
