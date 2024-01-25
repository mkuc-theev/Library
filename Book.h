//
// Created by Michał Kuć on 18/12/2023.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include "Genre.h"

#include <string>
#include <set>

class Book {
private:
    std::string title, author;
    unsigned int numOfPages, releaseYear;
    std::set<Genre> genres;
public:
    Book(std::string title, std::string author, unsigned int numOfPages, unsigned int releaseYear, std::set<Genre> genres);
    std::string toString(bool singleLine);
};


#endif //LIBRARY_BOOK_H
