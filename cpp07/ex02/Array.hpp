#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    T* _array;
    unsigned int _size; //changer unsigned pour proteger l'inferieur a 0 manuellement ?

    public:

    Array() : _array(NULL), _size(0) {}
    Array(unsigned int size) : _array(new T[size]())
}