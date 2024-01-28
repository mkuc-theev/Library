//
// Created by steam on 1/26/2024.
//

#include "headers/Library.h"

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
        ss << entry.toString(false);
    }
    return ss.str();
}

void Library::addBookEntry(BookEntry newEntry) {
    for(BookEntry& entry : bookEntries) {
       if(newEntry.equals(entry)) {
           entry.setNumOfCopies(entry.getNumOfCopies() + newEntry.getNumOfCopies());
           return;
       }
    }
    bookEntries.push_back(newEntry);
}

void Library::removeBookEntry(BookEntry &book, unsigned int numOfCopies) {
    for (auto it = bookEntries.begin(); it != bookEntries.end(); ++it) {
        auto& entry = *it;
        if(book.equals(entry)) {
            if(numOfCopies > entry.getNumOfCopies()) {
                throw std::runtime_error("Can't delete more copies than there are in stock");
            }
            entry.setNumOfCopies(entry.getNumOfCopies() - numOfCopies);
            if(entry.getNumOfCopies() == 0) {
                bookEntries.erase(it);
            }
            return;
        }
    }
}

void Library::editBookEntry(const BookEntry &book) {

}

const std::vector<BookEntry> &Library::getBookEntries() const {
    return bookEntries;
}