#pragma once

template<typename TKey>
class NotFoundException : public std::exception
{
private:
    TKey key;

public:
    explicit NotFoundException(const TKey& key_) noexcept;
    ~NotFoundException() noexcept override = default;

public:
    const TKey& GetKey() const noexcept;

};

template<typename TKey>
NotFoundException<TKey>::NotFoundException(const TKey& key_) noexcept
{
    this->key = key_;
}

template<typename TKey>
const TKey& NotFoundException<TKey>::GetKey() const noexcept
{
    return key;
}
