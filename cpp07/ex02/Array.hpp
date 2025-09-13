#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array {
private:
    T*              _data;
    unsigned int    _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;

	class OutOfBoundsException : public std::exception
	{
		public: const char* what() const throw();
	};

};

#include "Array.tpp"

#endif

