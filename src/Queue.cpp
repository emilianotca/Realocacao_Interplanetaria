//
// Created by emilianotca on 08-Jul-21.
//

#include "../include/Queue.h"

Queue::Queue() : size_of_queue {0} {}

Queue::~Queue() {}

int Queue::element_count() const
{
    return size_of_queue;
}