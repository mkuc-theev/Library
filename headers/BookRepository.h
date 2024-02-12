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
public:
    explicit BookRepository(std::vector<BookEntry> bookEntries);

    BookRepository();

    void addBookEntry(BookEntry newEntry);

    bool changeNumOfCopies(BookEntry &book, int numOfCopies);

    std::vector<BookEntry> &getBookEntries();

    void setBookEntries(std::vector<BookEntry> newEntries);

    static std::vector<BookEntry> mergeSort(
            std::vector<BookEntry>::iterator start,
            std::vector<BookEntry>::iterator end,
            bool (*comparator)(const BookEntry &, const BookEntry &));

    static std::vector<BookEntry> insertionSort(
            std::vector<BookEntry> &inputVec,
            bool (*comparator)(const BookEntry &, const BookEntry &));

};


#endif //LIBRARY_BOOKREPOSITORY_H
