//
// Created by emilianotca on 19-Jul-21.
//

#include "../include/History.h"

History::History()
{
    this->conscience_history = new Linked_Queue();
}

History::~History()
{
    delete conscience_history;
}

void History::add_to_history(std::string data)
{
    this->conscience_history->insert(data);
}

void History::print_history() const
{
    this->conscience_history->print();
}