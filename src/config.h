#ifndef CONFIG_H
#define CONFIG_H

#include <map>

class Config
{
public:
    Config();
    std::string get(std::string k);
private:
     void loadConfig();
     std::map<std::string, std::string> map;
};

#endif // CONFIG_H
