#include <iostream>

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
    if (n == 0)
        _data = NULL;
    else
        _data = new T[n]();
    _size = n;
}

template <typename T>
Array<T>::Array(const Array& src) : _data(NULL), _size(src._size)
{
    if (_size > 0)
    {
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = src._data[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template <typename T>
Array<T>&   Array<T>::operator=(const Array& src)
{
    if (this == &src)
        return (*this);
    delete[] _data;
    _size = src._size;
    if (_size == 0)
        _data = NULL;
    else
    {
        _data = new T[_size];
        for (unsigned int i = 0; i < src._size; i++)
            _data[i] = src._data[i];
    }
    return (*this);
}

template <typename T>
T&    Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw (std::out_of_range("Index out of bounds"));
    return (_data[i]);
}

template <typename T>
const T&    Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw (std::out_of_range("Index out of bounds"));
    return (_data[i]);
}

template <typename T>
unsigned int    Array<T>::size() const
{
    return (_size);
}
