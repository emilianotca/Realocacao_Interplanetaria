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
    int total_servers() const;
    void add_to_buffer(int server_id, std::string data);
    std::string upload_meganet(int server_id);
    void check_server_buffer(int server_id) const;
    void prioritize_data(int server_id, int position);

private:
    int number_of_servers;
    Server* rack;
};

#endif //REALOCACAO_INTERPLANETARIA_SERVER_RACK_H
