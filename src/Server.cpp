//
// Created by emilianotca on 10-Jul-21.
//

#include "../include/Server.h"
#include <iostream>
#include <stdexcept>

// Constructor and Destructor
Server::Server() : server_id {-1}, server_status {1}, server_buffer {nullptr}
{
    this->server_buffer = new Linked_Queue();
}

Server::Server(int new_server_id) : server_id {new_server_id}, server_status {1}, server_buffer {nullptr}
{
    this->server_buffer = new Linked_Queue();
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

void Server::set_id(int new_id)
{
    this->server_id = new_id;
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

void Server::check_buffer() const
{
    if(this->server_status == 1)
    {
        this->server_buffer->print();
    }
    else
    {
        throw std::logic_error("Server is down!");
    }
}

void Server::load_data(std::string data)
{
    if(this->server_status == 1)
    {
        this->server_buffer->insert(data);
    }
    else
    {
        throw std::logic_error("Server is down!");
    }
}

std::string Server::send_data()
{
    if(this->server_status == 1 && !this->server_buffer->is_empty())
    {
        return this->server_buffer->remove();
    }
    else
    {
        throw std::logic_error("Server is down!");
    }
}

void Server::prioritize_data(int position)
{
    this->server_buffer->queue_jump(position);
}

void Server::erase_buffer()
{
    this->server_buffer->clear();
}
