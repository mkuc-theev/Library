#ifndef LIBRARY_PROGRAMSETTINGS_H
#define LIBRARY_PROGRAMSETTINGS_H

#include <string>
#include <cstring>
#include <stdexcept>

/**
 * Stores program settings and arguments passed to the program from the console.
 */
class ProgramSettings {
private:
    bool exportMode = false; /**< Flag denoting if the program will export its repository to a file before terminating. */
    bool importMode = false; /**< Flag denoting if the program will initialize its repository from a file at launch. */
    bool helpMode = false; /**< Flag denoting if the program will display the manual page. */
    std::string importPath; /**< The path to the file being imported. Only set if importMode is true. */
    std::string exportPath; /**< The path to the file being exported. Only set if exportMode is true. */
public:
/**
 * Constructor for the ProgramSettings class.
 * @param argc The amount of arguments received from the console.
 * @param argv The array of arguments received from the console.
 */
ProgramSettings(const int &argc, char **argv);

/**
 * Checks if the program is running in export mode.
 * @return The state of the exportMode flag.
 */
bool isExportMode() const;

/**
 * Checks if the program is running in import mode.
 * @return The state of the importMode flag.
 */
bool isImportMode() const;

/**
 * Checks if the program is running in help mode.
 * @return The state of the helpMode flag.
 */
bool isHelpMode() const;

/**
 * Fetches the path to the file being imported to the program.
 * @return String containing the path to the file being imported to the program.
 */
const std::string &getImportPath() const;

/**
 * Fetches the path to the file being exported from the program.
 * @return String containing the path to the file being exported from the program.
 */
const std::string &getExportPath() const;
};

#endif //LIBRARY_PROGRAMSETTINGS_H