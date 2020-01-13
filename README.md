# Dictionary — test task for DrWeb for Junior C ++ position

A simple wrapper class over a standard map with the following interface:

```cpp
~Dictionary() = default;

const TValue& Get(const TKey& key) const;
void Set(const TKey& key, const TValue& value);
void Remove(const TKey& key); 
bool IsSet(const TKey& key) const;
```


And capable of throwing exceptions with the following interface:

```cpp
const TKey& GetKey() const noexcept;
```

## Original task (Russian):

Необходимо реализовать класс контейнера, реализующий интерфейс `Dictionary` и способный выбросить исключение, реализующее интерфейс `NotFoundException`. 
При разработке допускается использовать STL. Кроме этого, внутренняя реализация ничем не ограничена.

```cpp
template<class TKey, class TValue>
class Dictionary
{
public:
  virtual ~Dictionary() = default;

  virtual const TValue& Get(const TKey& key) const = 0;
  virtual void Set(const TKey& key, const TValue& value) = 0;
  virtual void Remove(const TKey& key) = 0;
  virtual bool IsSet(const TKey& key) const = 0;
};
```
```cpp
template<class TKey>
class NotFoundException : public std::exception
{
public:
  virtual const TKey& GetKey() const noexcept = 0;
};
```