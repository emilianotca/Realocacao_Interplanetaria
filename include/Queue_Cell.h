//
// Created by emilianotca on 08-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_QUEUE_CELL_H
#define REALOCACAO_INTERPLANETARIA_QUEUE_CELL_H

#include "../include/Element.h"
#include "../include/Queue.h"

class Queue_Cell
{
public:
    Queue_Cell();
    ~Queue_Cell();
    void print() const; // Print the element's content

private:
    Element* element;
    Queue_Cell* next_element;

    friend Queue;
};

#endif //REALOCACAO_INTERPLANETARIA_QUEUE_CELL_H
