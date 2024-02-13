//
// Created by steam on 1/26/2024.
//



#include <utility>

#include "headers/BookRepository.h"

BookRepository::BookRepository(std::vector<BookEntry> bookEntries) : bookEntries{std::move(bookEntries)} {}

BookRepository::BookRepository() = default;

void BookRepository::addBookEntry(BookEntry newEntry) {
    for (BookEntry &entry: bookEntries) {
        if (newEntry.equals(entry)) {
            entry.setNumOfCopies(entry.getNumOfCopies() + newEntry.getNumOfCopies());
            return;
        }
    }
    bookEntries.push_back(newEntry);
}

bool BookRepository::changeNumOfCopies(BookEntry &book, int numOfCopies) {
    for (auto it = bookEntries.begin(); it != bookEntries.end(); ++it) {
        auto &entry = *it;
        if (book.equals(entry)) {
            if (numOfCopies < 0 && -numOfCopies > entry.getNumOfCopies()) {
                throw std::runtime_error("Can't remove more copies than there are in stock");
            }
            entry.setNumOfCopies(entry.getNumOfCopies() + numOfCopies);
            if (entry.getNumOfCopies() == 0) {
                bookEntries.erase(it);
                return true;
            }
            return false;
        }
    }
    throw std::runtime_error("Couldn't find entry!");
}


std::vector<BookEntry> &BookRepository::getBookEntries() {
    return bookEntries;
}

std::vector<BookEntry> BookRepository::mergeSort(
        const std::vector<BookEntry>::iterator start,
        const std::vector<BookEntry>::iterator end,
        bool (*comparator)(const BookEntry &, const BookEntry &)) {
    //Return if one-element iteration is reached
    if (start >= end) {
        return {*end};
    }

    //Split the given vector in half, continue recursion on both halves
    auto midpoint = std::distance(start, end) / 2 + start;
    std::vector<BookEntry> sortedVectorA = mergeSort(
            start,
            midpoint,
            comparator
    );
    std::vector<BookEntry> sortedVectorB = mergeSort(
            midpoint + 1,
            end,
            comparator
    );

    std::vector<BookEntry> result;
    result.reserve(sortedVectorA.size() + sortedVectorB.size());
    auto itA = sortedVectorA.begin();
    auto itB = sortedVectorB.begin();
    //Looping over both vectors, insert elements in order
    while (result.size() < sortedVectorA.size() + sortedVectorB.size()) {
        if (comparator(*itA, *itB)) {
            result.push_back(*itA);
            //If sorted vector A is empty, insert the rest of vector B
            if (itA == sortedVectorA.end() - 1) {
                result.insert(result.end(), itB, sortedVectorB.end());
                continue;
            }
            itA++;
        } else {
            result.push_back(*itB);
            //If sorted vector B is empty, insert the rest of vector A
            if (itB == sortedVectorB.end() - 1) {
                result.insert(result.end(), itA, sortedVectorA.end());
                continue;
            }
            itB++;
        }
    }
    return result;
}

std::vector<BookEntry> BookRepository::insertionSort(std::vector<BookEntry> &inputVec,
                                                     bool (*comparator)(const BookEntry &, const BookEntry &)) {
    //Edge case handling for 0 and 1 element input
    if (inputVec.size() <= 1) {
        return inputVec;
    }
    std::vector<BookEntry> resultVec;
    resultVec.reserve(inputVec.size());
    resultVec.push_back(inputVec[0]);
    //For every element in the input vector, iterate over the result vector until the element to the left
    //of the iterator is smaller than the considered element, then insert if that is the case
    for (auto inputIt = inputVec.begin() + 1; inputIt != inputVec.end(); ++inputIt) {
        auto resultIt = resultVec.end() - 1;
        while (resultIt >= resultVec.begin() && !comparator(*resultIt, *inputIt)) {
            --resultIt;
        }
        resultVec.insert(resultIt + 1, *inputIt);
    }
    return resultVec;
}

void BookRepository::setBookEntries(std::vector<BookEntry> newEntries) {
    bookEntries = std::move(newEntries);
}

std::vector<BookEntry> BookRepository::searchByYear(std::vector<BookEntry> &entries, unsigned int year) {
    std::vector<BookEntry> result;
    for (auto &entry: entries) {
        if (entry.getReleaseYear() == year) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> BookRepository::searchByGenre(std::vector<BookEntry> &entries, std::set<Genre> &genres) {
    std::vector<BookEntry> result;
    for (auto &entry: entries) {
        if (std::includes(entry.getGenres().begin(), entry.getGenres().end(),
                          genres.begin(), genres.end())) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> BookRepository::searchByTitle(std::vector<BookEntry> &entries, std::string &title) {
    std::vector<BookEntry> result;
    std::regex regex(title, std::regex::icase);
    for (auto &entry: entries) {
        if (std::regex_search(entry.getTitle(), regex)) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> BookRepository::searchByAuthor(std::vector<BookEntry> &entries, std::string &author) {
    std::vector<BookEntry> result;
    std::regex regex(author, std::regex::icase);
    for (auto &entry: entries) {
        if (std::regex_search(entry.getAuthor(), regex)) {
            result.push_back(entry);
        }
    }
    return result;
}

