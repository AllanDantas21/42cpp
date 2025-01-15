#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data(42);

	std::cout << "Data Structure Adress: " << &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized Data: " << raw << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data Adress: " << ptr << std::endl;
	return 0;
};