//
// Created by emilianotca on 19-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_HISTORY_H
#define REALOCACAO_INTERPLANETARIA_HISTORY_H

#include <string>

#include "Linked_Queue.h"

class History
{
public:
    History();
    ~History();
    void add_to_history(std::string data);
    void print_history() const;

private:
    Linked_Queue* conscience_history;
};

#endif //REALOCACAO_INTERPLANETARIA_HISTORY_H
