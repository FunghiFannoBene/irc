#pragma once
#include <map>
#include <string>
#include <vector>

template<typename T>
class Command
{
	private:
		typedef void (T::*CommandPtr)(int, std::vector<std::string>);
		std::map<std::string, CommandPtr> commandMap;
		std::string lowerCaseCommand;

	public:
		Command();
		void exec(std::vector<std::string> cmd, T* instance, int fd, bool registered);
		std::string toLower(const std::string& str);
		~Command();
};

#include "Command.tpp"