#pragma once

#include <map>

#include "notFoundException/notFoundException.h"

template<typename TKey, typename TValue>
class Dictionary
{
public:
    Dictionary() = default;

public:
    /**
     * @brief The function to get the value by its key.
     * @param key The key by which to find the value.
     * @return The value for the given key.
     *
     * @throw If there is no such pair in the dictionary, a NotFoundException
     * exception will be raised for which, using the GetKey method, you can
     * get the key for which the exception occurred.
     */
    const TValue& Get(const TKey& key) const;

    /**
     * @brief The function to set the key value.
     * @param key The key by which you can get the value.
     * @param value The value that will be bound to the key, and which can be obtained by the key.
     */
    void Set(const TKey& key, const TValue& value);

    /**
     * @brief The function that checks whether a dictionary contains a value for a given key.
     * @param key The key to check.
     * @return True, if a key-value pair exists and false otherwise.
     */
    bool IsSet(const TKey& key) const;

    /**
     * @brief The function that removes a key-value pair from a dictionary.
     * @param key The key of the pair to be deleted.
     *
     * @throw If there is no such pair in the dictionary, a NotFoundException
     * exception will be raised for which, using the GetKey method, you can
     * get the key for which the exception occurred.
     */
    void Remove(const TKey& key);

private:
    std::map<TKey, TValue> _dictionary;


};

template<typename TKey, typename TValue>
const TValue& Dictionary<TKey, TValue>::Get(const TKey& key_) const
{
    if (IsSet(key_))
    {
        return _dictionary.at(key_);
    }
    else
    {
        throw NotFoundException<TKey>(key_);
    }
}

template<typename TKey, typename TValue>
void Dictionary<TKey, TValue>::Set(const TKey& key_, const TValue& value_)
{
    _dictionary[key_] = value_;
}

template<typename TKey, typename TValue>
bool Dictionary<TKey, TValue>::IsSet(const TKey& key_) const
{
    return _dictionary.find(key_) != _dictionary.end();
}

template<typename TKey, typename TValue>
void Dictionary<TKey, TValue>::Remove(const TKey& key_)
{
    if (IsSet(key_))
    {
        _dictionary.erase(key_);
    }
    else
    {
        throw NotFoundException<TKey>(key_);
    }
}