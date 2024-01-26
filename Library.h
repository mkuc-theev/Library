//
// Created by steam on 1/26/2024.
//

#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

#include "Book.h"
#include <vector>
#include <functional>


struct BookEntry {
    Book book;
    unsigned int numOfCopies;
};

class Library {
private:

    std::vector<BookEntry> bookEntries;

    template<typename T>
    const Book& compareByField(const Book& bookA, const Book& bookB, T fieldToCompare);

    std::vector<BookEntry> mergeSort();
    std::vector<BookEntry> insertionSort();

public:
    explicit Library (std::vector<BookEntry> bookEntries);
    Library();
    std::string toString();
    template<typename T>
    void sortBy(T field, const std::function<std::vector<BookEntry>()>& sortingAlgorithm);
    void addBook(Book book, unsigned int numOfCopies);
    void removeBook(const Book& book);
    void editBook(const Book& book);

    const std::vector<BookEntry> &getBookEntries() const;
};


#endif //LIBRARY_LIBRARY_H
