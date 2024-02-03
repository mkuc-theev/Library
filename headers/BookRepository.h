//
// Created by steam on 1/26/2024.
//

#ifndef LIBRARY_BOOKREPOSITORY_H
#define LIBRARY_BOOKREPOSITORY_H

#include "BookEntry.h"
#include "headers/RepositorySorter.h"
#include <chrono>
#include <vector>
#include <functional>

class BookRepository {
private:
    std::vector<BookEntry> bookEntries;
public:
    explicit BookRepository (std::vector<BookEntry> bookEntries);
    BookRepository();
    std::string toString();
    void addBookEntry(BookEntry newEntry);
    void removeBookEntry(BookEntry &book, unsigned int numOfCopies);
    void mergeSort(bool (*comparator)(const BookEntry&, const BookEntry&));
    const std::vector<BookEntry> &getBookEntries() const;
};


#endif //LIBRARY_BOOKREPOSITORY_H
