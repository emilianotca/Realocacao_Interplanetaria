//
// Created by emilianotca on 08-Jul-21.
//

#include "../include/Testcases.h"
#include "../include/Element.h"
#include "../include/Queue_Cell.h"
#include "../include/Linked_Queue.h"

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