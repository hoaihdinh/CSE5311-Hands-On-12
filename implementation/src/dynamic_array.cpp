#include <iostream>
#include <stdexcept>

#include "dynamic_array.hpp"

DynamicArray::DynamicArray() {
    capacity = 1;
    size = 0;
    items = new int[capacity];   
}

DynamicArray::~DynamicArray() {
    delete items;
}

int DynamicArray::length() {
    return size;
}

void DynamicArray::resize(double factor) {
    capacity *= factor;

    int *new_items = new int[capacity];

    for(int i = 0; i < size; i++) {
        new_items[i] = items[i];
    }

    delete items;

    items = new_items;
}

int DynamicArray::get(int index) {
    if(index > size) {
        throw std::invalid_argument("Index out of bounds\n");
    }

    return items[index];
}

void DynamicArray::append(int item) {
    if(size == capacity) {
        resize(2);
    }

    items[size] = item;
    size++;
}

void DynamicArray::remove(int index) {
    if(index >= size) {
        throw std::invalid_argument("Index out of bounds\n");
    }

    size -= 1;

    for(int i = index; i < size; i++) {
        items[i] = items[i + 1];
    }

    if( static_cast<double>(size) / capacity <= static_cast<double>(1)/4 ) {
        resize(static_cast<double>(1/2));
    }
}


void DynamicArray::print() {
    if(size == 0) {
        std::cout << "Array is empty!" << std::endl;
    } else {
        std::cout << "Array Data: {";
    
        for(int i = 0; i < size; i++) {
            std::cout << items[i] << ((i == size - 1) ? "" : ", ");
        }
        std::cout << "}" << std::endl;
    }

}
