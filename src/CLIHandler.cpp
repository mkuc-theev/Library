//
// Created by steam on 1/28/2024.
//


#include "headers/CLIHandler.h"
CLIHandler::CLIHandler(BookRepository& repo): bookRepository(repo) {}

void CLIHandler::cinClear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void CLIHandler::enterToContinue() {
    std::cout << "\nPress ENTER to continue...";
    char temp;
    std::cin.get(temp);
}

void CLIHandler::clearScreen()
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

void CLIHandler::mainMenu() {
    std::cin.exceptions(std::ios_base::failbit);
    int userInput;
    do {
        clearScreen();
        std::cout << "======= Main Menu =======\n"
                  << "1. List all entries\n"
                  << "2. View and manage an entry\n"
                  << "3. Add new entry\n"
                  << "4. Import entry repository from file\n"
                  << "5. Export entry repository to file\n\n"
                  << "99. Exit program\n\n"
                  << ">> ";

        try {
            std::cin >> userInput;
        } catch(std::exception &e) {
            clearScreen();
            std::cout << "======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }

        switch (userInput) {
            case 1:
                entryListMenu();
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
                clearScreen();
                std::cout << "======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }

    } while (userInput != 99);
}

void CLIHandler::entryListMenu() {
    clearScreen();
    sortMenu();
    std::cout << bookRepository.toString();
    cinClear();
    enterToContinue();
}
void CLIHandler::entryViewMenu() {

}

void CLIHandler::entryAddMenu() {

}

void CLIHandler::entryEditMenu() {

}

void CLIHandler::entryRemoveMenu() {

}

void CLIHandler::genreListBuilder() {

}

void CLIHandler::importMenu() {

}

void CLIHandler::exportMenu() {

}

void CLIHandler::sortMenu() {
    clearScreen();
    int userInput;
    do {
        std::cout << "Would you like to sort the repository?\n\n"
                  << "1. Merge sort\n"
                  << "2. Insertion sort\n"
                  << "3. Don't sort\n\n"
                  << "99. Exit\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch(std::exception &e) {
            clearScreen();
            std::cout << "======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }

        switch(userInput) {
            case 1:
                bookRepository.mergeSort(comparatorSelectMenu());
                return;
            case 2:
                bookRepository.insertionSort(comparatorSelectMenu());
                return;
            case 3:
                clearScreen();
                return;
            case 99:
                mainMenu();
            default:
                clearScreen();
                std::cout << "======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }
    } while (userInput != 99);
}

CLIHandler::comparatorFunc CLIHandler::comparatorSelectMenu() {
    clearScreen();
    int userInput;
    while(true) {
        std::cout << "Which field would you like to sort by?\n\n"
                  << "1. Title\n"
                  << "2. Author\n"
                  << "3. Number of pages\n"
                  << "4. Release year\n"
                  << "5. Number of copies\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch(std::exception &e) {
            clearScreen();
            std::cout << "======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }
        clearScreen();
        switch(userInput) {
            case 1:
                return BookEntry::compareTitle;
            case 2:
                return BookEntry::compareAuthor;
            case 3:
                return BookEntry::compareNumOfPages;
            case 4:
                return BookEntry::compareReleaseYear;
            case 5:
                return BookEntry::compareNumOfCopies;
            default:
                clearScreen();
                std::cout << "======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }
    }
}

void CLIHandler::helpScreen() {
    std::cout << "help";
}

void CLIHandler::exitScreen() {

}

