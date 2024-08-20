#ifndef ARRAY_HPP
#define ARRAY_HPP

#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;214m"
#define PINK "\033[38;5;200m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    Array();
    Array(unsigned int sz);
    Array(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);
    T& operator[](unsigned int index);
    unsigned int size() const;
    ~Array();
};

template <typename T>
Array<T>::Array() : _array(0), _size(0)
{
    std::cout << YELLOW << "Array default constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int sz) : _size(sz)
{
    _array = new T[sz];
    for (unsigned int i = 0; i < sz; i++)
        _array[i] = T();
    std::cout << YELLOW << "Array Constructor with size parameter called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size)
{
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
    std::cout << YELLOW << "Array copy constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
    std::cout << RED << "Destructor called for Array, the array is destroyed" << RESET << std::endl;
}

#endif
