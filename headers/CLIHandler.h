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
    void entryListMenu();
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
    void cinClear();
    void enterToContinue();
};


#endif //LIBRARY_CLIHANDLER_H
