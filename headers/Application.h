#ifndef LIBRARY_APPLICATION_H
#define LIBRARY_APPLICATION_H

#include <headers/ProgramSettings.h>
#include <headers/BookRepository.h>
#include <headers/TSVHandler.h>
#include <headers/CLIHandler.h>
/**
 * Application class. Contains program settings, data repository and tools to display the CLI.
 */
class Application {
private:
    ProgramSettings settings; /**< Object containing program settings required at runtime. */
    BookRepository bookRepository; /**< Main data repository for the program, contains a vector of BookEntry objects. */
    CLIHandler cliHandler; /**< Program flow and CLI display manager. */
public:
    /**
     * Application object constructor.
     * @param argc Number of CLI arguments passed to the program.
     * @param argv Array of CLI arguments passed to the program.
     */
    Application(int &argc, char **argv);

    /**
     * Executes program logic, should only be called once in the main function once.
     */
    void run();
};

#endif //LIBRARY_APPLICATION_H
