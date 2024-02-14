#include "headers/BookEntry.h"
#include <utility>
#include <sstream>

BookEntry::BookEntry(std::string bookTitle, std::string bookAuthor, unsigned int bookNumOfPages,
                     unsigned int bookReleaseYear, unsigned int bookNumOfCopies, std::set<Genre> bookGenres):
                     title{std::move(bookTitle)},
                     author{std::move(bookAuthor)},
                     numOfPages{bookNumOfPages},
                     releaseYear{bookReleaseYear},
                     numOfCopies{bookNumOfCopies},
                     genres{std::move(bookGenres)} {}

BookEntry::BookEntry() : numOfPages{0}, releaseYear{0}, numOfCopies{0} {}

std::string BookEntry::toString() {
    std::stringstream ss;
    ss << "\"" << title << "\" by " << author << " (" << releaseYear << "):\n  "
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

const unsigned int &BookEntry::getNumOfCopies() const {
    return numOfCopies;
}

std::set<Genre> &BookEntry::getGenres() {
    return genres;
}

bool BookEntry::operator==(BookEntry book) const {
    return (
            title == book.getTitle() &&
            author == book.getAuthor() &&
            numOfPages == book.getNumOfPages() &&
            releaseYear == book.getReleaseYear() &&
            genres == book.getGenres()
    );
}

void BookEntry::setTitle(const std::string &newTitle) {
    this->title = newTitle;
}

void BookEntry::setAuthor(const std::string &newAuthor) {
    this->author = newAuthor;
}

void BookEntry::setNumOfPages(unsigned int newNumOfPages) {
    this->numOfPages = newNumOfPages;
}

void BookEntry::setReleaseYear(unsigned int newReleaseYear) {
    this->releaseYear = newReleaseYear;
}

void BookEntry::setNumOfCopies(unsigned int newNumOfCopies) {
    this->numOfCopies = newNumOfCopies;
}

void BookEntry::setGenres(const std::set<Genre> &newGenres) {
    this->genres = newGenres;
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

bool BookEntry::compareReleaseYear(const BookEntry &entryA, const BookEntry &entryB) {
    return entryA.releaseYear <= entryB.releaseYear;
}

bool BookEntry::compareNumOfCopies(const BookEntry &entryA, const BookEntry &entryB) {
    return entryA.numOfCopies <= entryB.numOfCopies;
}