//
// Created by steam on 1/26/2024.
//

#ifndef LIBRARY_BOOKREPOSITORY_H
#define LIBRARY_BOOKREPOSITORY_H

#include "BookEntry.h"
#include <chrono>
#include <vector>
#include <regex>
#include <functional>

class BookRepository {
private:
    std::vector<BookEntry> bookEntries;

    std::vector<BookEntry> mergeSort(
            std::vector<BookEntry>::iterator start,
            std::vector<BookEntry>::iterator end,
            bool (*comparator)(const BookEntry&, const BookEntry&));
    static std::vector<BookEntry> insertionSort(
            std::vector<BookEntry>& inputVec,
            bool (*comparator)(const BookEntry&, const BookEntry&));
public:
    explicit BookRepository (std::vector<BookEntry> bookEntries);
    BookRepository();
    void addBookEntry(BookEntry newEntry);
    void removeBooksInEntry(BookEntry &book, unsigned int numOfCopies);
    void mergeSort(bool (*comparator)(const BookEntry&, const BookEntry&));
    void insertionSort(bool (*comparator)(const BookEntry &, const BookEntry &));
    std::vector<BookEntry> &getBookEntries();
    void setBookEntries(std::vector<BookEntry> newEntries);

};


#endif //LIBRARY_BOOKREPOSITORY_H
