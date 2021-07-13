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

void TRAN(int server_1_id, int server_2_id)
{

}