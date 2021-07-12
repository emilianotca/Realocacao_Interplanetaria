//
// Created by emilianotca on 10-Jul-21.
//

#include "../include/Server.h"
#include <stdexcept>

// Constructor and Destructor
Server::Server(int new_server_id) : server_id {new_server_id}, server_status {1}, server_buffer {nullptr}
{
    server_buffer = new Linked_Queue();
}

Server::~Server()
{
    delete server_buffer;
}

// Other methods
int Server::get_id() const
{
    return this->server_id;
}

int Server::get_status() const
{
    return this->server_status;
}

void Server::set_status(int new_status)
{
    // Sanity check
    if(new_status != 0 && new_status != 1)
    {
        throw std::logic_error("Bad status - use either 0 or 1!");
    }

    this->server_status = new_status;
}