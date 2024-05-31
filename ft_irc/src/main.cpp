/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:36 by mneri             #+#    #+#             */
/*   Updated: 2024/05/28 22:47:49 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Client.hpp"
#include "Utils.hpp"

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		Server ser = Server(checkPort(std::atoi(argv[1])), argv[2]);
	}
}