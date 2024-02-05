//
// Created by steam on 1/28/2024.
//

#ifndef LIBRARY_CLIHANDLER_H
#define LIBRARY_CLIHANDLER_H

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <limits>
#include <headers/BookRepository.h>

namespace CLIHandler {
    typedef bool (*comparatorFunc)(const BookEntry&, const BookEntry&);
    comparatorFunc comparatorSelectMenu();
    void mainMenu(BookRepository& repository);
    void entryListMenu(BookRepository& repository);
    void entryViewMenu();
    void entryAddMenu();
    void entryEditMenu();
    void entryRemoveMenu();
    void genreListBuilder();
    void importMenu();
    void exportMenu();
    void sortMenu(BookRepository& repository);
    void helpScreen();
    void exitScreen();
    void clearScreen();
    void cinClear();
    void enterToContinue();
}

#endif //LIBRARY_CLIHANDLER_H
