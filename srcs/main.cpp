/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:54:16 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/07 07:16:46 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network/Server.hpp"

# define SUCCCES 0;
# define FAILED 1;

int main(int argc, char **argv)
{
	Server *server;

	try 
	{
		if (argc != 3)
			throw Exception::args();
		server = new Server(argv[1], argv[2]);
		server	->launch()
				->live();
		
	} catch (const exception &ex) {
		cerr << ex.what() << endl;
		return FAILED;
	}

	delete server;
	return SUCCCES;
}