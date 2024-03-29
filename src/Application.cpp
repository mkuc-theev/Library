#include "headers/Application.h"

Application::Application(int &argc, char **argv)
        : settings(argc, argv),
          bookRepository(settings.isImportMode() ? BookRepository(TSVHandler::importFile(settings.getImportPath()))
                                                 : BookRepository()),
          cliHandler(CLIHandler(bookRepository)) {}

void Application::run() {
    if (settings.isHelpMode()) {
        CLIHandler::helpScreen();
        return;
    }
    try {
        cliHandler.mainMenu();
        if (settings.isExportMode()) {
            TSVHandler::exportFile(settings.getExportPath(), bookRepository);
        }
    } catch (std::exception &e) {
        throw e;
    }
}