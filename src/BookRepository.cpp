//
// Created by steam on 1/26/2024.
//


#include "headers/BookRepository.h"

BookRepository::BookRepository(std::vector<BookEntry> bookEntries) : bookEntries{std::move(bookEntries)} {}

BookRepository::BookRepository() = default;


std::string BookRepository::toString() {
    std::stringstream ss;
    ss << "Book repository with " << bookEntries.size() << " entries:\n";
    for (BookEntry& entry : bookEntries) {
        ss << entry.toString(true);
    }
    return ss.str();
}

void BookRepository::addBookEntry(BookEntry newEntry) {
    for(BookEntry& entry : bookEntries) {
       if(newEntry.equals(entry)) {
           entry.setNumOfCopies(entry.getNumOfCopies() + newEntry.getNumOfCopies());
           return;
       }
    }
    bookEntries.push_back(newEntry);
}

void BookRepository::removeBookEntry(BookEntry &book, unsigned int numOfCopies) {
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


const std::vector<BookEntry> &BookRepository::getBookEntries() const {
    return bookEntries;
}

void BookRepository::mergeSort(bool (*comparator)(const BookEntry &, const BookEntry &)) {
    try {
        auto start = std::chrono::steady_clock::now();
        bookEntries = RepositorySorter::mergeSort(bookEntries.begin(), bookEntries.end() - 1, comparator);
        auto end = std::chrono::steady_clock::now();
        std::cout << "Mergesort done in "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                  << " nanoseconds.\n";
    } catch(std::exception& e) {
        std::cout << "Sorting failed: " << e.what() << std::endl;
    }
}
