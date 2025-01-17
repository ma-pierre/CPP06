#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    std::vector<unsigned int> numbersVector;
    std::deque<unsigned int> numbersDeque;
    clock_t start;
    clock_t end;
    double vectorTime;
    double dequeTime;

    if (argc < 2) {
        std::cerr << "Error: Please provide at least one positive integer." << std::endl;
        return (1);
    }

    try {
        for (int i = 1; i < argc; i++) {
            long num = std::atol(argv[i]);
            if (num < 0 || num > INT_MAX) {
                throw std::invalid_argument("Input must be a positive integer within range.");
            }
            numbersVector.push_back(static_cast<unsigned int>(num));
            numbersDeque.push_back(static_cast<unsigned int>(num));
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    std::cout << "Before: ";
    printVector(numbersVector);

    start = clock();
    sortVector(numbersVector);
    end = clock();
    vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    sortDeque(numbersDeque);
    end = clock();
    dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    printVector(numbersVector);

    std::cout << "Time to process a range of " << numbersVector.size()
              << " elements with std::vector : " << vectorTime << " microseconds" << std::endl;
    std::cout << "Time to process a range of " << numbersDeque.size()
              << " elements with std::deque : " << dequeTime << " microseconds" << std::endl;

    return (0);
}
