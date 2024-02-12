//
// Created by Michał Kuć on 18/12/2023.
//

#ifndef LIBRARY_BOOKENTRY_H
#define LIBRARY_BOOKENTRY_H
#include "Genre.h"

#include <string>
#include <set>
#include <sstream>

class BookEntry {
private:
    std::string title, author;
    unsigned int numOfPages, releaseYear, numOfCopies;
    std::set<Genre> genres;
public:
    void setTitle(const std::string &newTitle);

    void setAuthor(const std::string &newAuthor);

    void setNumOfPages(unsigned int newNumOfPages);

    void setReleaseYear(unsigned int newReleaseYear);

    void setNumOfCopies(unsigned int newNumOfCopies);

    void setGenres(const std::set<Genre> &newGenres);

    BookEntry(std::string title, std::string author, unsigned int numOfPages, unsigned int releaseYear, unsigned int numOfCopies, std::set<Genre> genres);

    BookEntry();

    std::string toString();


    const std::string &getTitle() const;

    const std::string &getAuthor() const;

    unsigned int getNumOfPages() const;

    unsigned int getReleaseYear() const;

    const unsigned int & getNumOfCopies() const;

    std::set<Genre> &getGenres();

    bool equals(BookEntry& book);

    static bool compareTitle(const BookEntry &entryA, const BookEntry &entryB);

    static bool compareAuthor(const BookEntry &entryA, const BookEntry &entryB);

    static bool compareNumOfPages(const BookEntry &entryA, const BookEntry &entryB);
    
    static bool compareReleaseYear(const BookEntry &entryA, const BookEntry &entryB);
    
    static bool compareNumOfCopies(const BookEntry &entryA, const BookEntry &entryB);


};


#endif //LIBRARY_BOOKENTRY_H
