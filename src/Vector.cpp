//
// Created by emilianotca on 10-Jul-21.
//

#include "../include/Vector.h"
#include <iostream>
#include <stdexcept>

template <typename element_type, int N> Vector<element_type, N>::Vector() : size_of_vector {0} {}

template <typename element_type, int N> Vector<element_type, N>::~Vector()
{
    delete [] this->elements;
}

template <typename element_type, int N> void Vector<element_type, N>::print() const
{
    std::cout << "[ ";

    for(auto control {0}; control < this->element_count(); control++)
    {
        std::cout << this->elements[control] << " ";
    }

    std::cout << "]";
}

template <typename element_type, int N> int Vector<element_type, N>::element_count() const
{
    return this->size_of_vector;
}

template <typename element_type, int N> bool Vector<element_type, N>::is_empty() const
{
    return (this->size_of_vector == 0);
}

template <typename element_type, int N> void Vector<element_type, N>::insert_back(element_type new_element)
{
    // Sanity check
    if(this->element_count() == MAX_ELEMENTS)
    {
        throw std::logic_error("Can NOT insert - Vector at maximum capacity!");
    }
    else
    {
        this->elements[this->element_count()] = new_element;

        this->size_of_vector++;
    }
}

template <typename element_type, int N> element_type Vector<element_type, N>::remove(int position)
{
    // Sanity check
    if(position > this->element_count())
    {
        throw std::logic_error("Can NOT remove - not a valid position!");
    }
    else
    {
        element_type returned_element {};
        int actual_position = position - 1;

        if(position == this->element_count()) // Last element
        {
            returned_element = this->elements[actual_position];

            this->size_of_vector--;
        }
        else if(position == 1) // First element
        {
            returned_element = this->elements[actual_position];

            // TODO: Reallocation routine


            this->size_of_vector--;
        }
        else // Internal element
        {
            returned_element = this->elements[actual_position];

            // TODO: Reallocation routine

            this->size_of_vector--;
        }

    }
}
