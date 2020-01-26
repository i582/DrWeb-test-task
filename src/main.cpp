#include <iostream>
#include <string>

#include "dictionary/dictionary.h"

int main()
{
    Dictionary<std::string, int> dictionary;

    dictionary.Set("id", 100);

    const std::string key = "id";

    try
    {
        int value = dictionary.Get(key);
        std::cout << "Value with key = " << key << " equal " << value << std::endl;

        dictionary.Remove(key);
        value = dictionary.Get(key);
    }
    catch (const NotFoundException<std::string>& e)
    {
        const auto& errorKey = e.GetKey();

        std::cout << "Error! Key \"" << errorKey << "\" not found!" << std::endl;
    }

    return 0;
}
