//
// Created by steam on 1/28/2024.
//


#include <list>
#include "headers/CLIHandler.h"

CLIHandler::CLIHandler(BookRepository &repo) : bookRepository(repo) {}

void CLIHandler::cinClear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CLIHandler::enterToContinue() {
    std::cout << "\nPress ENTER to continue...";
    char temp;
    std::cin.get(temp);
}

std::string &CLIHandler::ltrim(std::string &str) {
    auto it2 = std::find_if(str.begin(), str.end(),
                            [](char ch) { return !std::isspace<char>(ch, std::locale::classic()); });
    str.erase(str.begin(), it2);
    return str;
}

std::string &CLIHandler::rtrim(std::string &str) {
    auto it1 = std::find_if(str.rbegin(), str.rend(),
                            [](char ch) { return !std::isspace<char>(ch, std::locale::classic()); });
    str.erase(it1.base(), str.end());
    return str;
}

std::string &CLIHandler::trimString(std::string &str) {
    return ltrim(rtrim(str));
}

void CLIHandler::printEntryList(std::vector<BookEntry> &entries) {
    std::stringstream ss;
    ss << "\n======= Listing " << entries.size() << " entries =======\n\n";
    for (int i = 0; i < entries.size(); ++i) {
        ss << i + 1 << ". " << entries[i].toString() << "\n\n";
    }
    std::cout << ss.str();
}

void CLIHandler::mainMenu() {
    std::cin.exceptions(std::ios_base::failbit);
    int userInput;
    do {
        std::cout << "\n======= Main Menu =======\n\n"
                  << "1. View and manage entries\n"
                  << "2. Add new entry\n"
                  << "3. Import entry repository from file\n"
                  << "4. Export entry repository to file\n\n"
                  << "99. Exit program\n\n"
                  << ">> ";

        try {
            std::cin >> userInput;
        } catch (std::exception &e) {
            std::cout << "\n======= Bad user input! =======\n";
            cinClear();
            enterToContinue();
            continue;
        }
        cinClear();
        switch (userInput) {
            case 1:
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
                std::cout << "\nExiting...\n\n";
                break;
            default:
                std::cout << "\n======= Please choose one of the listed numbers. =======\n";
                cinClear();
                enterToContinue();
                continue;
        }
    } while (userInput != 99);
}

void CLIHandler::entryListMenu(std::vector<BookEntry> &entries) {
    std::vector<BookEntry> &currentList = entries;
    std::string userInput;
    do {
        printEntryList(currentList);
        std::cout << "================================================================\n\n"
                  << "You may search the list. Subsequent searches are multiplicative.\n"
                  << "  - To search by title, enter \"title\".\n"
                  << "  - To search by author, enter \"author\".\n"
                  << "  - To search by release year, enter \"year\".\n"
                  << "  - To search by genre, enter \"genre\".\n"
                  << "  - To reset the search, enter \"reset\"\n\n"
                  << "To sort the list, enter \"sort\"\n"
                  << "To select an entry for viewing and editing, enter its index.\n"
                  << "To go back, enter \"exit\".\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch (std::exception &e) {
            std::cout << "\n======= Bad user input! =======\n";
            cinClear();
            enterToContinue();
            continue;
        }
        if (userInput == "exit") {
            continue;
        }
        std::regex integer_regex("^\\d+$");
        if (std::regex_match(userInput, integer_regex)) {
            int index;
            try {
                index = std::stoi(userInput, nullptr, 10) - 1;
                if (index < 0 || index >= currentList.size()) {
                    throw std::out_of_range("");
                }
            } catch (std::exception &e) {
                std::cout << "\n======= Invalid numerical input! =======\n";
                cinClear();
                enterToContinue();
                continue;
            }
            entryViewMenu(currentList.at(index));
        } else if (userInput == "title") {
            currentList = searchByTitle(currentList);
        } else if (userInput == "author") {
            currentList = searchByAuthor(currentList);
        } else if (userInput == "year") {
            currentList = searchByYear(currentList);
        } else if (userInput == "genre") {
            currentList = searchByGenre(currentList);
        } else if (userInput == "reset") {
            currentList = bookRepository.getBookEntries();
        } else if (userInput == "sort") {
            currentList = sortMenu(currentList);
        } else {
            std::cout << "\n\n======= Please choose one of the listed options. =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }
    } while (userInput != "exit");
}

std::vector<BookEntry> CLIHandler::searchByYear(std::vector<BookEntry> &entries) {
    int userInput;
    std::vector<BookEntry> result;
    while (true) {
        std::cout << "\nEnter the year you want to search for.\n\n>> ";
        try {
            std::cin >> userInput;
        } catch (std::exception &e) {
            std::cout << "\n======= Bad numerical input! =======\n";
            cinClear();
            enterToContinue();
            continue;
        }
        break;
    }
    for (auto &entry: entries) {
        if (entry.getReleaseYear() == userInput) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> CLIHandler::searchByGenre(std::vector<BookEntry> &entries) {
    std::cout << "\nPlease choose which genres to look for.\n";
    std::vector<BookEntry> result;
    std::set<Genre> chosenGenres = genreSetBuilder(chosenGenres);
    for (auto &entry: entries) {
        if (std::includes(entry.getGenres().begin(), entry.getGenres().end(),
                          chosenGenres.begin(), chosenGenres.end())) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> CLIHandler::searchByTitle(std::vector<BookEntry> &entries) {
    cinClear();
    std::vector<BookEntry> result;
    std::string query;
    do {
        std::cout << "\nPlease enter the search query.\n>> ";
        std::getline(std::cin, query);
        if (query.empty()) {
            std::cout << "\nQuery can't be empty!\n";
        }
    } while (query.empty());
    query = trimString(query);
    std::regex regex(query, std::regex::icase);
    for (auto &entry: entries) {
        if (std::regex_search(entry.getTitle(), regex)) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<BookEntry> CLIHandler::searchByAuthor(std::vector<BookEntry> &entries) {
    cinClear();
    std::vector<BookEntry> result;
    std::string query;
    do {
        std::cout << "\nPlease enter the search query.\n>> ";
        std::getline(std::cin, query);
        if (query.empty()) {
            std::cout << "\nQuery can't be empty!\n";
        }
    } while (query.empty());
    query = trimString(query);
    std::regex regex(query, std::regex::icase);
    for (auto &entry: entries) {
        if (std::regex_search(entry.getAuthor(), regex)) {
            result.push_back(entry);
        }
    }
    return result;
}

void CLIHandler::entryViewMenu(BookEntry &entry) {
    int userInput;
    do {
        std::cout << "\nSelected entry:\n\n"
                  << entry.toString();
        std::cout << "\n==============\n\n"
                  << "1. Edit entry\n"
                  << "2. Manage number of copies in entry\n\n"
                  << "99. Exit\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch (std::exception &e) {
            std::cout << "\n======= Bad numerical input! =======\n";
            cinClear();
            enterToContinue();
            continue;
        }
        cinClear();
        switch (userInput) {
            case 1:
                entryEditMenu(entry);
                break;
            case 2:
                if (entryCopiesCountMenu(entry)) {
                    return;
                }
                break;
            case 99:
                continue;
            default:
                std::cout << "\n======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }
    } while (userInput != 99);
}

void CLIHandler::entryAddMenu() {
    int intInput;
    std::string stringInput;
    do {
        BookEntry entry;
        std::cout << "\n======= Adding new entry =======\n\n";
        do {
            std::cout << "Please enter the title of the book: ";
            std::getline(std::cin, stringInput);
            if (stringInput.empty()) {
                std::cout << "\nField cannot be empty!\n";
            }
        } while (stringInput.empty());
        entry.setTitle(stringInput);
        do {
            std::cout << "\nPlease enter the name of the author: ";
            std::getline(std::cin, stringInput);
            if (stringInput.empty()) {
                std::cout << "\nField cannot be empty!\n";
            }

        } while (stringInput.empty());
        entry.setAuthor(stringInput);
        while (true) {
            std::cout << "\nPlease enter the number of pages: ";
            try {
                std::cin >> intInput;
                if (intInput <= 0) {
                    throw std::out_of_range("\n======= Input can't be below 1! =======\n\n");
                }
                entry.setNumOfPages(intInput);
            } catch (std::exception &e) {
                std::cout << "\n======= Bad user input! =======\n\n";
                cinClear();
                enterToContinue();
                continue;
            }
            cinClear();
            break;
        }
        while (true) {
            std::cout << "\nPlease enter the release year: ";
            try {
                std::cin >> intInput;
                if (intInput < 0) {
                    throw std::out_of_range("\n======= Input can't be below 0! =======\n\n");
                }
                entry.setReleaseYear(intInput);
            } catch (std::exception &e) {
                std::cout << "\n======= Bad user input! =======\n\n";
                cinClear();
                enterToContinue();
                continue;
            }
            cinClear();
            break;
        }
        std::cout << "\nBuilding genre list...\n";
        entry.setGenres(genreSetBuilder(entry.getGenres()));
        while (true) {
            std::cout << "\nPlease enter the number of copies to add: ";
            try {
                std::cin >> intInput;
                if (intInput <= 0) {
                    throw std::out_of_range("\n======= Input can't be below 1! =======\n\n");
                }
                entry.setNumOfCopies(intInput);
            } catch (std::exception &e) {
                std::cout << "\n======= Bad user input! =======\n\n";
                cinClear();
                enterToContinue();
                continue;
            }
            cinClear();
            break;
        }
        while (true) {
            std::cout << "\n\nCompleted entry creation. Is this correct?\n\n"
                      << entry.toString()
                      << "\n1. Yes\n"
                      << "2. No, start over\n\n"
                      << "3. Cancel\n\n"
                      << ">> ";
            try {
                std::cin >> intInput;
            } catch (std::exception &e) {
                std::cout << "\n======= Bad user input! =======\n\n";
                cinClear();
                enterToContinue();
                continue;
            }
            cinClear();
            break;
        }
        switch (intInput) {
            case 1:
                bookRepository.addBookEntry(entry);
                std::cout << "\nEntry added!\n";
                break;
            case 2:
                std::cout << "\nResetting...\n";
                break;
            case 99:
                break;
            default:
                std::cout << "\n======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }
    } while (intInput != 99 && intInput != 1);
}

void CLIHandler::entryEditMenu(BookEntry &entry) {
    int userInput;
    std::string stringInput;
    do {
        std::cout << "\nSelected entry: \n"
                  << entry.toString()
                  << "\nWhich property would you like to change?\n\n"
                  << "1. Title\n"
                  << "2. Author\n"
                  << "3. Release year\n"
                  << "4. Number of pages\n"
                  << "5. Genres\n\n"
                  << "99. Exit\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch (std::exception &e) {
            std::cout << "\n======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }
        cinClear();
        switch (userInput) {
            case 1:
                do {
                    std::cout << "\nWhat should the new title be?\n\n>> ";
                    std::getline(std::cin, stringInput);
                    if (stringInput.empty()) {
                        std::cout << "\nTitle field cannot be empty!\n";
                    }
                } while (stringInput.empty());
                entry.setTitle(stringInput);
                std::cout << "\nChanged title to \"" << stringInput << "\".\n";
                break;
            case 2:
                do {
                    std::cout << "\nWhat should the new author be?\n\n>> ";
                    std::getline(std::cin, stringInput);
                    if (stringInput.empty()) {
                        std::cout << "\nAuthor field cannot be empty!\n";
                    }
                } while (stringInput.empty());
                entry.setAuthor(stringInput);
                std::cout << "\nChanged author to \"" << stringInput << "\".\n";
                break;
            case 3:
                while (true) {
                    std::cout << "\nWhat should the new release year be?\n\n>> ";
                    try {
                        std::cin >> userInput;
                        if (userInput < 0) {
                            throw std::out_of_range("Year can't be negative");
                        }
                    } catch (std::exception &e) {
                        std::cout << "\n======= Bad user input! =======\n\n";
                        cinClear();
                        enterToContinue();
                        continue;
                    }
                    break;
                }
                entry.setReleaseYear(userInput);
                std::cout << "\nChanged release year to " << userInput << ".\n";
                break;
            case 4:
                while (true) {
                    std::cout << "\nWhat should the new page count be?\n\n>> ";
                    try {
                        std::cin >> userInput;
                        if (userInput < 1) {
                            throw std::out_of_range("Page count must be positive");
                        }
                    } catch (std::exception &e) {
                        std::cout << "\n======= Bad user input! =======\n\n";
                        cinClear();
                        enterToContinue();
                        continue;
                    }
                    break;
                }
                entry.setNumOfPages(userInput);
                std::cout << "\nChanged number of pages to " << userInput << ".\n";
                break;
            case 5:
                entry.setGenres(genreSetBuilder(entry.getGenres()));
                break;
            case 99:
                continue;
            default:
                std::cout << "\n======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }
    } while (userInput != 99);

}

bool CLIHandler::entryCopiesCountMenu(BookEntry &entry) {
    int userInput;
    while (true) {
        std::cout << "\nEnter a positive number to increase number of copies, or a negative number to decrease it.\n"
                     "Removing all copies will remove the entry.\n"
                     "Enter 0 to cancel.\n\n"
                     ">> ";
        try {
            std::cin >> userInput;
            if (userInput == 0) {
                break;
            }
            return (bookRepository.changeNumOfCopies(entry, userInput));
        } catch (std::exception &e) {
            std::cout << "\n" << e.what() << "\n";
            cinClear();
            enterToContinue();
            continue;
        }
    }
    return false;
}

std::set<Genre> CLIHandler::genreSetBuilder(std::set<Genre> &genres) {
    int userInput;
    int index;
    std::set<Genre> result = genres;

    std::vector<std::string> availableGenres;
    availableGenres.reserve(genreStringMap.size());
    for (auto &genre: genreStringMap) {
        availableGenres.push_back(genre.first);
    }

    while (true) {
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
        } catch (std::exception &e) {
            std::cout << "\n======= Bad numerical input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }

        if (userInput == 99) {
            if (result.empty()) {
                std::cout << "\n======= Please select at least one genre tag. =======\n\n";
                continue;
            }
            break;
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
    }
    return result;
}

void CLIHandler::importMenu() {
    std::string userInput;
    std::cout << "\nPlease enter the path to the file you wish to import.\n>> ";
    std::getline(std::cin, userInput);
    try {
        bookRepository.setBookEntries(TSVHandler::importFile(userInput));
        std::cout << "\nFile imported successfully!\n";
    } catch (std::exception &e) {
        std::cout << "\n======= File import failed! =======\n\n";
    }
}

void CLIHandler::exportMenu() {
    std::string userInput;
    std::cout << "\nPlease enter the export path.\n\n>> ";
    std::getline(std::cin, userInput);
    try {
        TSVHandler::exportFile(userInput, bookRepository);
        std::cout << "\nFile exported successfully!\n";
    } catch (std::exception &e) {
        std::cout << "\n======= File export failed! =======\n\n";
    }
}

std::vector<BookEntry> CLIHandler::sortMenu(std::vector<BookEntry> &entryVec) {
    int userInput;
    while (true) {
        std::cout << "\nWould you like to sort the repository?\n\n"
                  << "1. Merge sort\n"
                  << "2. Insertion sort\n\n"
                  << "99. Cancel\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch (std::exception &e) {

            std::cout << "\n======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }

        switch (userInput) {
            case 1:
                return BookRepository::mergeSort(
                        entryVec.begin(),
                        entryVec.end() - 1,
                        comparatorSelectMenu()
                );

            case 2:
                return BookRepository::insertionSort(
                        entryVec,
                        comparatorSelectMenu()
                );
            case 99:
                return entryVec;
            default:
                std::cout << "\n======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }
        cinClear();
    }
}

CLIHandler::comparatorFunc CLIHandler::comparatorSelectMenu() {
    int userInput;
    while (true) {
        std::cout << "\nWhich field would you like to sort by?\n\n"
                  << "1. Title\n"
                  << "2. Author\n"
                  << "3. Number of pages\n"
                  << "4. Release year\n"
                  << "5. Number of copies\n\n"
                  << ">> ";
        try {
            std::cin >> userInput;
        } catch (std::exception &e) {

            std::cout << "\n======= Bad user input! =======\n\n";
            cinClear();
            enterToContinue();
            continue;
        }

        switch (userInput) {
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

                std::cout << "\n======= Please choose one of the listed numbers. =======\n\n";
                cinClear();
                enterToContinue();
        }
    }
}

void CLIHandler::helpScreen() {
    std::cout << "\n======= Library usage =======\n\n"
              << ".\\Library.exe [parameters]\n"
              << "Available parameters:\n"
              << "-i [path] - Import book repository from filepath.\n"
              << "-e [path] - Export book repository to file path before exiting program.\n"
              << "-h - Show this help message.\n\n";
    enterToContinue();
}


