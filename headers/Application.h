//
// Created by steam on 1/28/2024.
//

#ifndef LIBRARY_APPLICATION_H
#define LIBRARY_APPLICATION_H

#include <headers/ProgramSettings.h>
#include <headers/BookRepository.h>
#include <headers/TSVHandler.h>
#include <headers/CLIHandler.h>

class Application {
private:
    ProgramSettings settings;
    BookRepository bookRepository;
    CLIHandler cliHandler;
public:
    Application(int &argc, char **argv);
    void run();
};


#endif //LIBRARY_APPLICATION_H
