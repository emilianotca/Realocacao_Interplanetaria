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
    ~Queue();
    virtual void insert(std::string element_data) = 0; // Cell insertion method
    virtual void remove() = 0; // Cell removal method
    virtual void clear() = 0; // Delete all cells and make the Queue clean
    virtual int element_count() const; // Returns the cell count


private:
    int size_of_queue;
};

#endif //REALOCACAO_INTERPLANETARIA_QUEUE_H
