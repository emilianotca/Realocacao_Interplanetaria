//
// Created by emilianotca on 08-Jul-21.
//

#include "../include/Testcases.h"
#include "../include/Element.h"
#include "../include/Queue_Cell.h"

#include <iostream>
#include <cassert>

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