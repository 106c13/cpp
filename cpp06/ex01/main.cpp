#include <stdint.h>
#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data d;
    d.id = 42;
    d.name = "example";

    Data* original = &d;

    uintptr_t raw = Serializer::serialize(original);

    Data* recovered = Serializer::deserialize(raw);


    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Raw integer:     " << raw << std::endl;
    std::cout << "Recovered ptr:   " << recovered << std::endl;

    if (original == recovered)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Error: pointers do not match!" << std::endl;

    std::cout << "Data: " << recovered->id << ", " << recovered->name << std::endl;


    return 0;
}

