//
// Created by steam on 1/26/2024.
//

#ifndef LIBRARY_BOOKREPOSITORY_H
#define LIBRARY_BOOKREPOSITORY_H

#include "BookEntry.h"
#include "headers/RepositorySorter.h"
#include <chrono>
#include <vector>
#include <regex>
#include <functional>

class BookRepository {
private:
    std::vector<BookEntry> bookEntries;
public:
    explicit BookRepository (std::vector<BookEntry> bookEntries);
    BookRepository();
    std::string toString();
    void addBookEntry(BookEntry newEntry);
    void removeBooksInEntry(BookEntry &book, unsigned int numOfCopies);
    std::vector<BookEntry *> searchInBookEntries(const std::string& query);
    void mergeSort(bool (*comparator)(const BookEntry&, const BookEntry&));
    void insertionSort(bool (*comparator)(const BookEntry &, const BookEntry &));
    const std::vector<BookEntry> &getBookEntries() const;
};


#endif //LIBRARY_BOOKREPOSITORY_H
