//
// Created by steam on 1/28/2024.
//


#include <list>
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

void CLIHandler::printEntryList(std::vector<BookEntry> &entries) {
    std::stringstream ss;
    ss << "======= Listing " << entries.size() << " entries =======\n\n";
    for (int i = 0; i < entries.size(); ++i) {
        ss << i + 1 << ". " << entries[i].toString() << "\n\n";
    }
    std::cout << ss.str();
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
                sortMenu();
                entryListMenu(bookRepository.getBookEntries());
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

void CLIHandler::entryListMenu(std::vector<BookEntry>& entries) {
    std::vector<BookEntry> currentList = entries;
    std::string userInput;
    do {
        printEntryList(currentList);
        std::cout << "\n\n================================================================\n\n"
                  << "You may search the list. Subsequent searches are multiplicative.\n"
                  << "  - To search by title, enter \"title\".\n"
                  << "  - To search by author, enter \"author\".\n"
                  << "  - To search by release year, enter \"year\".\n"
                  << "  - To search by genre, enter \"genre\".\n\n"
                  << "To select an entry for viewing and editing, enter its index.\n"
                  << "To go back, enter \"exit\".\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch (std::exception &e) {
            std::cout << "\n\n======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }
        if (userInput == "exit") {
            cinClear();
            continue;
        }
        std::regex integer_regex("^\\d+$");
        if (std::regex_match(userInput, integer_regex)) {
            int index;
            try {
                index = std::stoi(userInput, nullptr, 10) - 1;
                if (index == 0 || index >= entries.size()) {
                    throw std::out_of_range("");
                }
            } catch (std::exception &e) {
                std::cout << "\n\n======= Invalid numerical input! =======\n\n";
                cinClear();
                enterToContinue();
                continue;
            }
            entryViewMenu(entries.at(index));
        } else if (userInput == "title") {
            currentList = searchByTitle(currentList);
        } else if (userInput == "author"){
            currentList = searchByAuthor(currentList);
        } else if (userInput == "year") {
            currentList = searchByYear(currentList);
        } else if (userInput == "genre") {
            currentList = searchByGenre(currentList);
        } else {
            std::cout << "\n\n======= Please choose one of the listed options. =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }
        cinClear();
    } while (userInput != "exit");
}

std::vector<BookEntry> CLIHandler::searchByYear(std::vector<BookEntry>& entries) {
    int userInput;
    std::vector<BookEntry> result;
    while (true) {
        std::cout << "\n\nEnter the year you want to search for.\n\n>> ";
        try {
            std::cin >> userInput;
        } catch(std::exception &e) {
            std::cout << "\n\n======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }
        break;
    }
    for (auto& entry : entries) {
        if (entry.getReleaseYear() == userInput) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> CLIHandler::searchByGenre(std::vector<BookEntry>& entries) {
    std::cout << "\n\nPlease choose which genres to look for.\n\n";
    std::vector<BookEntry> result;
    std::set<Genre> chosenGenres = genreSetBuilder(chosenGenres);
    for (auto& entry : entries) {
        if (std::includes(entry.getGenres().begin(), entry.getGenres().end(),
                          chosenGenres.begin(), chosenGenres.end())) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> CLIHandler::searchByTitle(std::vector<BookEntry>&entries) {
    std::vector<BookEntry> result;
    std::string query;
    std::cout << "\n\nPlease enter the search query.\n>> ";
    std::cin >> query;
    std::regex regex(query, std::regex::icase);
    for (auto& entry : entries) {
        if(std::regex_search(entry.getTitle(), regex)) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> CLIHandler::searchByAuthor(std::vector<BookEntry>&entries) {
    std::vector<BookEntry> result;
    std::string query;
    std::cout << "\n\nPlease enter the search query.\n>> ";
    std::cin >> query;
    std::regex regex(query, std::regex::icase);
    for (auto& entry : entries) {
        if(std::regex_search(entry.getAuthor(), regex)) {
            result.push_back(entry);
        }
    }
    return result;
}

void CLIHandler::entryViewMenu(BookEntry& entry) {

}

void CLIHandler::entryAddMenu() {

}

void CLIHandler::entryEditMenu() {

}

void CLIHandler::entryRemoveMenu() {

}

std::set<Genre> CLIHandler::genreSetBuilder(std::set<Genre>& genres) {
    int userInput;
    int index;
    std::set<Genre> result = genres;

    std::vector<std::string> availableGenres;
    availableGenres.reserve(genreStringMap.size());
    for (auto& genre : genreStringMap) {
        availableGenres.push_back(genre.first);
    }

    do {
        std::cout << "\n\nCurrently set genres: ";
        for (auto itr = result.begin(); itr != result.end(); ++itr) {
            std::cout << GenreToString(*itr) << (itr == --result.end() ? " " : ", ");
        }

        std::cout << "\n\nAvailable genres:\n";
        for (int i = 0; i < availableGenres.size(); ++i) {
            std::cout << i + 1 << ". " << availableGenres.at(i) << "\n";
        }

        std::cout << "\nEnter a genre's index to set or unset it.\n"
                  << "Enter 99 to exit.\n\n"
                  << ">> ";

        try {
            std::cin >> userInput;
            if ((userInput <= 0 || userInput > genreStringMap.size()) && userInput != 99) {
                throw std::out_of_range("");
            }
            index = userInput - 1;
        } catch(std::exception &e) {
            std::cout << "\n\n======= Bad numerical input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }

        if (userInput == 99) {
            continue;
        }
        Genre chosenGenre = GenreFromString(availableGenres.at(index));
        auto foundGenre = result.find(chosenGenre);
        if (foundGenre == result.end()) {
            std::cout << "Added " << availableGenres.at(index) << ".\n";
            result.insert(chosenGenre);
        } else {
            std::cout << "Removed " << availableGenres.at(index) << ".\n";
            result.erase(foundGenre);
        }
        cinClear();
    } while (userInput != 99);
    return result;
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


