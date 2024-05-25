/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PRIVMSG.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:27:28 by mneri             #+#    #+#             */
/*   Updated: 2024/05/23 18:22:16 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server.hpp"
#include "../Channel.hpp"

void Server::parseMsgCommand(Client *client, std::vector<std::string> cmd, Channel *channel, Client *recipient)
{
	std::string msg = "";
	std::string finalmsg = "";
	for(size_t arg = 2; arg < cmd.size(); arg++)
	{
		msg += cmd[arg] + " ";
	}
	if(recipient)
	{
		finalmsg = RPL_MSG(client, recipient->getNick(), msg);
		sendMsg(recipient, finalmsg);
	}
	else
	{
		finalmsg = RPL_MSG(client, channel->getName(), msg);
		channel->sendToChannel(finalmsg);
	}
}

void Server::PRIVMSG(int fd, std::vector<std::string> cmd)
{
	Client *cli = getClient(fd);
    if(cmd.size() < 2)
	{
		ERR_NORECIPIENT(cli);
		return;
	}
	Channel *channel = getChannel(cmd[1]);
	Client *recipient = getClientbyName(cmd[1]);
	if(!channel && !recipient)
	{
		ERR_NOSUCHNICK(cli, cmd[1]);
		return;
	}
    if(cmd.size() == 2 || cmd[2].empty())
	{	
		ERR_NOTEXTOSEND(cli);
		return;
    }
	parseMsgCommand(cli, cmd, channel, recipient);
		
}	
