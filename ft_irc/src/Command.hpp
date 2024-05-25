#pragma once
#include <map>
#include <string>
#include <vector>

template<typename T>
class Command {
public:
    typedef void (T::*CommandPtr)(int, std::vector<std::string>);
    std::map<std::string, CommandPtr> commandMap;

    Command();

    void exec(std::vector<std::string> cmd, T* instance, int fd);
	std::string toLower(const std::string& str);
};

#include "Command.tpp"