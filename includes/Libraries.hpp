/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libraries.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:34:19 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/07 07:25:01 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARIES_HPP
# define LIBRARIES_HPP

#include "Exceptions.hpp"
#include "Utils.hpp"
#include <iostream>
using namespace std;
#include <sys/socket.h> //sockets  setsockopt getsockname  getaddrinfo freeaddrinfo  bind connect listen accept send recv
#include <netdb.h> //getprotobyname gethostbyname  getaddrinfo freeaddrinfo
#include <arpa/inet.h> //htons htonl ntohs ntohl inet_addr inet_ntoa
#include <signal.h> //signal
#include <unistd.h> //lseek
#include <sys/stat.h> //fstat
#include <fcntl.h> //fcntl
#include <poll.h> //poll
#include <sys/select.h> //select
#include <vector>
#include <map>
#include <sstream> //istringstream

#define MAX_CLIENTS 100

#define GREEN "\033[38;5;49m"
#define RED "\033[31;5;160m"
#define PINK "\033[38;5;198m"
#define YELLOW "\033[38;5;220m"
#define BLUE "\033[38;5;69m"
#define ORANGE "\033[38;5;202m"
#define DEFAULT "\033[0m"

#define VALID_ARGS "PORT AND PASSWORD ARE VALID!\n"
#define WELCOME_IRC_MESSAGE "Welcome to this IRC made by Tanguy Billon and Gavriel Rosendorn"
#define NEW_CHAN_WELCOME "Welcome to this new channel"

#endif