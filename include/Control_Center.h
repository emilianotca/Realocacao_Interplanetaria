//
// Created by emilianotca on 10-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_CONTROL_CENTER_H
#define REALOCACAO_INTERPLANETARIA_CONTROL_CENTER_H

#include "Server_Rack.h"
#include <string>

class Control_Center
{
public:
    Control_Center();
    Control_Center(int number_of_servers);
    ~Control_Center();
    void INFO(int server_id, std::string data);
    void WARN(int server_id, int position);
    void TRAN(int server_1_id, int server_2_id);

private:
    Server_Rack rack;
};

#endif //REALOCACAO_INTERPLANETARIA_CONTROL_CENTER_H
