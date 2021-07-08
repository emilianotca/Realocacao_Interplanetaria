//
// Created by emilianotca on 08-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_ELEMENT_H
#define REALOCACAO_INTERPLANETARIA_ELEMENT_H

#include <string>

class Element
{
public:
    Element();
    ~Element();
    std::string get_data() const;
    void set_data(std::string new_data);

private:
    std::string data;
};

#endif //REALOCACAO_INTERPLANETARIA_ELEMENT_H
