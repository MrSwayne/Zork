#ifndef CONFIG_H
#define CONFIG_H

#include <map>

class Config
{
public:
    static Config& getInstance();
    std::string get(std::string k);
    void set(std::string k, std::string v);

private:
     Config();
     void iterate();
     std::map<std::string, std::string> map;
};

#endif // CONFIG_H
