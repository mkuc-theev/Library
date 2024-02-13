//
// Created by steam on 2/6/2024.
//

#ifndef LIBRARY_CLIHANDLER_H
#define LIBRARY_CLIHANDLER_H

#include <iostream>
#include <limits>
#include <vector>
#include "TSVHandler.h"
#include "BookRepository.h"
/**
 * Provides functions for UI flow and related operations that require console I/O.
 */
class CLIHandler {
private:
    BookRepository &bookRepository; /**< Reference to the program's data repository. */
public:
/**
 * Represents a pointer to a comparator function that accepts references to two book entries.
 */
typedef bool (*comparatorFunc)(const BookEntry &, const BookEntry &);

/**
 * Constructor for the CLIHandler class.
 * @param bookRepository Reference to the program's main data repository.
 */
explicit CLIHandler(BookRepository &bookRepository);

/**
 * Displays menu that allows choosing one of the comparator functions from the BookEntry class.
 * @return Pointer to the chosen comparator function.
 */
static comparatorFunc comparatorSelectMenu();

/**
 * Displays the main menu of the program.
 */
void mainMenu();

/**
 * Displays a menu for searching through, sorting and editing a list of book entries.
 * @param entries The vector of book entries to display and manage.
 */
void entryListMenu(std::vector<BookEntry> &entries);

/**
 * Displays information about a book entry and provides option for editing it.
 * @param entry The book entry to display and manage.
 */
void entryViewMenu(BookEntry &entry);

/**
 * Displays a menu for manually creating a new book entry and adding it to the program's repository.
 */
void entryAddMenu();

/**
 * Displays a menu for searching a vector of book entries by release year.
 * @param entries The vector of book entries to search.
 * @return Vector of book entries matching the search query provided by user.
 */
static std::vector<BookEntry> searchByYear(std::vector<BookEntry> &entries);

/**
 * Displays a menu for searching a vector of book entries by genre.
 * @param entries The vector of book entries to search.
 * @return Vector of book entries matching the list of genres provided by the user.
 */
static std::vector<BookEntry> searchByGenre(std::vector<BookEntry> &entries);

/**
 * Displays a menu for searching a vector of book entries by title.
 * @param entries The vector of book entries to search.
 * @return Vector of book entries matching the search query provided by user.
 */
static std::vector<BookEntry> searchByTitle(std::vector<BookEntry> &entries);

/**
 * Displays a menu for searching a vector of book entries by the name of the author.
 * @param entries The vector of book entries to search.
 * @return Vector of book entries matching the search query provided by user.
 */
static std::vector<BookEntry> searchByAuthor(std::vector<BookEntry> &entries);

/**
 * Displays a menu for editing the fields of a BookEntry object.
 * @param entry The book entry to edit.
 */
static void entryEditMenu(BookEntry &entry);

/**
 * Displays a menu for altering the amount of copies of a book stored in the program's repository.
 * @param entry The book entry to edit.
 * @return true if the entry was deleted, false otherwise.
 */
bool entryCopiesCountMenu(BookEntry &entry);

/**
 * Displays a menu that allows the user to build or edit a set of genre tags.
 * @param genres Existing genre set to edit, if applicable.
 * @return A new set of genre tags.
 */
static std::set<Genre> genreSetBuilder(std::set<Genre> &genres);

/**
 * Displays a menu that allows the user to manually import a repository file.
 */
void importMenu();

/**
 * Displays a menu that allows the user to manually export a repository file.
 */
void exportMenu();

/**
 * Displays a menu that allows the user to sort a vector of book entries by chosen field, using chosen algorithm.
 * @param entryVec The vector of book entries to sort.
 * @return Sorted vector of book entries.
 */
static std::vector<BookEntry> sortMenu(std::vector<BookEntry> &entryVec);

/**
 * Displays manual page for the program.
 */
static void helpScreen();

/**
 * Clears cin error flags and flushes the stream.
 */
static void cinClear();

/**
 * Trims trailing whitespace from a string.
 * @param str The string to trim.
 * @return The string with trailing whitespace removed
 */
static std::string &rtrim(std::string &str);

/**
 * Trims leading whitespace from a string.
 * @param str The string to trim.
 * @return The string with leading whitespace removed
 */
static std::string &ltrim(std::string &str);

/**
 * Trims leading and trailing whitespace from a string.
 * @param str The string to trim.
 * @return The string with leading and trailing whitespace removed
 */
static std::string &trimString(std::string &str);

/**
 * Pauses program execution and displays a message prompting the user to press the enter key to continue.
 */
static void enterToContinue();

/**
 * Displays a list of book entries.
 * @param entries The vector of book entries to display as list.
 */
static void printEntryList(std::vector<BookEntry> &entries);
};


#endif //LIBRARY_CLIHANDLER_H
