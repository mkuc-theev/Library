//
// Created by Michał Kuć on 18/12/2023.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include "Genre.h"

#include <string>
#include <set>
#include <sstream>

class Book {
private:
    std::string title, author;
    unsigned int numOfPages, releaseYear;
    std::set<Genre> genres;
public:
    Book(std::string title, std::string author, unsigned int numOfPages, unsigned int releaseYear, std::set<Genre> genres);
    std::string toString(bool singleLine);

    const std::string &getTitle() const;

    const std::string &getAuthor() const;

    unsigned int getNumOfPages() const;

    unsigned int getReleaseYear() const;

    const std::set<Genre> &getGenres() const;
};


#endif //LIBRARY_BOOK_H
