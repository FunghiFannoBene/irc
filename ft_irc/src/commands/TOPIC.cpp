/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOPIC.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:48:41 by mneri             #+#    #+#             */
/*   Updated: 2024/05/22 18:20:06 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Channel.hpp"
#include "../Server.hpp"

void Channel::parseTopicCommand(Client *client, std::vector<std::string> cmd)
{
	if(cmd.size() == 2)
	{
		RPL_TOPIC(client, cmd[1], _topic);
		return;
	}
	else
	{
		if(cmd[2] == ":" && cmd.size() == 3)
			_topic.clear();
		else
		{
			std::string msg;
			for(size_t arg = 2; arg < cmd.size(); arg++)
				msg += cmd[arg] + " ";
			setTopic(msg);
		}
	}
}


void Server::TOPIC(int fd, std::vector<std::string> cmd)
{
	Client *cli = getClient(fd);
    Channel *channel = getChannel(cmd[1]);
    if(cmd.size() < 2)
	{
		ERR_NEEDMOREPARAMS(cli, "TOPIC");
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
	channel->parseTopicCommand(cli, cmd);
		
}	
