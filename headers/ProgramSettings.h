//
// Created by steam on 1/28/2024.
//

#ifndef LIBRARY_PROGRAMSETTINGS_H
#define LIBRARY_PROGRAMSETTINGS_H


#include <string>
#include <cstring>
#include <stdexcept>

class ProgramSettings {
private:
    bool exportMode = false, importMode = false, helpMode = false;
    std::string importPath, exportPath;
public:
    ProgramSettings(const int& argc, char **argv);

    const bool isExportMode() const;

    ProgramSettings();

    const bool isImportMode() const;

    const bool isHelpMode() const;

    const std::string &getImportPath() const;

    const std::string &getExportPath() const;
};


#endif //LIBRARY_PROGRAMSETTINGS_H
