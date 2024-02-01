//
// Created by steam on 1/28/2024.
//

#include "headers/CLIHandler.h"

namespace CLIHandler {
    void cinClear() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void clearScreen()
    {
        HANDLE                     hStdOut;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD                      count;
        DWORD                      cellCount;
        COORD                      homeCoords = { 0, 0 };

        hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
        if (hStdOut == INVALID_HANDLE_VALUE) return;

        /* Get the number of cells in the current buffer */
        if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
        cellCount = csbi.dwSize.X *csbi.dwSize.Y;

        /* Fill the entire buffer with spaces */
        if (!FillConsoleOutputCharacter(
                hStdOut,
                (TCHAR) ' ',
                cellCount,
                homeCoords,
                &count
        )) return;

        /* Fill the entire buffer with the current colors and attributes */
        if (!FillConsoleOutputAttribute(
                hStdOut,
                csbi.wAttributes,
                cellCount,
                homeCoords,
                &count
        )) return;

        /* Move the cursor home */
        SetConsoleCursorPosition( hStdOut, homeCoords );
    }

    void mainMenu(const BookRepository& repository) {
        clearScreen();
        std::cin.exceptions(std::ios_base::failbit);
        int userInput;
        do {
            std::cout << "\n======= Main Menu =======\n"
                      << "1. List all entries\n"
                      << "2. View and manage an entry\n"
                      << "3. Add new entry\n"
                      << "4. Import entry repository from file\n"
                      << "5. Export entry repository to file\n\n"
                      << "99. Exit program\n\n"
                      << ">> ";

            try {
                cinClear();
                std::cin >> userInput;
            } catch(std::exception &e) {
                std::cout << "\n\n======= Bad user input! =======\n\n";
                userInput = 0;
                continue;
            }

            switch (userInput) {
                case 1:
                    entryListMenu(repository);
                    break;
                case 2:
                    entryViewMenu();
                    break;
                case 3:
                    entryAddMenu();
                    break;
                case 4:
                    importMenu();
                    break;
                case 5:
                    exportMenu();
                    break;
                case 99:
                    continue;
                default:
                    std::cout << "\n\n======= Please choose one of the listed numbers. =======\n\n";
                    userInput = 0;
            }

        } while (userInput != 99);
    }

    void entryListMenu(const BookRepository& repository) {
        clearScreen();

    }
    void entryViewMenu() {

    }

    void entryAddMenu() {

    }

    void entryEditMenu() {

    }

    void entryRemoveMenu() {

    }

    void genreListBuilder() {

    }

    void importMenu() {

    }

    void exportMenu() {

    }

    void sortMenu() {

    }
    void helpScreen() {
        std::cout << "help";
    }

    void exitScreen() {

    }
}