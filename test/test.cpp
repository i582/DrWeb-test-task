#include "gtest/gtest.h"

#include "dictionary/dictionary.h"

TEST(DictionaryTest, test_SetGet)
{
    Dictionary<std::string, int> dictionary;

    const int testValue = 100;

    dictionary.Set("id", testValue);

    auto result = dictionary.Get("id");

    EXPECT_EQ(result, testValue);
}

TEST(DictionaryTest, test_IsSet)
{
    Dictionary<std::string, int> dictionary;

    const int testValue = 100;

    dictionary.Set("id", testValue);

    auto result = dictionary.IsSet("id");

    EXPECT_EQ(result, true);
}

TEST(DictionaryTest, test_Remove)
{
    Dictionary<std::string, int> dictionary;

    const int testValue = 100;

    dictionary.Set("id", testValue);

    dictionary.Remove("id");

    EXPECT_ANY_THROW(dictionary.Get("id"););
}