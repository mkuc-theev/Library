//
// Created by steam on 1/28/2024.
//


#include "headers/ProgramSettings.h"

const bool ProgramSettings::isExportMode() const {
    return exportMode;
}

const bool ProgramSettings::isImportMode() const {
    return importMode;
}

const bool ProgramSettings::isHelpMode() const {
    return helpMode;
}

const std::string &ProgramSettings::getImportPath() const {
    return importPath;
}

const std::string &ProgramSettings::getExportPath() const {
    return exportPath;
}

ProgramSettings::ProgramSettings(const int &argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        if (strlen(argv[i]) != 2 || argv[i][0] != '-') {
            throw std::invalid_argument("Error in command line parameters. Use '-h' or '-H' for help.");
        }

        switch (argv[i][1]) {
            case 'i': case 'I':
                importMode = true;
                importPath = argv[++i];
                continue;
            case 'e': case 'E':
                exportMode = true;
                exportPath = argv[++i];
                continue;
            case 'h': case 'H':
                helpMode = true;
                return;
            default:
                throw std::invalid_argument("Error in command line parameters. Use '-h' or '-H' for help.");
        }
    }
}

ProgramSettings::ProgramSettings() = default;
