
#include "PmergeMe.hpp"

void printVector(const std::vector<unsigned int> &vec)
{
    size_t i;
    i = 0;
    while (i < vec.size())
    {
        std::cout << vec[i] << " ";
        i++;
    }
    std::cout << std::endl;
}
void insertionSort(std::vector<unsigned int> &arr)
{
    size_t i, j;
    unsigned int key;
    for (i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
void insertionSort(std::deque<unsigned int> &arr)
{
    size_t i, j;
    unsigned int key;
    for (i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

void printDeque(const std::deque<unsigned int> &deq)
{
    size_t i;
    i = 0;
    while (i < deq.size())
    {
        std::cout << deq[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

std::vector<std::pair<unsigned int, unsigned int> > createPairsVector(const std::vector<unsigned int> &arr)
{
    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    size_t i;
    i = 0;
    while ((i + 1) < arr.size()) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        } else {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
        i += 2;
    }
    return (pairs);
}

std::deque<std::pair<unsigned int, unsigned int> > createPairsDeque(const std::deque<unsigned int> &arr) {
    std::deque<std::pair<unsigned int, unsigned int> > pairs;
    size_t i;
    i = 0;
    while ((i + 1) < arr.size()) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        } else {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
        i += 2;
    }
    return (pairs);
}

std::vector<unsigned int> sortHighVector(const std::vector<std::pair<unsigned int, unsigned int> > &pairs) {
    std::vector<unsigned int> high;
    size_t i;
    i = 0;
    while (i < pairs.size()) {
        high.push_back(pairs[i].second);
        i++;
    }
    insertionSort(high);
    return (high);
}

std::deque<unsigned int> sortHighDeque(const std::deque<std::pair<unsigned int, unsigned int> > &pairs) {
    std::deque<unsigned int> high;
    size_t i;
    i = 0;
    while (i < pairs.size()) {
        high.push_back(pairs[i].second);
        i++;
    }
    insertionSort(high);
    return (high);
}

void insertLowVector(std::vector<unsigned int> &high, const std::vector<std::pair<unsigned int, unsigned int> > &pairs) {
    size_t i;
    i = 0;
    while (i < pairs.size()) {
        unsigned int lowElement = pairs[i].first;
        std::vector<unsigned int>::iterator pos = std::lower_bound(high.begin(), high.end(), lowElement);
        high.insert(pos, lowElement);
        i++;
    }
}

void insertLowDeque(std::deque<unsigned int> &high, const std::deque<std::pair<unsigned int, unsigned int> > &pairs)
{
    size_t i;
    i = 0;
    while (i < pairs.size()) {
        unsigned int lowElement = pairs[i].first;
        std::deque<unsigned int>::iterator pos = std::lower_bound(high.begin(), high.end(), lowElement);
        high.insert(pos, lowElement);
        i++;
    }
}

void insertLastElementVector(std::vector<unsigned int> &high, unsigned int lastElement)
{
    std::vector<unsigned int>::iterator pos = std::lower_bound(high.begin(), high.end(), lastElement);
    high.insert(pos, lastElement);
}

void insertLastElementDeque(std::deque<unsigned int> &high, unsigned int lastElement)
{
    std::deque<unsigned int>::iterator pos = std::lower_bound(high.begin(), high.end(), lastElement);
    high.insert(pos, lastElement);
}

void sortVector(std::vector<unsigned int> &arr)
{
    bool odd;
    unsigned int lastElement;
    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    std::vector<unsigned int> high;

    odd = (arr.size() % 2 != 0);
    if (odd) {
        lastElement = arr.back();
    }
    pairs = createPairsVector(arr);
    high = sortHighVector(pairs);
    insertLowVector(high, pairs);
    if (odd) {
        insertLastElementVector(high, lastElement);
    }
    arr = high;
}

void sortDeque(std::deque<unsigned int> &arr)
{
    bool odd;
    unsigned int lastElement;
    std::deque<std::pair<unsigned int, unsigned int> > pairs;
    std::deque<unsigned int> high;

    odd = (arr.size() % 2 != 0);
    if (odd) {
        lastElement = arr.back();
    }
    pairs = createPairsDeque(arr);
    high = sortHighDeque(pairs);
    insertLowDeque(high, pairs);
    if (odd) {
        insertLastElementDeque(high, lastElement);
    }
    arr = high;
}
