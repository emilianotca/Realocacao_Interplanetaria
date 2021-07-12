//
// Created by emilianotca on 11-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_SERVER_RACK_H
#define REALOCACAO_INTERPLANETARIA_SERVER_RACK_H

#include "Server.h"

class Server_Rack
{
public:
    Server_Rack();
    Server_Rack(int server_quantity);
    ~Server_Rack();
    void change_status(int server_id, int new_status);
    int check_status(int server_id) const;
    bool check_id(int server_id) const;
    int active_servers() const;

private:
    int number_of_servers;
    Server* rack;
};

#endif //REALOCACAO_INTERPLANETARIA_SERVER_RACK_H
