//
// Created by emilianotca on 10-Jul-21.
//

#include "../include/Linked_Queue.h"
#include <stdexcept>

// Constructor and Destructor
Linked_Queue::Linked_Queue() : Queue(), front {nullptr}, back {nullptr}
{
    // Allocating head and making both pointers point to it
    this->front = new Queue_Cell();
    this->back = this->front;
}

Linked_Queue::~Linked_Queue() noexcept
{
    // Clearing queue
    this->clear();

    // Clearing head and updating pointers to prevent dangling pointer
    delete this->front;

   this->front = nullptr;
   this->back = nullptr;
}

void Linked_Queue::insert(std::string element_data)
{
    // Allocating new cell and setting data
    Queue_Cell* new_cell = new Queue_Cell();
    new_cell->element->set_data(element_data);

    // Sanity check
    if(this->front == this->back) // Empty queue
    {
        // Updating both head's next and back pointers
        this->front->next_cell = new_cell;
        this->back = new_cell;

        size_of_queue++;
    }
    else // Queue has at least one item
    {
        // Linking last element and updating back pointer
        this->back->next_cell = new_cell;
        this->back = new_cell;

        size_of_queue++;
    }
}

std::string Linked_Queue::remove()
{
    // Sanity check
    if(this->is_empty())
    {
        throw std::logic_error("Can NOT remove - Queue is empty.");
    }

    // Retrieving removed data
    auto removed_data = this->front->next_cell->element->get_data();

    // Removing current head and turning first valid cell into head
    auto* aux_cell = this->front->next_cell;
    delete this->front;
    this->front = aux_cell;

    size_of_queue--;

    return removed_data;
}

int Linked_Queue::element_count() const
{
    return this->size_of_queue;
}

bool Linked_Queue::is_empty() const
{
    return (this->front == this->back);
}

void Linked_Queue::print() const
{
    auto* current_cell = this->front->next_cell;

    for(auto control {0}; control < this->element_count(); control++)
    {
        current_cell->print();

        current_cell = current_cell->next_cell;
    }
}

void Linked_Queue::clear()
{
    // Sanity Check
    if(!this->is_empty())
    {
        // Deallocating cells
        Queue_Cell* T_killer_cell {nullptr};

        for(auto control {0}; control < this->element_count(); control++)
        {
            T_killer_cell = this->front->next_cell; // Points to the cell that will be deallocated
            delete this->front;
            this->front = T_killer_cell;
        }

        // Setting Queue's variables
        this->size_of_queue = 0;
    }
}

void Linked_Queue::queue_jump(int position)
{
    // Sanity Check
    if(!this->is_empty() && position <= this->element_count() && position > 0)
    {
        // Searching for cell
        auto* interest_cell = this->front;
        auto control {0};

        while(control < position)
        {
            interest_cell = interest_cell->next_cell;

            control++;
        }

        // Removing jumper cell from between two cells (or one cell and the abyss...)
        auto* jumper = interest_cell->next_cell;
        interest_cell->next_cell = jumper->next_cell;

        // Inserting the jumper at the first position
        jumper->next_cell = this->front->next_cell;
        this->front->next_cell = jumper;
        this->back = interest_cell;
    }
    else
    {
        throw std::logic_error("ERROR: Position not valid or Queue empty");
    }
}