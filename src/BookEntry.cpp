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

std::string BookEntry::toString() {
    std::stringstream ss;
    ss << "\"" << title << "\" by " << author <<" (" << releaseYear << "):\n  "
       << numOfPages << " pages. Genres: ";
    for (auto itr = genres.begin(); itr != genres.end(); ++itr) {
        ss << GenreToString(*itr) << (itr == --genres.end() ? " " : ", ");
    }
    ss << "\n   " << numOfCopies << " copies in stock.";

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
    this->title = title;
}

void BookEntry::setAuthor(const std::string &author) {
    this->author = author;
}

void BookEntry::setNumOfPages(unsigned int numOfPages) {
    this->numOfPages = numOfPages;
}

void BookEntry::setReleaseYear(unsigned int releaseYear) {
    this->releaseYear = releaseYear;
}

void BookEntry::setNumOfCopies(unsigned int numOfCopies) {
    this->numOfCopies = numOfCopies;
}

void BookEntry::setGenres(const std::set<Genre> &genres) {
    this->genres = genres;
}


bool BookEntry::compareTitle(const BookEntry &entryA, const BookEntry &entryB) {
    return entryA.title <= entryB.title;
}

bool BookEntry::compareAuthor(const BookEntry &entryA, const BookEntry &entryB) {
    return entryA.author <= entryB.author;
}

bool BookEntry::compareNumOfPages(const BookEntry &entryA, const BookEntry &entryB) {
    return entryA.numOfPages <= entryB.numOfPages;
}

bool BookEntry::compareReleaseYear(const BookEntry &entryA, const BookEntry& entryB) {
    return entryA.releaseYear <= entryB.releaseYear;
}


bool BookEntry::compareNumOfCopies(const BookEntry &entryA, const BookEntry &entryB) {
    return entryA.numOfCopies <= entryB.numOfCopies;
}

std::string BookEntry::toRegexTarget() {
    std::stringstream result;
    result << title << author << releaseYear;
    return result.str();
}