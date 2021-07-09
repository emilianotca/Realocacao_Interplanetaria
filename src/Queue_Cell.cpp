//
// Created by emilianotca on 08-Jul-21.
//

#include <iostream>
#include "../include/Queue_Cell.h"

Queue_Cell::Queue_Cell() : element{nullptr}, next_element {nullptr}
{
    element = new Element();
}

Queue_Cell::~Queue_Cell()
{
    delete element;
}

void Queue_Cell::print() const
{
    std::cout << element->get_data() << std::endl;
}