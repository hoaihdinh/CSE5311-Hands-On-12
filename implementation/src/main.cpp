#include <iostream>

#include "dynamic_array.hpp"

int main() {
    
    DynamicArray a = DynamicArray();

    std::cout << "Array size: " << a.length() << std::endl;
    a.print();

    std::cout << "\nInserting values 0 to 19" << std::endl;
    for(int i = 0; i < 20; i++) {
        a.append(i);
    }

    std::cout << "\nArray size: " << a.length() << std::endl;
    a.print();

    std::cout << "\nGetting item at index 2: " << a.get(2) << std::endl;

    std::cout << "\nRemoving item at index 5" << std::endl;
    a.remove(5);

    std::cout << "\nArray size: " << a.length() << std::endl;
    a.print();

    std::cout << "\nGetting item at index 5: " << a.get(5) << std::endl;

    std::cout << "\nRemoving the first 10 items..." << std::endl;
    for(int i = 0;  i < 10; i++) {
        a.remove(0);
    }

    std::cout << "\nArray size: " << a.length() << std::endl;
    a.print();

    std::cout << "\nRemoving all items" << std::endl;
    while(a.length() != 0) {
        a.remove(0);
    }

    std::cout << "\nArray size: " << a.length() << std::endl;
    a.print();

    return 0;
}