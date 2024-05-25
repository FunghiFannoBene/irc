/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:41:37 by mneri             #+#    #+#             */
/*   Updated: 2024/05/26 00:22:28 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

int checkPort(char *port)
{
	if(std::atoi(port) >= 1024 && std::atoi(port) <= 65535)
		return std::atoi(port);
	return 0;
}