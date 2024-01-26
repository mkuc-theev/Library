//
// Created by steam on 1/26/2024.
//

#include "Library.h"

Library::Library(std::vector<BookEntry> bookEntries) : bookEntries{std::move(bookEntries)} {}

Library::Library() = default;

std::vector<BookEntry> Library::mergeSort() {
    return std::vector<BookEntry>();
}

std::vector<BookEntry> Library::insertionSort() {
    return std::vector<BookEntry>();
}



std::string Library::toString() {
    std::stringstream ss;
    ss << "Library with " << bookEntries.size() << " entries:\n";
    for (BookEntry& entry : bookEntries) {
        ss << entry.book.toString(false) << ": " << entry.numOfCopies << " copies\n";
    }
    return ss.str();
}

void Library::addBook(Book book, unsigned int numOfCopies) {
    for(BookEntry& entry : bookEntries) {
       if(book.equals(entry.book)) {
           entry.numOfCopies += numOfCopies;
           return;
       }
    }
    bookEntries.push_back({book, numOfCopies});
}

void Library::removeBook(const Book &book) {

}

void Library::editBook(const Book &book) {

}

const std::vector<BookEntry> &Library::getBookEntries() const {
    return bookEntries;
}

template<typename T>
void Library::sortBy(T field, const std::function<std::vector<BookEntry>()>& sortingAlgorithm) {

}

template<typename T>
const Book &Library::compareByField(const Book &bookA, const Book &bookB, T fieldToCompare) {

}
