//
// Created by steam on 1/28/2024.
//

#include "headers/Application.h"

Application::Application(int &argc, char **argv)
        : settings(argc, argv),
          bookRepository(settings.isImportMode() ? BookRepository(TSVHandler::importFile(settings.getImportPath())) : BookRepository()),
          cliHandler(CLIHandler(bookRepository)) {}

void Application::run() {
    cliHandler.clearScreen();

    if(settings.isHelpMode()) {
        cliHandler.helpScreen();
        return;
    }

    try {
        cliHandler.mainMenu();
    } catch (std::exception &e) {
        throw e;
    }

}

