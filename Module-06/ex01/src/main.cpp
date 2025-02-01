#include "../include/Serializer.hpp"

int main(void) {
     
    Data *data = new Data;
    data->age = 42;
    data->grade = 100;
    data->name = "Alice";
    data->isStudent = true;

    std::cout << "Pointer data value: " << data << std::endl;
    uintptr_t serializedData = Serializer::serialize(data);
    std::cout << "Serialized value: " << serializedData << std::endl;

    Data *deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized value: " << deserializedData << std::endl;
    std::cout << "Deserialized age: " << deserializedData->age << std::endl;
    std::cout << "Deserialized grade: " << deserializedData->grade << std::endl;
    std::cout << "Deserialized name: " << deserializedData->name << std::endl;
    std::cout << "Deserialized isStudent: " << deserializedData->isStudent << std::endl;

    delete data;

    return 0;
}