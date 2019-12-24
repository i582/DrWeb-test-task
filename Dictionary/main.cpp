#include <iostream>
#include <string>

#include "dictionary/dictionary.h"

int main()
{
	MyDictionary<std::string, int> dictionary;

	dictionary.Set("id", 100);

	const std::string key = "classname";

	try
	{
		int value = dictionary.Get(key);
		std::cout << "Value with key = " << key << " equal " << value << std::endl;
	}
	catch (const MyNotFoundException<std::string>& e)
	{
		auto key = e.GetKey();

		std::cout << "Error! Key \"" << key << "\" not found!" << std::endl;
	}

	return 0;
}
