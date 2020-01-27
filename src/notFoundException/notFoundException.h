#pragma once

template<typename TKey>
class NotFoundException : public std::exception
{
public:
    explicit NotFoundException(const TKey& key_) noexcept;
    ~NotFoundException() noexcept override = default;
    
public:
    /**
     * @brief The function that returns the key for which an exception was raised.
     * @return The key for which the exception was thrown.
     */
    const TKey& GetKey() const noexcept;


private:
    TKey key;

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
