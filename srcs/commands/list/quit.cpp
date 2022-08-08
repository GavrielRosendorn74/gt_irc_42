/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:20:38 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/08 20:32:58 by grosendo         ###   ########.fr       */
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
    
    //* REPLY FUNCTION TO RETURN REPLY CODE
    //* client write message and send REPLY code to quit server
}