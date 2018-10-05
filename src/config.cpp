#include "config.h"
#include <fstream>
#include <string>
#include <qdir.h>
#include <iostream>

#define PATH QDir::currentPath().toStdString()

using namespace std;

Config::Config() {
}


void Config::loadConfig() {
        ifstream configFile;

         configFile.open(PATH + "/config.properties");

        if(!configFile) {
            cerr << "Unable to open " + PATH + "/config.properties";
            exit(-1);
        }

        string line;
        while(std::getline(configFile, line)) {
            std::cout << line << std::endl;
        }
}

std::string Config::get(std::string k) {
    if(map.empty()) loadConfig();

    return map[k];
}
