//
// Created by steam on 2/6/2024.
//

#ifndef LIBRARY_CLIHANDLER_H
#define LIBRARY_CLIHANDLER_H

#include <iostream>
#include <limits>
#include <vector>
#include "BookRepository.h"

class CLIHandler {
private:
    BookRepository& bookRepository;
public:
    typedef bool (*comparatorFunc)(const BookEntry&, const BookEntry&);
    explicit CLIHandler(BookRepository& bookRepository);
    comparatorFunc comparatorSelectMenu();
    void mainMenu();
    void entryListMenu(std::vector<BookEntry>& entries);
    void entryViewMenu(BookEntry& entry);
    void entryAddMenu();
    std::vector<BookEntry>  searchByYear(std::vector<BookEntry>& entries);
    std::vector<BookEntry>  searchByGenre(std::vector<BookEntry>& entries);
    std::vector<BookEntry>  searchByTitle(std::vector<BookEntry>& entries);
    std::vector<BookEntry>  searchByAuthor(std::vector<BookEntry>& entries);
    void entryEditMenu();
    void entryRemoveMenu();
    std::set<Genre> genreSetBuilder(std::set<Genre>& genres);
    void importMenu();
    void exportMenu();
    void sortMenu();
    void helpScreen();
    void cinClear();
    void enterToContinue();
    void printEntryList(std::vector<BookEntry>& entries);
};


#endif //LIBRARY_CLIHANDLER_H
