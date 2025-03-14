#include "Serializer.hpp"
#include "colors.h"
#include <iostream>

int main() {
    Data myData;
    myData.id = 42;
    myData.name = "Salut comment ça va?";

    std::cout << CYAN << "Original Data Address: " << &myData << RESET << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << YELLOW << "Serialized Value: " << raw << RESET << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << MAGENTA << "Deserialized Address: " << deserializedData << RESET << std::endl;

    if (deserializedData == &myData) {
        std::cout << GREEN << BOLD << "Success: Deserialization is correct!" << RESET << std::endl;
        std::cout << BLUE << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << RESET << std::endl;
    } else {
        std::cout << RED << BOLD << "Error: Deserialization failed!" << RESET << std::endl;
    }

    return 0;
}
