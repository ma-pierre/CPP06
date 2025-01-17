#include "PmergeMe.hpp"


void printVector(const std::vector<unsigned int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printDeque(const std::deque<unsigned int> &deq)
{
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<unsigned int> calculateJacobsthal(size_t size)
{
    std::vector<unsigned int> jacobsthal;
    jacobsthal.push_back(0);
    if (size > 1)
        jacobsthal.push_back(1);

    for (size_t i = 2; i < size; i++) {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    }

    return (jacobsthal);
}

// Récursivité pour trier les "high" (vecteur)
void recursiveSortHighVector(std::vector<unsigned int> &high) {
    if (high.size() <= 1) return;

    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    std::vector<unsigned int> unpaired;

    for (size_t i = 0; i + 1 < high.size(); i += 2) {
        pairs.push_back(std::make_pair(std::min(high[i], high[i + 1]), std::max(high[i], high[i + 1])));
    }

    if (high.size() % 2 != 0) {
        unpaired.push_back(high.back());
    }

    std::vector<unsigned int> newHigh;
    for (size_t i = 0; i < pairs.size(); i++) {
        newHigh.push_back(pairs[i].second);
    }

    recursiveSortHighVector(newHigh);
    high = newHigh;

    std::vector<unsigned int> jacobsthal = calculateJacobsthal(pairs.size());
    for (size_t i = 0; i < pairs.size(); i++) {
        unsigned int lowElement = pairs[i].first;
        high.insert(std::lower_bound(high.begin(), high.end(), lowElement), lowElement);
    }

    for (size_t i = 0; i < unpaired.size(); i++) {
        high.insert(std::lower_bound(high.begin(), high.end(), unpaired[i]), unpaired[i]);
    }
}

// Récursivité pour trier les "high" (deque)
void recursiveSortHighDeque(std::deque<unsigned int> &high) {
    if (high.size() <= 1) return;

    std::deque<std::pair<unsigned int, unsigned int> > pairs;
    std::deque<unsigned int> unpaired;

    for (size_t i = 0; i + 1 < high.size(); i += 2) {
        pairs.push_back(std::make_pair(std::min(high[i], high[i + 1]), std::max(high[i], high[i + 1])));
    }

    if (high.size() % 2 != 0) {
        unpaired.push_back(high.back());
    }

    std::deque<unsigned int> newHigh;
    for (size_t i = 0; i < pairs.size(); i++) {
        newHigh.push_back(pairs[i].second);
    }

    recursiveSortHighDeque(newHigh);
    high = newHigh;

    std::vector<unsigned int> jacobsthal = calculateJacobsthal(pairs.size());
    for (size_t i = 0; i < pairs.size(); i++) {
        unsigned int lowElement = pairs[i].first;
        high.insert(std::lower_bound(high.begin(), high.end(), lowElement), lowElement);
    }

    for (size_t i = 0; i < unpaired.size(); i++) {
        high.insert(std::lower_bound(high.begin(), high.end(), unpaired[i]), unpaired[i]);
    }
}

// Tri principal pour les vecteurs
void sortVector(std::vector<unsigned int> &arr) {
    recursiveSortHighVector(arr);
}

// Tri principal pour les deques
void sortDeque(std::deque<unsigned int> &arr) {
    recursiveSortHighDeque(arr);
}
