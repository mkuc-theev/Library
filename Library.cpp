//
// Created by steam on 1/26/2024.
//

#include "Library.h"

Library::Library(std::vector<Book>& books) {

}

Library::Library() {
}

std::vector<BookEntry> Library::mergeSort() {
    return std::vector<BookEntry>();
}

std::vector<BookEntry> Library::insertionSort() {
    return std::vector<BookEntry>();
}



std::string Library::toString() {
    return std::string();
}

void Library::addBook(const Book &book) {

}

void Library::removeBook(const Book &book) {

}

void Library::editBook(const Book &book) {

}

template<typename T>
void Library::sortBy(T field, const std::function<std::vector<BookEntry>()>& sortingAlgorithm) {

}

template<typename T>
const Book &Library::compareByField(const Book &bookA, const Book &bookB, T fieldToCompare) {

}
