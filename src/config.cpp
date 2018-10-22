#include "config.h"
#include <fstream>
#include <string>
#include <qdir.h>
#include <iostream>
#include <sstream>
#include <map>

#define PATH QDir::currentPath().toStdString()

/* DISCLAIMER
 *
 * I wasn't allowed to make any globals so this was my workaround sorry Chris
 *
 *
*/

using namespace std;

Config::Config() {
    loadConfig();
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
        while(getline(configFile, line)) {
            istringstream iss(line);
            string token, currentKey;
            int n = 0;
            while(getline(iss, token, '=')) {
                  if(!n++)
                      currentKey = token;

                  else
                      map[currentKey] = token;
            } n--;
        }
}

void Config::iterate() {
    std::cout << "iterating" << std::endl;
    for(std::map<string, string>::iterator it=map.begin(); it!=map.end();++it)
        cout<< it->first << "=>" << it->second << endl;
}

std::string Config::get(string k) {
    if(!map.empty()) {
        return map[k];
    } else
        return "null";
}
