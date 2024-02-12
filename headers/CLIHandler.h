//
// Created by steam on 2/6/2024.
//

#ifndef LIBRARY_CLIHANDLER_H
#define LIBRARY_CLIHANDLER_H

#include <iostream>
#include <limits>
#include <vector>
#include "TSVHandler.h"
#include "BookRepository.h"

class CLIHandler {
private:
    BookRepository &bookRepository;
public:
    typedef bool (*comparatorFunc)(const BookEntry &, const BookEntry &);

    explicit CLIHandler(BookRepository &bookRepository);

    static comparatorFunc comparatorSelectMenu();

    void mainMenu();

    void entryListMenu(std::vector<BookEntry> &entries);

    void entryViewMenu(BookEntry &entry);

    void entryAddMenu();

    static std::vector<BookEntry> searchByYear(std::vector<BookEntry> &entries);

    static std::vector<BookEntry> searchByGenre(std::vector<BookEntry> &entries);

    static std::vector<BookEntry> searchByTitle(std::vector<BookEntry> &entries);

    static std::vector<BookEntry> searchByAuthor(std::vector<BookEntry> &entries);

    static void entryEditMenu(BookEntry &entry);

    bool entryCopiesCountMenu(BookEntry &entry);

    static std::set<Genre> genreSetBuilder(std::set<Genre> &genres);

    void importMenu();

    void exportMenu();

    static std::vector<BookEntry> sortMenu(std::vector<BookEntry> &entryVec);

    static void helpScreen();

    static void cinClear();

    static std::string &rtrim(std::string &str);

    static std::string &ltrim(std::string &str);

    static std::string &trimString(std::string &str);

    static void enterToContinue();

    static void printEntryList(std::vector<BookEntry> &entries);
};


#endif //LIBRARY_CLIHANDLER_H
