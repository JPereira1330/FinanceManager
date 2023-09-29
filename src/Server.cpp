/**
 * @file    Server.cpp
 * @author  José C. Pereira (jpereira1330@gmail.com)
 * @brief 
 * @version 1.0 - Alpha
 * @date    2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <cstdint>
#include <iostream>
#include <boost/asio.hpp>

#include "Server.hpp"

using namespace boost::asio;
using ip::tcp;

Server::Server(uint16_t port) {
    this->port = port;
}

Server::~Server() {

}

bool Server::run(uint16_t queue) {

    /// 
    io_service io;

    /// Initializing Endpoint and Acceptor
    tcp::endpoint endpoint(tcp::v4(), this->port);
    tcp::acceptor acceptor(io, endpoint);

    std::cout << " [SERVER] Listen on port " << this->port << std::endl;

    while(true) {
        tcp::socket socket(io);
        acceptor.accept(socket);

        boost::asio::streambuf request;
        boost::asio::read_until(socket, request, "\r\n\r\n");
    }

    return true;
}
