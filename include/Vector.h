//
// Created by emilianotca on 10-Jul-21.
//

#ifndef REALOCACAO_INTERPLANETARIA_VECTOR_H
#define REALOCACAO_INTERPLANETARIA_VECTOR_H

template <typename element_type, int N>
class Vector
{
public:
    Vector();
    ~Vector();
    void print() const; // Print all elements currently in the vector
    int element_count() const; // Return the current number of elements in the vector
    bool is_empty() const; // Test for emptiness
    void insert_back(element_type new_element); // Insert new element at the back of the vector
    element_type remove(int position); // Remove from an arbitrary position

private:
    static const int MAX_ELEMENTS {N};
    int size_of_vector;
    element_type* elements [MAX_ELEMENTS];
};

#endif //REALOCACAO_INTERPLANETARIA_VECTOR_H
