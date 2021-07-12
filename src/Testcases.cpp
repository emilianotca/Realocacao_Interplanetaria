//
// Created by emilianotca on 08-Jul-21.
//

#include "../include/Testcases.h"
#include "../include/Element.h"
#include "../include/Queue_Cell.h"
#include "../include/Linked_Queue.h"
#include "../include/Server.h"
#include "../include/Server_Rack.h"

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

    delete subject_0;
}

void test_Server_Rack()
{
    // Initializing a new rack with the default number of servers
    auto* subject_0 = new Server_Rack();

    assert(subject_0->active_servers() == 1);

    delete subject_0;
}