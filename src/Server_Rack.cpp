//
// Created by emilianotca on 11-Jul-21.
//

#include "../include/Server_Rack.h"
#include <stdexcept>
#include <iostream>

// Constructor and Destructor
Server_Rack::Server_Rack() : number_of_servers {1}
{
    // Initializing Server Rack
    this->rack = new Server [number_of_servers];

    // Updating Server IDs
    for (auto control {0}; control < this->number_of_servers; control++)
    {
        this->rack[control].set_id(control);
    }
}

Server_Rack::Server_Rack(int server_quantity) : number_of_servers {server_quantity}
{
    // Initializing Server Hack
    if(number_of_servers < 0)
    {
        throw std::logic_error("Number of servers can't be negative.");
    }

    this->rack = new Server [number_of_servers];

    // Updating Server IDs
    for (auto control {0}; control < this->number_of_servers; control++)
    {
        this->rack[control].set_id(control);
    }
}

Server_Rack::~Server_Rack()
{
    delete [] this->rack;
}

void Server_Rack::change_status(int server_id, int new_status)
{
    // Sanity check
    if(!this->check_id(server_id))
    {
        throw std::logic_error("There's no server with such ID!");
    }

    try
    {
        this->rack[server_id].set_status(new_status);

    } catch (std::logic_error& except)
    {
        std::cerr << except.what() << std::endl;
    }
}

int Server_Rack::check_status(int server_id) const
{
    // Sanity check
    if(!this->check_id(server_id))
    {
        throw std::logic_error("There's no server with such ID!");
    }

    return this->rack[server_id].get_status();
}

bool Server_Rack::check_id(int server_id) const
{
    // Loops through the Rack and checks if searched ID exists
    for(auto control {0}; control < this->number_of_servers; control++)
    {
        if(this->rack[control].get_id() == server_id)
        {
            return true;
        }
        else
        {
            continue;
        }
    }

    return false;
}

int Server_Rack::total_servers() const
{
    return this->number_of_servers;
}

void Server_Rack::add_to_buffer(int server_id, std::string data)
{
    // Sanity check
    if(!this->check_id(server_id))
    {
        throw std::logic_error("There's no server with such ID!");
    }

    try
    {
        this->rack[server_id].load_data(data);

    }catch(std::logic_error& except)
    {
        std::cerr << except.what() << std::endl;
    }
}

std::string Server_Rack::depart(int server_id)
{
    // Sanity check
    if(!this->check_id(server_id))
    {
        throw std::logic_error("There's no server with such ID!");
    }

    std::string uploaded_data {};

    uploaded_data = this->rack[server_id].send_data();
    return uploaded_data;
}

void Server_Rack::check_server_buffer(int server_id) const
{
    // Sanity check
    if(!this->check_id(server_id))
    {
        throw std::logic_error("There's no server with such ID!");
    }

    this->rack[server_id].check_buffer();
}

void Server_Rack::prioritize_data(int server_id, int position)
{
    try
    {
        this->rack[server_id].prioritize_data(position);

    }catch(std::logic_error& except)
    {
        std::cerr << except.what() << std::endl;
    }
}

void Server_Rack::display_and_erase(int server_id, bool display)
{
    // First step: Display current data held by selected server
    if(display)
    {
        this->rack[server_id].check_buffer();
    }

    // Second step: Erase buffer of selected server
    this->rack[server_id].erase_buffer();
}