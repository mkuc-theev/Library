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

void CLIHandler::mainMenu() {
    std::cin.exceptions(std::ios_base::failbit);
    int userInput;
    do {
        std::cout << "\n\n======= Main Menu =======\n\n"
                  << "1. View and manage entries\n"
                  << "2. Add new entry\n"
                  << "3. Import entry repository from file\n"
                  << "4. Export entry repository to file\n\n"
                  << "99. Exit program\n\n"
                  << ">> ";

        try {
            std::cin >> userInput;
        } catch(std::exception &e) {
            
            std::cout << "\n\n======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }

        switch (userInput) {
            case 1:
                entryListMenu();
                break;
            case 2:
                entryAddMenu();
                break;
            case 3:
                importMenu();
                break;
            case 4:
                exportMenu();
                break;
            case 99:
                std::cout << "\nExiting...\n";
                break;
            default:
                std::cout << "\n\n======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
                continue;
        }
        cinClear();
    } while (userInput != 99);
}

void CLIHandler::entryListMenu() {
    sortMenu();
    std::cout << bookRepository.toString();
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
    int userInput;
    do {
        std::cout << "\n\nWould you like to sort the repository?\n\n"
                  << "1. Merge sort\n"
                  << "2. Insertion sort\n"
                  << "3. Don't sort\n\n"
                  << "99. Exit\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch(std::exception &e) {
            
            std::cout << "\n\n======= Bad user input! =======\n\n";
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
                return;
            case 99:
                mainMenu();
            default:
                
                std::cout << "\n\n======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }
        cinClear();
    } while (userInput != 99);
}

CLIHandler::comparatorFunc CLIHandler::comparatorSelectMenu() {
    int userInput;
    while(true) {
        std::cout << "\n\nWhich field would you like to sort by?\n\n"
                  << "1. Title\n"
                  << "2. Author\n"
                  << "3. Number of pages\n"
                  << "4. Release year\n"
                  << "5. Number of copies\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch(std::exception &e) {
            
            std::cout << "\n\n======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }
        
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
                
                std::cout << "\n\n======= Please choose one of the listed numbers. =======\n\n";
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

