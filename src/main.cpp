#include <iostream>
#include <conio.h>
#include "headers/BookRepository.h"
#include "headers/CSVHandler.h"
#include "headers/ProgramSettings.h"
#include "headers/MenuHandler.h"
#include "headers/Application.h"


int main(int argc, char** argv) {
    try {
        Application app = Application(argc, argv);
        app.run();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
