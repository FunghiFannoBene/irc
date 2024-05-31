/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:41:37 by mneri             #+#    #+#             */
/*   Updated: 2024/05/28 22:48:42 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

int checkPort(int port)
{
	if(!(port >= 1024 && port <= 65535))
		port = 0;
	return port;
}