//
// Created by emilianotca on 08-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_QUEUE_H
#define REALOCACAO_INTERPLANETARIA_QUEUE_H

#include <string>

class Queue
{
public:
    Queue();
    virtual ~Queue();
    virtual void insert(std::string element_data) = 0; // Cell insertion method
    virtual std::string remove() = 0; // Cell removal method
    virtual int element_count() const; // Returns the cell count
    virtual bool is_empty() const = 0; // Testing queue emptiness
    virtual void print() const = 0; // Print current elements in the queue
protected:
    int size_of_queue;
};

#endif //REALOCACAO_INTERPLANETARIA_QUEUE_H
