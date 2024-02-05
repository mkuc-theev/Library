#include <iostream>
#include <conio.h>
#include "headers/BookRepository.h"
#include "headers/TSVHandler.h"
#include "headers/ProgramSettings.h"
#include "headers/CLIHandler.h"
#include "headers/Application.h"


int main(int argc, char** argv) {
    try {
        Application app = Application(argc, argv);
        app.run();
    } catch (std::exception& e) {
        std::cout << "\nProgram terminated: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
