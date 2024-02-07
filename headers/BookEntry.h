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
    void setTitle(const std::string &title);

    void setAuthor(const std::string &author);

    void setNumOfPages(unsigned int numOfPages);

    void setReleaseYear(unsigned int releaseYear);

    void setNumOfCopies(unsigned int numOfCopies);

    void setGenres(const std::set<Genre> &genres);

    BookEntry(std::string title, std::string author, unsigned int numOfPages, unsigned int releaseYear, unsigned int numOfCopies, std::set<Genre> genres);

    std::string toString();


    const std::string &getTitle() const;

    const std::string &getAuthor() const;

    unsigned int getNumOfPages() const;

    unsigned int getReleaseYear() const;

    const unsigned int & getNumOfCopies() const;

    const std::set<Genre> &getGenres() const;

    bool equals(const BookEntry& book);

    static bool compareTitle(const BookEntry &entryA, const BookEntry &entryB);

    static bool compareAuthor(const BookEntry &entryA, const BookEntry &entryB);

    static bool compareNumOfPages(const BookEntry &entryA, const BookEntry &entryB);
    
    static bool compareReleaseYear(const BookEntry &entryA, const BookEntry &entryB);
    
    static bool compareNumOfCopies(const BookEntry &entryA, const BookEntry &entryB);


};


#endif //LIBRARY_BOOKENTRY_H
