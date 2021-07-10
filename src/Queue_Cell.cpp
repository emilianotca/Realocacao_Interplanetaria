//
// Created by emilianotca on 08-Jul-21.
//

#include <iostream>
#include "../include/Queue_Cell.h"

Queue_Cell::Queue_Cell() : element{nullptr}, next_cell {nullptr}
{
    this->element = new Element();
}

Queue_Cell::~Queue_Cell()
{
    delete this->element;
}

void Queue_Cell::print() const
{
    std::cout << this->element->get_data() << std::endl;
}