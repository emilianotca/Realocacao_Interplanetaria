//
// Created by emilianotca on 08-Jul-21.
//

#include "../include/Element.h"

// Constructor and Destructor
Element::Element() = default;

Element::~Element() = default;

// Interface
std::string Element::get_data() const
{
    return this->data;
}

void Element::set_data(std::string new_data)
{
    this->data.clear();

    this->data = new_data;
}