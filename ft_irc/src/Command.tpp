#include "Command.hpp"
#include "Server.hpp"

template<typename T>
Command<T>::Command() {
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
void Command<T>::exec(std::vector<std::string> cmd, T* instance, int fd) {
    try {
        CommandPtr func = commandMap.at(cmd[0]);
        (instance->*func)(fd, cmd);
    } catch (const std::out_of_range&)
	{
        ERR_NOTREGISTERED(instance->getClient(fd));
    }
}