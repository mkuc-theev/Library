//
// Created by steam on 1/26/2024.
//

#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

#include "BookEntry.h"
#include <vector>
#include <functional>

class Library {
private:
    std::vector<BookEntry> bookEntries;

    std::vector<BookEntry> mergeSort();
    std::vector<BookEntry> insertionSort();
public:
    explicit Library (std::vector<BookEntry> bookEntries);
    Library();
    std::string toString();
    void addBookEntry(BookEntry newEntry);
    void removeBookEntry(BookEntry &book, unsigned int numOfCopies);
    void editBookEntry(const BookEntry& book);

    const std::vector<BookEntry> &getBookEntries() const;
};


#endif //LIBRARY_LIBRARY_H
