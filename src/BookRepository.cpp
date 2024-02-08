//
// Created by steam on 1/26/2024.
//



#include <utility>

#include "headers/BookRepository.h"

BookRepository::BookRepository(std::vector<BookEntry> bookEntries) : bookEntries{std::move(bookEntries)} {}

BookRepository::BookRepository() = default;

void BookRepository::addBookEntry(BookEntry newEntry) {
    for(BookEntry& entry : bookEntries) {
       if(newEntry.equals(entry)) {
           entry.setNumOfCopies(entry.getNumOfCopies() + newEntry.getNumOfCopies());
           return;
       }
    }
    bookEntries.push_back(newEntry);
}

void BookRepository::removeBooksInEntry(BookEntry &book, unsigned int numOfCopies) {
    for (auto it = bookEntries.begin(); it != bookEntries.end(); ++it) {
        auto& entry = *it;
        if(book.equals(entry)) {
            if(numOfCopies > entry.getNumOfCopies()) {
                throw std::runtime_error("Can't remove more copies than there are in stock");
            }
            entry.setNumOfCopies(entry.getNumOfCopies() - numOfCopies);
            if(entry.getNumOfCopies() == 0) {
                bookEntries.erase(it);
            }
            return;
        }
    }
}


std::vector<BookEntry> &BookRepository::getBookEntries() {
    return bookEntries;
}

void BookRepository::mergeSort(bool (*comparator)(const BookEntry &, const BookEntry &)) {
    try {
        auto start = std::chrono::steady_clock::now();
        bookEntries = mergeSort(bookEntries.begin(), bookEntries.end() - 1, comparator);
        auto end = std::chrono::steady_clock::now();
        std::cout << "Merge sort done in "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                  << " nanoseconds.\n";
    } catch(std::exception& e) {
        std::cout << "Sorting failed: " << e.what() << std::endl;
    }
}

void BookRepository::insertionSort(bool (*comparator)(const BookEntry &, const BookEntry &)) {
    try {
        auto start = std::chrono::steady_clock::now();
        bookEntries = insertionSort(bookEntries, comparator);
        auto end = std::chrono::steady_clock::now();
        std::cout << "Insertion sort done in "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                  << " nanoseconds.\n";
    } catch (std::exception& e) {
        std::cout << "Sorting failed: " << e.what() << std::endl;
    }
}

std::vector<BookEntry> BookRepository::mergeSort(
        const std::vector<BookEntry>::iterator start,
        const std::vector<BookEntry>::iterator end,
        bool (*comparator)(const BookEntry&, const BookEntry&)) {
    if (start >= end) {
        return {*end};
    }

    auto midpoint = std::distance(start, end) / 2 + start;
    std::vector<BookEntry> sortedVectorA = mergeSort(
            start,
            midpoint,
            comparator
    );
    std::vector<BookEntry> sortedVectorB = mergeSort(
            midpoint + 1,
            end,
            comparator
    );

    std::vector<BookEntry> result;
    result.reserve(sortedVectorA.size() + sortedVectorB.size());
    auto itA = sortedVectorA.begin();
    auto itB = sortedVectorB.begin();

    while (result.size() < sortedVectorA.size() + sortedVectorB.size()) {
        if (comparator(*itA, *itB)) {
            result.push_back(*itA);
            if (itA == sortedVectorA.end() - 1) {
                result.insert(result.end(), itB, sortedVectorB.end());
                continue;
            }
            itA++;
        } else {
            result.push_back(*itB);
            if (itB == sortedVectorB.end() - 1) {
                result.insert(result.end(), itA, sortedVectorA.end());
                continue;
            }
            itB++;
        }
    }
    return result;
}

std::vector<BookEntry> BookRepository::insertionSort(std::vector<BookEntry>& inputVec,
                                     bool (*comparator)(const BookEntry&, const BookEntry&)) {
    if(inputVec.size() <= 1) {
        return inputVec;
    }
    std::vector<BookEntry> resultVec;
    resultVec.reserve(inputVec.size());
    resultVec.push_back(inputVec[0]);
    for (auto inputIt = inputVec.begin() + 1; inputIt != inputVec.end(); ++inputIt) {
        auto resultIt = resultVec.end() - 1;
        if (comparator(*resultIt, *inputIt) || !comparator(*inputIt, *resultIt)) {
            resultVec.push_back(*inputIt);
        } else {
            while (resultIt >= resultVec.begin() && !comparator(*resultIt, *inputIt)) {
                --resultIt;
            }
            resultVec.insert(resultIt + 1, *inputIt);
        }
    }
    return resultVec;
}

void BookRepository::setBookEntries(std::vector<BookEntry> newEntries) {
    bookEntries = std::move(newEntries);
}

