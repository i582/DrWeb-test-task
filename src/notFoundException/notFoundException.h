#pragma once

#include "notFoundException_interface.h"

template<typename TKey>
class MyNotFoundException : public NotFoundException<TKey>
{
private:
	TKey key;

public:
	explicit MyNotFoundException(const TKey& key) noexcept;
	~MyNotFoundException() noexcept = default;

public:
	const TKey& GetKey() const noexcept;

};




template<typename TKey>
MyNotFoundException<TKey>::MyNotFoundException(const TKey& key) noexcept
{
	this->key = key;
}

template<typename TKey>
const TKey& MyNotFoundException<TKey>::GetKey() const noexcept
{
	return key;
}
