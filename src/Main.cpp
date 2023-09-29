#include <iostream>

#include "Utils.hpp"
#include "Server.hpp"

int main(int argc, char const *argv[]) {
    bool ret;
    Server server(8000);

    ret = Utils::get_input_param(argc, argv);
    if (ret == false) {
        return EXIT_FAILURE;
    }

    ret = server.run(10);
    if (ret == false) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/*
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

int main(int argc, char const *argv[]) {
    io_service io;

    // Create an endpoint to listen on port 8080
    tcp::endpoint endpoint(tcp::v4(), 8080);

    // Create a socket to accept incoming connections
    tcp::acceptor acceptor(io, endpoint);

    std::cout << "Server listening on port 8080..." << std::endl;

    while (true) {
        // Create a socket to represent the client connection
        tcp::socket socket(io);

        // Wait for and accept a new connection
        acceptor.accept(socket);

        // Read the HTTP request
        boost::asio::streambuf request;
        boost::asio::read_until(socket, request, "\r\n\r\n");

        // Print the HTTP request
        std::istream request_stream(&request);
        std::string http_request;
        while (std::getline(request_stream, http_request)) {
            std::cout << http_request << std::endl;
        }

        // Send an HTTP response (in this example, a simple "Hello, World!" response)
        std::string response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
        boost::asio::write(socket, boost::asio::buffer(response));

        // Close the connection
        socket.close();
    }

    return 0;
}*/