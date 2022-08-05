/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grosendo <grosendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:14:45 by grosendo          #+#    #+#             */
/*   Updated: 2022/08/05 10:14:08 by grosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
using namespace std;

#define ARGS_ERROR "ERROR: Arguments error! ./ircserv <PORT> <PASSWORD>"
#define PORT_FORMAT "ERROR: Port format invalid! Port must be only digits."
#define PORT_INVALID "ERROR: Port invalid!"
#define PWD_FORMAT "ERROR: Password format invalid! Password must be at least 6 characters long, contains at least 1 digit an 1 special character"
#define PWD_INVALID "ERROR: Password invalid!"
#define EXEC_FAILURE "ERROR: Execution of command failed!"
#define SOCKET_CREATION_FAILURE "ERROR: Socket creation failed"
#define SOCKET_CONFIG_FAILURE "ERROR: Socket configuration failed"
#define BINDING_FAILURE "ERROR: Socket binding failed"
#define NONBLOCKING_FAILURE "ERROR: Socket failed to listen on port"
#define LISTENING_FAILURE "ERROR: Socket failed to listen on port"
#define SELECT_FAILURE "ERROR: Select() failed"
#define ACCPET_FAILURE "ERROR: Accept() failed"
#define CMD_ARG_ERROR "ERROR: Wong agruments implementation for current command"
#define NO_SUCH_CHAN "ERROR: No such Channel"
#define UNREGISTERED_USER "ERROR: Current user not registered"
#define USER_REGISTRATION_ARGS_ERROR "ERROR: User registration need 4 arguments: <username> <hostname> <servername> <realname>"
#define USER_ALREADY_REGISTERED "ERROR: User already registered"
#define NICKNAME_ALREADY_TAKEN "ERROR: The nickname you've choosen is already taken"
#define USER_NOT_IN_CHAN "ERROR: User not present in this channel"
#define USER_ALREADY_IN_CHAN "ERROR: User already present in this channel"
#define NO_SUCH_USER "ERROR: No such User"
#define No_SUCH_COMMAND "ERROR: No such Command"

class Exception
{
    public:
        class args : public exception
        {
            const char *what() const throw() { return ARGS_ERROR;}
        };

        class invalid_port_format : public exception
        {
            const char *what() const throw() {return PORT_FORMAT; }
        };

        class invalid_port : public exception
        {
            const char *what() const throw() {return PORT_INVALID;}
        };

        class invalid_pwd_format : public exception
        {
            const char *what() const throw() {return PWD_FORMAT;}
        };

        class invalid_pwd : public exception
        {
            const char *what() const throw() {return PWD_INVALID;}
        };

        class exec_failure : public exception 
        {
            const char *what() const throw() {return EXEC_FAILURE;}
        };

        class socket_creation_failure : public exception
        {
            const char *what() const throw() {return SOCKET_CREATION_FAILURE;}
        };

		class socket_non_blocking_failure : public exception
        {
            const char *what() const throw() {return NONBLOCKING_FAILURE;}
        };

        class socket_config_failure : public exception
        {
            const char *what() const throw() {return SOCKET_CONFIG_FAILURE;}
        };

        class binding_failure : public exception
        {
            const char *what() const throw() {return BINDING_FAILURE;}
        };

        class listening_failure : public exception
        {
            const char *what() const throw() {return LISTENING_FAILURE;}
        };

        class select_failure : public exception
        {
            const char *what() const throw() {return SELECT_FAILURE;}
        };

        class accept_failure : public exception
        {
            const char *what() const throw() {return ACCPET_FAILURE;}
        };
        
        class cmd_arg_error : public exception
        {
            const char *what() const throw() {return CMD_ARG_ERROR;}
        };

        class no_such_chan : public exception
        {
            const char *what() const throw() {return NO_SUCH_CHAN;}
        };

        class unregistered_user : public exception
        {
            const char *what() const throw() {return UNREGISTERED_USER;}
        };

        class user_registration_args_error : public exception
        {
            const char *what() const throw() {return USER_REGISTRATION_ARGS_ERROR;}
        };

        class user_already_registered : public exception
        {
            const char *what() const throw() {return USER_ALREADY_REGISTERED;}
        };

        class nickname_already_taken : public exception
        {
            const char *what() const throw() {return NICKNAME_ALREADY_TAKEN;}
        };

        class user_not_in_chan : public exception
        {
            const char *what() const throw() {return USER_NOT_IN_CHAN;}
        };

        class user_already_in_chan : public exception
        {
            const char *what() const throw() {return USER_ALREADY_IN_CHAN;}
        };

        class no_such_user : public exception
        {
            const char *what() const throw() {return NO_SUCH_USER;}
        };

        class no_such_command : public exception
        {
            const char *what() const throw() {return No_SUCH_COMMAND;}
        };
};

#endif