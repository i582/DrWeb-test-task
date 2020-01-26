#pragma once
#include <map>

#include "notFoundException/notFoundException.h"

template<typename TKey, typename TValue>
class Dictionary
{
private:
	std::map<TKey, TValue> _dictionary;

public:
    Dictionary() = default;

public:
	const TValue& Get(const TKey& key) const;
	void Set(const TKey& key, const TValue& value);
	bool IsSet(const TKey& key) const;
	void Remove(const TKey& key);

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