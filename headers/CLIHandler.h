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
    void mainMenu(const BookRepository& repository);
    void entryListMenu(const BookRepository& repository);
    void entryViewMenu();
    void entryAddMenu();
    void entryEditMenu();
    void entryRemoveMenu();
    void genreListBuilder();
    void importMenu();
    void exportMenu();
    void sortMenu();
    void helpScreen();
    void exitScreen();
    void clearScreen();
    void cinClear();
}

#endif //LIBRARY_CLIHANDLER_H
