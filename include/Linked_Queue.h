//
// Created by emilianotca on 10-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_LINKED_QUEUE_H
#define REALOCACAO_INTERPLANETARIA_LINKED_QUEUE_H

#include "../include/Queue.h"
#include "../include/Queue_Cell.h"
#include <string>

class Linked_Queue : public Queue
{
public:
    Linked_Queue();
    ~Linked_Queue();
    virtual void insert(std::string element_data) override; // Cell insertion method
    virtual std::string remove() override; // Cell removal method
    virtual int element_count() const override; // Returns the cell count
    virtual bool is_empty() const override; // Tests queue emptiness
    virtual void print() const override; // Print current elements in queue
    void clear(); // Delete the cells

private:
    Queue_Cell* front; // Holds the head
    Queue_Cell* back; // Holds the tail
};

#endif //REALOCACAO_INTERPLANETARIA_LINKED_QUEUE_H
