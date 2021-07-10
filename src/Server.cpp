//
// Created by emilianotca on 10-Jul-21.
//

#include "../include/Server.h"

// Constructor and Destructor
Server::Server(int new_server_id) : server_id {new_server_id}, server_buffer {nullptr}
{
    server_buffer = new Linked_Queue();
}

Server::~Server()
{
    delete server_buffer;
}

// Other methods
