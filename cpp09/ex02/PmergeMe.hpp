#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

// Fonctions d'impression
void printVector(const std::vector<unsigned int> &vec);
void printDeque(const std::deque<unsigned int> &deq);

// Algorithme Ford-Johnson
void sortVector(std::vector<unsigned int> &arr);
void sortDeque(std::deque<unsigned int> &arr);

// Outils d'insertion et de tri
std::vector<unsigned int> calculateJacobsthal(size_t size);
void recursiveSortHighVector(std::vector<unsigned int> &high);
void recursiveSortHighDeque(std::deque<unsigned int> &high);

#endif
