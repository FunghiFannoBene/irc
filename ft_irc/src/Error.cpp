/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:28:37 by mneri             #+#    #+#             */
/*   Updated: 2024/05/23 17:53:45 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"


void sendMsg(Client *client, std::string msg)
{
	send(client->getFd(), msg.c_str(), msg.size(), 0);
	std::cout << msg;
}



// ERROR //
void ERR_ALREADYREGISTERED(Client *client){std::string str =  std::string(RED) +  "ERR_ALREADYREGISTEstd::string(RED)(462) " + "<" + client->getNick() + ">" + ":You may not reregister\n" + WHITE; sendMsg(client, str);}
void ERR_NEEDMOREPARAMS(Client *client, std::string cmd){std::string str =  std::string(RED) + "ERR_NEEDMOREPARAMS(461) " + "<" + client->getNick() + "> " + cmd + ":Not enough parameters\n" + WHITE; sendMsg(client, str);}
void ERR_PASSWDMISMATCH(Client *client){std::string str =  std::string(RED) + "ERR_PASSWDMISMATCH (464) ) " + "<" + client->getNick() + "> " + ":Password incorrect\n" + WHITE; sendMsg(client, str);}
void ERR_ERRONEUSNICKNAME(Client *client, std::string nick){std::string str =  std::string(RED) + "ERR_ERRONEUSNICKNAME (432) " + "<" + client->getNick() + "> " + nick + ":Erroneus nickname\n" + WHITE; sendMsg(client, str);}
void ERR_NONICKNAMEGIVEN(Client *client){std::string str =  std::string(RED) + " ERR_NONICKNAMEGIVEN (431) " + "<" + client->getNick() + "> " + ":No nickname given\n" + WHITE; sendMsg(client, str);}
void ERR_NICKNAMEINUSE(Client *client, std::string nick){std::string str =  std::string(RED) + " ERR_NICKNAMEINUSE (433) " + "<" + client->getNick() + "> " + nick + ":Nickname is already in use\n" + WHITE; sendMsg(client, str);}
void ERR_NOTREGISTERED(Client *client){std::string str =  std::string(RED) + " ERR_NOTREGISTERED (451) " + "<" + client->getNick() + "> " + ":You have not registered\n" + WHITE; sendMsg(client, str);}
void ERR_NOSUCHCHANNEL(Client *client, std::string channel){std::string str = std::string(RED) + "ERR_NOSUCHCHANNEL (403) " + "<" + client->getNick() + "> " + channel + ":No such channel\n" + WHITE; sendMsg(client, str);}
void ERR_TOOMANYCHANNELS(Client *client, std::string channel){std::string str =  std::string(RED) + "ERR_TOOMANYCHANNELS (405) " + "<" + client->getNick() + "> " + channel + ":You have joined too many channels\n" + WHITE; sendMsg(client, str);}
void ERR_BADCHANNELKEY(Client *client, std::string channel){std::string str = std::string(RED) + "ERR_BADCHANNELKEY (475) " + "<" + client->getNick() + "> " + channel + " :Cannot join channel (+k)\n" + WHITE; sendMsg(client, str);}
void ERR_ALREADYJOIN(Client *client, std::string channelname){std::string str = std::string(RED) + client->getNick() + " already joined " + channelname + "\n" + WHITE; sendMsg(client, str);}
void ERR_INVITEONLYCHAN(Client *client, std::string channelname){std::string str = std::string(RED) + "ERR_INVITEONLYCHAN (473) " + "<" + client->getNick() + "> " + channelname + " :Cannot join channel (+i)\n" + WHITE; sendMsg(client, str);}
void ERR_CHANOPRIVSNEEDED(Client *client, std::string channel){std::string str = std::string(RED) + "ERR_CHANOPRIVSNEEDED (482) " + "<" + client->getNick() + "> " + channel + " :You're not channel operator\n" + WHITE; sendMsg(client, str);}
void ERR_INVALIDMODEPARAM(Client *client, std::string channel, std::string param){std::string str = std::string(RED) + "ERR_INVALIDMODEPARAM (696) " + "<" + client->getNick() + "> " + channel + " :Missing parameter for MODE (" + param + ") \n" + WHITE; sendMsg(client, str);}
void ERR_UNKNOWNMODE(Client *client){std::string str = std::string(RED) + "ERR_UNKNOWNMODE (472) " + "<" + client->getNick() + "> " + " :Unkwown mode char\n" + WHITE; sendMsg(client, str);}
void ERR_USERNOTINCHANNEL(Client *client, std::string nick, std::string channel){std::string str = std::string(RED) + "ERR_USERNOTINCHANNEL (441) " + "<" + client->getNick() + "> " + nick + " " + channel + " :They aren't on that channel\n" + WHITE; sendMsg(client, str);}
void ERR_NOTONCHANNEL(Client *client, std::string channel){std::string str = std::string(RED) + "ERR_USERNOTINCHANNEL (441) " + "<" + client->getNick() + "> " + channel + " :You're not on that channel\n" + WHITE; sendMsg(client, str);}
void ERR_USERONCHANNEL(Client *client, std::string nick, std::string channel){std::string str = std::string(RED) + "ERR_USERONCHANNEL (443) " + "<" + client->getNick() + "> " + nick + " " + channel + " :is already on channel\n" + WHITE; sendMsg(client, str);}
void ERR_NORECIPIENT(Client *client){std::string str = std::string(RED) + "ERR_NORECIPIENT (411) " + "<" + client->getNick() + "> " + ": No recipient given\n" + WHITE; sendMsg(client, str);}
void ERR_NOSUCHNICK(Client *client, std::string nick){std::string str = std::string(RED) + "ERR_NOSUCHNICK (401) " + "<" + client->getNick() + "> " + nick + ": No such nick/channel\n" + WHITE; sendMsg(client, str);}
void ERR_NOTEXTOSEND(Client *client){std::string str = std::string(RED) + "ERR_NOSUCHNICK (401) " + "<" + client->getNick() + "> " + ": No text to send\n" + WHITE; sendMsg(client, str);}

//REPLIES// 

void RPL_WELCOME(Client *client){std::string str = "<" + client->getNick() + "> Welcome to the IRC server!\n"; sendMsg(client, str);}
void RPL_CHANNELMODEIS(Client *client, std::string channel, std::string modestring){std::string str = "RPL_CHANNELMODEIS (324) <" + client->getNick() + "> " + channel + " " + modestring + "\n"; sendMsg(client, str);}
void RPL_TOPIC(Client *client, std::string channel, std::string topic){std::string str = "RPL_TOPIC (332) <" + client->getNick() + "> " + channel + " :" + topic + "\n"; sendMsg(client, str);}
// CHANNEL ERRORS // 
std::string RPL_JOINCHANNEL(Client *client, std::string channelname){return client->getNick() + ":" + client->getUser() + "@" + client->getIPaddr() + " JOIN " + channelname + "\n";}
std::string RPL_KICKCHANNEL(Client *client, std::string channelname, std::string kicked, std::string reason){return client->getNick() + ":" + client->getUser() + "@" + client->getIPaddr() + " KICK " + channelname + " " + kicked +  ":" + reason +"\n";}
std::string RPL_INVITING(Client *client, std::string invited, std::string channel){return client->getNick() + ":" + client->getUser() + "@" + client->getIPaddr() + " INVITE " + invited + " " + channel + "\n";}
std::string RPL_PART(Client *client, std::string channel, std::string reason){return client->getNick() + ":" + client->getUser() + "@" + client->getIPaddr() + " PART " + channel + " :" + reason + "\n";}
std::string RPL_QUIT(Client *client, std::string reason){return client->getNick() + ":" + client->getUser() + "@" + client->getIPaddr() + " QUIT :" + reason + "\n";}
std::string RPL_MSG(Client *client, std::string recipient, std::string msg){return client->getNick() + ":" + client->getUser() + "@" + client->getIPaddr() + " PRIVMSG :" + recipient + " " + msg + "\n";}
