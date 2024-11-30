// PmergeMe.hpp
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

void printVector(const std::vector<unsigned int> &vec);
void printDeque(const std::deque<unsigned int> &deq);
void sortVector(std::vector<unsigned int> &arr);
void sortDeque(std::deque<unsigned int> &arr);
void insertionSort(std::vector<unsigned int> &arr);
void insertionSort(std::deque<unsigned int> &arr);
std::vector<std::pair<unsigned int, unsigned int> > createPairsVector(const std::vector<unsigned int> &arr);
void insertLowDeque(std::deque<unsigned int> &high, const std::deque<std::pair<unsigned int, unsigned int> > &pairs);
std::deque<std::pair<unsigned int, unsigned int> > createPairsDeque(const std::deque<unsigned int> &arr);
std::vector<unsigned int> sortHighVector(const std::vector<std::pair<unsigned int, unsigned int> > &pairs);
std::deque<unsigned int> sortHighDeque(const std::deque<std::pair<unsigned int, unsigned int> > &pairs);
void insertLastElementVector(std::vector<unsigned int> &high, unsigned int lastElement);
void insertLastElementDeque(std::deque<unsigned int> &high, unsigned int lastElement);

#endif