#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;214m"
#define PINK "\033[38;5;200m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    MutantStack();
    MutantStack(const MutantStack<T>& other);
    ~MutantStack();

    MutantStack<T>& operator=(const MutantStack<T>& other);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << RED << "default constructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {
    std::cout << RED << "copy constructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << RED << "destructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    std::cout << RED << "assignment operator called" << RESET << std::endl;
    return(*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    std::cout << RED << "begin() called" << RESET << std::endl;
    return(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    std::cout << RED << "end() called" << RESET << std::endl;
    return(this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    std::cout << RED << "const begin() called" << RESET << std::endl;
    return(this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    std::cout << RED << "const end() called" << RESET << std::endl;
    return(this->c.end());
}

#endif
