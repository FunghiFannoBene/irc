#include "Command.hpp"
#include "Server.hpp"
#include <algorithm>

template<typename T>
Command<T>::Command()
{
    commandMap["pass"] = &T::PASS;
    commandMap["nick"] = &T::NICK;
    commandMap["user"] = &T::USER;
    commandMap["join"] = &T::JOIN;
    commandMap["mode"] = &T::MODE;
    commandMap["kick"] = &T::KICK;
    commandMap["part"] = &T::PART;
    commandMap["privmsg"] = &T::PRIVMSG;
    commandMap["quit"] = &T::QUIT;
    commandMap["topic"] = &T::TOPIC;
}

template<typename T>
void Command<T>::exec(std::vector<std::string> cmd, T* instance, int fd, bool registered)
{
	lowerCaseCommand = toLower(cmd[0]);
	if(registered || (!registered && (lowerCaseCommand == "pass" || lowerCaseCommand == "nick" || lowerCaseCommand == "user")))
	{
		CommandPtr func = commandMap.at(lowerCaseCommand);
			(instance->*func)(fd, cmd);
	}
	else
		ERR_NOTREGISTERED(instance->getClient(fd));
}

template<typename T>
std::string Command<T>::toLower(const std::string& str)
{
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), static_cast<int(*)(int)>(std::tolower));
    return lowerStr;
}


template<typename T>
Command<T>::~Command()
{
}