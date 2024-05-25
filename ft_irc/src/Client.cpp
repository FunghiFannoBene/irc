/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:57:54 by mneri             #+#    #+#             */
/*   Updated: 2024/05/16 15:22:37 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client() : logged(false) , nicked(false), usered(false) ,registered(false)
{
	_IPaddr.clear();
	_username.clear();
	_nickname = "*";
	_buff.clear();
}

Client::~Client(){}


int Client::getFd()
{
	return _fd;
}

void Client::setUsername(std::string username)
{
	_username = username;
}
void Client::setNick(std::string nickname)
{
	_nickname = nickname;
}
void Client::setBuff(std::string buff)
{
	_buff = buff;
}

void Client::setFd(int fd)
{
	_fd = fd;
}

void Client::setIPaddr(std::string ipadd)
{
	_IPaddr = ipadd;
}

void Client::setLogged(bool bool_)
{
	logged = bool_;
}

bool Client::getLogged()
{
	return logged;
}

void Client::setRegistered(bool bool_)
{
	registered = bool_;
}

bool Client::getUsered()
{
	return usered;
}

void Client::setUsered(bool bool_)
{
	usered = bool_;
}

bool Client::getNicked()
{
	return nicked;
}

void Client::setNicked(bool bool_)
{
	nicked = bool_;
}


std::string Client::getNick()
{
	return _nickname;
}

std::string Client::getUser()
{
	return _username;
}

void Client::setUser(std::string user)
{
	_username = user;
}

std::string Client::getRealname()
{
	return _realname;
}

void Client::setRealname(std::string realname)
{
	_realname = realname;
}

std::string Client::getIPaddr()
{
	return _IPaddr;
}

bool Client::getRegistered()
{
	return registered;
}
