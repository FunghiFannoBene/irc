/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KICK.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:29:06 by teo               #+#    #+#             */
/*   Updated: 2024/05/23 14:59:46 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Channel.hpp"
#include "../Server.hpp"

void Channel::parseKickCommand(Client *client, std::vector<std::string> cmd)
{
    std::string reason;
    Client *kicked = getClientbyName(cmd[2]);
    if(!kicked)
    {
        ERR_USERNOTINCHANNEL(client, cmd[2], cmd[1]);
        return;
    }
    for(size_t i = 3; i < cmd.size(); i++)
        reason += cmd[i] + " ";
    std::string msg = RPL_KICKCHANNEL(client, cmd[1], cmd[2], reason);
    sendToChannel(msg);
    remAdmins(kicked->getFd());
    remClients(kicked->getFd());
	remInvited(kicked->getFd());
}


void Server::KICK(int fd, std::vector<std::string> cmd)
{
	Client *cli = getClient(fd);
    Channel *channel = getChannel(cmd[1]);
    if(cmd.size() < 3)
	{
		ERR_NEEDMOREPARAMS(cli, "KICK");
		return;
	}
	if(!channel)
	{
		ERR_NOSUCHCHANNEL(cli, cmd[1]);
		return;
	}
    if(!channel->getClient(fd))
	{	
		ERR_NOTONCHANNEL(cli, cmd[1]);
		return;
    }
	if(channel->getClientInChannel(fd) != channel->getAdmins(fd))
	{
		ERR_CHANOPRIVSNEEDED(cli, cmd[1]);
		return;
	}
	channel->parseKickCommand(cli, cmd);
		
}	
