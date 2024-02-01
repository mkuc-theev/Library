//
// Created by steam on 1/28/2024.
//

#include "headers/Application.h"

Application::Application(int &argc, char **argv) {
    settings = ProgramSettings(argc, argv);
    if(settings.isImportMode()) {
        try {
            bookRepository = BookRepository(TSVHandler::importFile(settings.getImportPath()));
        } catch (std::exception &e) {
            throw e;
        }
    } else {
        bookRepository = BookRepository();
    }
}

void Application::run() {
    CLIHandler::clearScreen();

    if(settings.isHelpMode()) {
        CLIHandler::helpScreen();
        return;
    }

    try {
        CLIHandler::mainMenu();
    } catch (std::exception &e) {
        throw e;
    }

}

