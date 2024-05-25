/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INVITE.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:51:38 by mneri             #+#    #+#             */
/*   Updated: 2024/05/23 15:00:46 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Channel.hpp"
#include "../Server.hpp"

void Server::parseInviteCommand(Client *client, std::vector<std::string> cmd, Channel *channel)
{
	Client *inv = getClientbyName(cmd[1]);
	std::string msg;
	if(!inv)
		return;
	if(channel->getInvonly() == true && channel->getAdmins(client->getFd())->getNick() != client->getNick())
	{
		ERR_CHANOPRIVSNEEDED(client, cmd[2]);
		return;
	}
    if(channel->getClientbyName(cmd[1]))
    {
        ERR_USERONCHANNEL(client, cmd[1], cmd[2]);
        return;
    }
	channel->addInvited(inv);
	msg = RPL_INVITING(client, cmd[1], cmd[2]);
	channel->sendToChannel(msg);
}


void Server::INVITE(int fd, std::vector<std::string> cmd)
{
	
	Client *cli = getClient(fd);
	if(cmd.size() < 3)
	{
		ERR_NEEDMOREPARAMS(cli, "INVITE");
		return;
	}
    Channel *channel = getChannel(cmd[2]);
	if(!channel)
	{
		ERR_NOSUCHCHANNEL(cli, cmd[2]);
		return;
	}
    if(!channel->getClient(fd))
	{	
		ERR_NOTONCHANNEL(cli, cmd[2]);
		return;
    }
	parseInviteCommand(cli, cmd, channel);
		
}	
