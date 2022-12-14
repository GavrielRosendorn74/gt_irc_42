/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:38 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 23:18:31 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/commands/Command.hpp"

void    Command::_quit()
{
    _server->log("/QUIT exec function called");
    std::string comment;
    if (_args.empty())
        comment = "Leaving...";
    else
        comment = _args.at(0);
    
    _client->write(RPL_QUIT(_client->prefix(), comment));
}