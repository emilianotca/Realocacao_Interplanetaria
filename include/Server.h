//
// Created by emilianotca on 10-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_SERVER_H
#define REALOCACAO_INTERPLANETARIA_SERVER_H

#include "Linked_Queue.h"

class Server
{
public:
    Server();
    Server(int new_server_id);
    ~Server();
    int get_id() const;
    void set_id(int new_id);
    int get_status() const;
    void set_status(int new_status);

private:
    int server_id;
    int server_status;
    Linked_Queue* server_buffer;
};

#endif //REALOCACAO_INTERPLANETARIA_SERVER_H
