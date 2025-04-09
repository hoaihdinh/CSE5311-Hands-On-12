#pragma once

class DynamicArray {
    private: 
        int *items;
        int capacity;
        int size;
        void resize(double factor);
    
    public:
        DynamicArray();
        ~DynamicArray();

        int  length();
        int  get(int index);
        void append(int item);
        void remove(int index);
        void print();
};