#include <iostream>
#include <string>

#include "dictionary/dictionary.h"

int main()
{
	MyDictionary<std::string, int> dictionary;

	dictionary.Set("id", 100);

	const std::string key = "id";

	try
	{
		int value = dictionary.Get(key);
		std::cout << "Value with key = " << key << " equal " << value << std::endl;

		dictionary.Remove(key);
		value = dictionary.Get(key);
	}
	catch (const MyNotFoundException<std::string>& e)
	{
		const auto& result_key = e.GetKey();

		std::cout << "Error! Key \"" << result_key << "\" not found!" << std::endl;
	}

	return 0;
}
