//
// Created by emilianotca on 08-Jul-21.
//

#include "../include/Testcases.h"
#include "../include/Element.h"
#include "../include/Queue_Cell.h"
#include "../include/Linked_Queue.h"
#include "../include/Server.h"
#include "../include/Server_Rack.h"
#include "../include/Control_Center.h"

#include <iostream>
#include <cassert>
#include <string>

void test_Element()
{
    auto* subject_0 = new Element();

    // Testing get_data
    assert(subject_0->get_data().empty()); // Data should initially be empty

    // Testing set_data
    std::string test_data("Testing 123@!");
    subject_0->set_data(test_data);

    assert(subject_0->get_data() == test_data);

    delete subject_0;
}

void test_Queue_Cell()
{
    auto* subject_0 = new Queue_Cell();

    // Testing initial value held by cell's element
    std::cout << "Expecting nothing. Got: ";
    subject_0->print();

    delete subject_0;
}

void test_Linked_Queue()
{
    auto* subject_0 = new Linked_Queue();

    // Testing initial conditions
    assert(subject_0->is_empty());
    assert(subject_0->element_count() == 0);

    // Testing single insertion and deletion
    std::string test_string_0 {"Testing 0"};
    subject_0->insert(test_string_0);

    assert(!subject_0->is_empty());
    assert(subject_0->element_count() == 1);

    auto returned_value = subject_0->remove();

    assert(returned_value == test_string_0);

    // Testing multiple insertion
    std::string test_string_1 {"Testing 1"};
    std::string test_string_2 {"Testing 2"};
    std::string test_string_3 {"Testing 3"};

    subject_0->insert(test_string_1);
    subject_0->insert(test_string_2);
    subject_0->insert(test_string_3);

    assert(subject_0->element_count() == 3);
    assert(!subject_0->is_empty());

    returned_value = subject_0->remove();

    assert(returned_value == test_string_1);
    assert(subject_0->element_count() == 2);
    assert(!subject_0->is_empty());

    returned_value = subject_0->remove();

    assert(returned_value == test_string_2);
    assert(subject_0->element_count() == 1);
    assert(!subject_0->is_empty());

    returned_value = subject_0->remove();

    assert(returned_value == test_string_3);
    assert(subject_0->element_count() == 0);
    assert(subject_0->is_empty());

    // Testing cutting in line method
    std::string test_string_4 {"Testing 4"};

    subject_0->insert(test_string_1);
    subject_0->insert(test_string_2);
    subject_0->insert(test_string_3);
    subject_0->insert(test_string_4);

    auto flag {0};

    try
    {
        subject_0->queue_jump(-1);

    }catch(std::logic_error& except)
    {
        flag = 1;
    }

    assert(flag == 1);

    try
    {
        subject_0->queue_jump(7);

    }catch(std::logic_error& except)
    {
        flag = 2;
    }

    assert(flag == 2);

    subject_0->queue_jump(3); // Expecting test_string_3 1 2 4 to be the new order

    returned_value = subject_0->remove();

    assert(returned_value == test_string_3);

    returned_value = subject_0->remove();

    assert(returned_value == test_string_1);

    returned_value = subject_0->remove();

    assert(returned_value == test_string_2);

    returned_value = subject_0->remove();

    assert(returned_value == test_string_4);

    subject_0->insert(test_string_1);
    subject_0->insert(test_string_2);

    subject_0->queue_jump(1);

    returned_value = subject_0->remove();

    assert(returned_value == test_string_1);

    returned_value = subject_0->remove();

    assert(returned_value == test_string_2);
}

void test_Server()
{
    // Testing default constructor
    auto* subject_0 = new Server();

    assert(subject_0->get_id() == -1);

    delete subject_0;

    // Initializing a single server with one arg constructor
    subject_0 = new Server(54);

    // Testing initial conditions
    assert(subject_0->get_id() == 54);
    assert(subject_0->get_status() == 1);

    // Testing invalid settings
    int flag = 0;

    try
    {
        subject_0->set_status(-1); // Should throw an exception

    } catch(std::logic_error& except)
    {
        flag = 1;
    }

    assert(flag == 1);

    try
    {
        subject_0->set_status(-1); // Should NOT throw an exception

    } catch(std::logic_error& except)
    {
        flag = 2;
    }

    assert(flag == 2);

    // Testing ID setting
    subject_0->set_id(132);

    assert(subject_0->get_id() == 132);

    // Testing data handling
    std::string test_data_0 = "TEST 0101010";
    std::string test_data_1 = "TEST 1000101";
    std::string test_data_2 = "TEST 0000000";

    subject_0->load_data(test_data_0);
    subject_0->load_data(test_data_1);
    subject_0->load_data(test_data_2);

    subject_0->check_buffer(); // Expecting test_data_0 to 2

    auto sent_data = subject_0->send_data();

    assert(sent_data == test_data_0);

    sent_data = subject_0->send_data();

    assert(sent_data == test_data_1);

    subject_0->check_buffer(); // Expecting test_data_2

    // Testing data manipulation with server down
    subject_0->set_status(0); // Server inactive

    try
    {
        subject_0->load_data(test_data_2);

    }catch(std::logic_error& except)
    {
        flag = 3;
    }

    assert(flag == 3);

    try
    {
        sent_data = subject_0->send_data();

    }catch(std::logic_error& except)
    {
        flag = 4;
    }

    assert(flag == 4);

    delete subject_0;
}

void test_Server_Rack()
{
    // Initializing a new rack with the default number of servers
    auto* subject_0 = new Server_Rack();

    assert(subject_0->total_servers() == 1);
    assert(subject_0->check_id(0));
    assert(subject_0->check_status(0) == 1);

    delete subject_0;

    // Initializing a new rack with a custom number of server
    subject_0 = new Server_Rack(20);

    assert(subject_0->total_servers() == 20); // Expecting 20 active servers

    // Testing initial configurations
    for(auto control {0}; control < subject_0->total_servers(); control++)
    {
        assert(subject_0->check_id(control));
        assert(subject_0->check_status(control));
    }

    // Testing custom configurations
    subject_0->change_status(3, 0); // Turning off server 4

    assert(subject_0->check_status(3) == 0);

    subject_0->change_status(3, 1); // Turning on server 4

    subject_0->change_status(5, -1); // Expecting exception to be handled

    // Printing out statuses
    subject_0->change_status(5, 0);
    subject_0->change_status(10, 0);
    subject_0->change_status(15, 0);

    for(auto control {0}; control < subject_0->total_servers(); control++)
    {
        if(subject_0->check_status(control) == 1)
        {
            std::cout << "ONLINE" << std::endl;
        }
        else
        {
            std::cout << "OFFLINE" << std::endl;
        }
    }

    // Testing individual buffer management

    std::string test_data_0 = "TEST 0101010";
    std::string test_data_1 = "TEST 1000101";
    std::string test_data_2 = "TEST 0000000";

    subject_0->add_to_buffer(18, test_data_0);
    subject_0->add_to_buffer(0, test_data_1);
    subject_0->add_to_buffer(10, test_data_2); // Should not work
    subject_0->add_to_buffer(15, test_data_2); // Should not work either

    // Testing buffer operations
    subject_0->add_to_buffer(18, test_data_1);
    subject_0->add_to_buffer(18, test_data_2);

    subject_0->check_server_buffer(18); // Expecting test_data_0 to 2

    subject_0->depart(18);
    subject_0->depart(18);

    subject_0->check_server_buffer(18); // Expecting test_data_2

    subject_0->depart(10); // Should not work
    subject_0->check_server_buffer(10); // Should not work

    // Testing prioritization
    subject_0->add_to_buffer(18, test_data_1);
    subject_0->add_to_buffer(18, test_data_0);

    subject_0->check_server_buffer(18); // Expecting test_data_2

    subject_0->prioritize_data(18, 3);

    std::cout << "----------------------------------------------------------" << std::endl;

    subject_0->check_server_buffer(18);

    delete subject_0;
}

void test_Control_Center()
{
    auto* subject_0 = new Control_Center(10); // Initializing control center with 10 servers.

    std::string test_data_0 = "TEST 0101010";
    std::string test_data_1 = "TEST 1000101";
    std::string test_data_2 = "TEST 0000000";

    // INFO
    subject_0->INFO(0, test_data_0);
    subject_0->INFO(0, test_data_2);
    subject_0->INFO(0, test_data_1);
    subject_0->INFO(50, test_data_1); // Error

    // WARN
    subject_0->WARN(0, 3);

    subject_0->INFO(0, "EMILIANO 00101010");
    subject_0->INFO(1, "ISABELA 10001010");
    subject_0->INFO(1, "ADRIANO 11111111");
    subject_0->INFO(1, "MARCIA 111111111");
    subject_0->INFO(9, "SEXO 101010");
    subject_0->INFO(9, "VAGINA 123");
    subject_0->TRAN(1, 9);
    subject_0->SEND();
    subject_0->SEND();
    subject_0->FLUSH();
}