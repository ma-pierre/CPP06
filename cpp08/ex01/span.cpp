#include "span.hpp"

Span::Span() : _N(0), _lstNb()
{}

Span::Span(unsigned int N) : _N(N), _lstNb()
{}

Span::Span(const Span &other) : _N(other._N), _lstNb(other._lstNb)
{}

Span::~Span()
{}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_lstNb = other._lstNb;
    }
    return (*this);
}

void Span::addNumber(int nb)
{
    if (_lstNb.size() >= _N)
    {
        throw NreachedException();
    }
    _lstNb.push_back(nb);
}

int Span::longestSpan() const
{
    if (_lstNb.size() <= 1)
        throw NoSpanException();
    int min = *std::min_element(_lstNb.begin(), _lstNb.end());
    int max = *std::max_element(_lstNb.begin(), _lstNb.end());
    return (max - min);
}

int Span::shortestSpan() const
{
    if (_lstNb.size() <= 1)
        throw NoSpanException();
    std::list<int> Sorted = _lstNb;
    Sorted.sort();
    int shortest = std::numeric_limits<int>::max();
    std::list<int>::iterator i = Sorted.begin();
    std::list<int>::iterator next = ++Sorted.begin();
    while (next != Sorted.end())
    {
        int span = *next - *i;
        if (span < shortest)
            shortest = span;
        ++i;
        ++next;
    }
    return (shortest);
}

const char* Span::NreachedException::what() const throw()
{
    return ("_N limit reached, you can't add more numbers.");
}

const char* Span::NoSpanException::what() const throw()
{
    return ("No span found, you don't have enought elements in the list to look for Span");
}
