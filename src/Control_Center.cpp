//
// Created by emilianotca on 10-Jul-21.
//

#include "../include/Control_Center.h"
#include <iostream>

// Constructor and Destructor
Control_Center::Control_Center() = default;

Control_Center::Control_Center(int number_of_servers) : rack(number_of_servers) {}

Control_Center::~Control_Center() = default;

// Methods
void Control_Center::INFO(int server_id, std::string data)
{
    // Checking if ID is valid
    if(this->rack.check_id(server_id))
    {
        this->rack.add_to_buffer(server_id, data);
    }
    else
    {
        std::cerr << "FATAL ERROR: SPECIFIED SERVER DOES NOT EXIST." << std::endl;
    }
}

void Control_Center::WARN(int server_id, int position)
{
    // Checking if ID is valid
    if(this->rack.check_id(server_id))
    {
        this->rack.prioritize_data(server_id, position);
    }
    else
    {
        std::cerr << "FATAL ERROR: SPECIFIED SERVER DOES NOT EXIST." << std::endl;
    }
}

void Control_Center::TRAN(int server_1_id, int server_2_id)
{
    // Checking if ID is valid
    if(this->rack.check_id(server_1_id) && this->rack.check_id(server_2_id))
    {
        // Transferring content from server_1_id to server_2_id]
        std::string transferred_string;

        while(true)
        {
            try
            {
                // Transferring data
                transferred_string = this->rack.depart(server_1_id);
                this->rack.add_to_buffer(server_2_id, transferred_string);


            }catch(std::logic_error& exception)
            {
                break;
            }
        }

        // Erasing data from source server
        this->rack.display_and_erase(server_1_id, false);
    }
    else
    {
        std::cerr << "FATAL ERROR: SPECIFIED SERVER DOES NOT EXIST." << std::endl;
    }
}

void Control_Center::ERRO(int server_id)
{
    // Checking if ID is valid
    if(this->rack.check_id(server_id))
    {
        // Displaying error message and printing out buffer content
        std::cout << "ERRO " << server_id << std::endl;

        this->rack.display_and_erase(server_id, true);
    }
    else
    {
        std::cerr << "FATAL ERROR: SPECIFIED SERVER DOES NOT EXIST." << std::endl;
    }
}

void Control_Center::SEND()
{
    // Looping through the servers and dispatching their buffer's first on line
    std::string departed;

    for(auto control {0}; control < this->rack.total_servers(); control++)
    {
        // Sanity check
        try
        {
            departed = this->rack.depart(control);
            this->conscience_history.add_to_history(departed);

        }catch(std::logic_error& exception)
        {
           continue;
        }
    }
}

void Control_Center::FLUSH()
{
    // Displaying conscience history
    this->conscience_history.print_history();

    // Looping through the servers and displaying the remaining content of their buffers
    for(auto control {0}; control < this->rack.total_servers(); control++)
    {
        // Sanity check
        try
        {
            this->rack.check_server_buffer(control);

        }catch(std::logic_error& exception)
        {
            continue;
        }
    }

    // Erasing the remaining content
    for(auto control {0}; control < this->rack.total_servers(); control++)
    {
        this->rack.display_and_erase(control, false);
    }
}