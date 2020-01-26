# Dictionary — test task for DrWeb for Junior C++ position

## Task

Need to implement a container class that implements the `Dictionary` interface and is able to throw an exception that implements the `NotFoundException` interface. During development it is allowed to use `STL`. In addition, the internal implementation is not limited by anything.

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


## Additionally

Here I will provide some links to my projects for the convenience of transition to them.

1. [`component-sdl2`](https://github.com/i582/component-sdl2) — is a small cross-platform library for creating interfaces created on the basis of the low-level graphics library SDL2. It supports the complete customization of the appearance of components using `css`, as well as the simple creation of custom components of any complexity.

2. [`table-winapi`](https://github.com/i582/HLProgramming/tree/new/4/tables-1/tables-1) — a small abstraction for tables in `WinAPI` and some other things, as well as working with `CSV`.