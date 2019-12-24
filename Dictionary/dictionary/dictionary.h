#pragma once
#include <map>

#include "dictionary_interface.h"
#include "notFoundException/notFoundException.h"

using std::map;

template<typename TKey, typename TValue>
class MyDictionary : public Dictionary<TKey, TValue>
{
private:
	map<TKey, TValue> _dictionary;

public:
	MyDictionary() = default;

public:
	const TValue& Get(const TKey& key) const;
	void Set(const TKey& key, const TValue& value);
	bool IsSet(const TKey& key) const;
	void Remove(const TKey& key);

};

template<typename TKey, typename TValue>
const TValue& MyDictionary<TKey, TValue>::Get(const TKey& key) const
{
	if (IsSet(key))
	{ 
		return _dictionary.at(key);
	}
	else
	{
		throw MyNotFoundException<TKey>(key);
	}
}

template<typename TKey, typename TValue>
void MyDictionary<TKey, TValue>::Set(const TKey& key, const TValue& value)
{
	_dictionary[key] = value;
}

template<typename TKey, typename TValue>
bool MyDictionary<TKey, TValue>::IsSet(const TKey& key) const
{
	return _dictionary.find(key) != _dictionary.end();
}

template<typename TKey, typename TValue>
void MyDictionary<TKey, TValue>::Remove(const TKey& key)
{
	if (IsSet(key))
	{
		_dictionary.erase(key);
	}
	else
	{
		throw MyNotFoundException<TKey>(key);
	}
}
