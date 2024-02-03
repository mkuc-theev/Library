//
// Created by Michał Kuć on 18/12/2023.
//

#include "headers/BookEntry.h"
#include <utility>
#include <sstream>

BookEntry::BookEntry(std::string title, std::string author, unsigned int numOfPages, unsigned int releaseYear, unsigned int numOfCopies,
                     std::set<Genre> genres) {
    this -> title = std::move(title);
    this -> author = std::move(author);
    this -> numOfPages = numOfPages;
    this -> releaseYear = releaseYear;
    this -> numOfCopies = numOfCopies;
    this -> genres = std::move(genres);
}

std::string BookEntry::toString(bool singleLine) {
    std::stringstream ss;
    if (singleLine) {
        ss << "\"" << title << "\" by " << author << " (" << releaseYear << ")\n";
    } else {
        ss << "{ " << std::endl
           << "    Title: \"" << title << "\"," << std::endl
           << "    Author: " << author << ',' << std::endl
           << "    Number of pages: " << numOfPages << ',' << std::endl
           << "    Release year: " << releaseYear << ',' << std::endl
           << "    Number of copies: " << numOfCopies << ',' << std::endl
           << "    Genres: [ ";
        std::set<Genre>::iterator itr;
        for (itr = genres.begin(); itr != genres.end(); ++itr) {
            ss << GenreToString(*itr) << (itr == --genres.end() ? " " : ", ");
        }
        ss << "]\n}\n";
    }
    return ss.str();
}

const std::string &BookEntry::getTitle() const {
    return title;
}

const std::string &BookEntry::getAuthor() const {
    return author;
}

unsigned int BookEntry::getNumOfPages() const {
    return numOfPages;
}

unsigned int BookEntry::getReleaseYear() const {
    return releaseYear;
}

const unsigned int & BookEntry::getNumOfCopies() const {
    return numOfCopies;
}

const std::set<Genre> &BookEntry::getGenres() const {
    return genres;
}

bool BookEntry::equals(const BookEntry &book) {
    return (
            title == book.getTitle() &&
            author == book.getAuthor() &&
            numOfPages == book.getNumOfPages() &&
            releaseYear == book.getReleaseYear() &&
            genres == book.getGenres()
            );
}

void BookEntry::setTitle(const std::string &title) {
    BookEntry::title = title;
}

void BookEntry::setAuthor(const std::string &author) {
    BookEntry::author = author;
}

void BookEntry::setNumOfPages(unsigned int numOfPages) {
    BookEntry::numOfPages = numOfPages;
}

void BookEntry::setReleaseYear(unsigned int releaseYear) {
    BookEntry::releaseYear = releaseYear;
}

void BookEntry::setNumOfCopies(unsigned int numOfCopies) {
    BookEntry::numOfCopies = numOfCopies;
}

void BookEntry::setGenres(const std::set<Genre> &genres) {
    BookEntry::genres = genres;
}

bool BookEntry::compareReleaseYear(const BookEntry &bookA, const BookEntry& bookB) {
    return bookA.releaseYear <= bookB.releaseYear;
}
