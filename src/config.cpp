#include "config.h"
#include <fstream>
#include <string>
#include <qdir.h>
#include <iostream>


#define PATH QDir::currentPath().toStdString()

using namespace std;

Config::Config() {
}

//https://stackoverflow.com/questions/31103883/reading-key-value-pairs-from-a-file-and-ignoring-comment-lines

void Config::loadConfig() {
        const string CONF_P = PATH + "/config.properties";
        ifstream configFile;

         configFile.open(CONF_P);

        if(!configFile) {
            cerr << "Unable to open " << CONF_P << " creating new file now.";
            ofstream configFile(CONF_P);
            configFile << "";
        }

        string line;

        std::string pairs[2];
        while(std::getline(configFile, line)) {

        }
}

std::string Config::get(std::string k) {
    if(map.empty()) loadConfig();

    return map[k];
}
