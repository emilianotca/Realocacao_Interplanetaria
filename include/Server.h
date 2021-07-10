//
// Created by emilianotca on 10-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_SERVER_H
#define REALOCACAO_INTERPLANETARIA_SERVER_H

#include <string>
#include "Linked_Queue.h"

class Server
{
public:
    Server(std::string new_server_id);
    ~Server();


private:
    std::string server_id;
    Linked_Queue* server_buffer;
};

#endif //REALOCACAO_INTERPLANETARIA_SERVER_H
