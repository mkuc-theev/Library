//
// Created by Michał Kuć on 18/12/2023.
//

#ifndef LIBRARY_BOOKENTRY_H
#define LIBRARY_BOOKENTRY_H
#include "Genre.h"

#include <string>
#include <set>
#include <sstream>
/**
 * Class representing a book as well as the number of copies of that book being stored in the repository.
 */
class BookEntry {
private:
    std::string title; /**< The title of this book. */
    std::string author; /**< The author of this book. */
    unsigned int numOfPages; /**< The number of pages this book has. */
    unsigned int releaseYear; /**< The year this book was released in. */
    unsigned int numOfCopies; /**< The number of copies of this book being stored in the repository. */
    std::set<Genre> genres; /**< A set of tags denominating the genres this book could be classified as. */
public:
/**
* Constructor for the BookEntry class.
* @param title The title of the book.
* @param author The book author's name.
* @param numOfPages The number of pages of the book.
* @param releaseYear The release year of the book.
* @param numOfCopies The number of copies of the book.
* @param genres The set of genre tags describing the book's genres.
*/
BookEntry(std::string title, std::string author, unsigned int numOfPages, unsigned int releaseYear, unsigned int numOfCopies, std::set<Genre> genres);

/**
* Default constructor for the book entry class. Initializes a BookEntry with default empty values.
*/
BookEntry();

/**
 * Changes the title of this book.
 * @param newTitle The new title.
 */
void setTitle(const std::string &newTitle);

/**
 * Changes the name of the author of this book.
 * @param newAuthor The new author name.
 */
void setAuthor(const std::string &newAuthor);

/**
 * Changes the number of pages of this book.
 * @param newNumOfPages The new number of pages.
 */
void setNumOfPages(unsigned int newNumOfPages);

/**
 * Changes the release year of this book.
 * @param newReleaseYear The new release year.
 */
void setReleaseYear(unsigned int newReleaseYear);

/**
 * Changes the number of copies of this book being stored in the repository.
 * @param newNumOfCopies The new number of copies.
 */
void setNumOfCopies(unsigned int newNumOfCopies);

/**
 * Changes the set of genre tags describing this book's genres.
 * @param newGenres New set of genre tags.
 */
void setGenres(const std::set<Genre> &newGenres);

/**
 * @return String containing a human-readable representation of this book's parameters.
 */
std::string toString();

/**
 * Fetches the title of this book.
 * @return String containing the title of this book.
 */
const std::string &getTitle() const;

/**
 * Fetches the author of this book.
 * @return String containing the name of this book's author.
 */
const std::string &getAuthor() const;

/**
 * Fetches the number of pages of this book.
 * @return Integer representing the number of the pages of this book.
 */
unsigned int getNumOfPages() const;

/**
 * Fetches the release year of this book.
 * @return Integer representing the release year of this book.
 */
unsigned int getReleaseYear() const;

/**
 * Fetches the number of copies of this book being stored in the repository.
 * @return Integer representing the number of copies of this book being stored in the repository.
 */
const unsigned int & getNumOfCopies() const;

/**
 * Fetches the set of genre tags describing this book's genres.
 * @return Set of genre tags describing this book's genres.
 */
std::set<Genre> &getGenres();

/**
 * Checks whether two BookEntry objects represent the same book.
 * @param book The BookEntry object to check this BookEntry against.
 * @return true if the BookEntry objects represent the same book, otherwise false.
 */
bool equals(BookEntry& book);

/**
 * Compares the titles of two BookEntry objects.
 * @param entryA The first BookEntry object.
 * @param entryB The second BookEntry object.
 * @return true if the title of the first BookEntry object is alphabetically smaller or equal to that of the second, false otherwise.
 */
static bool compareTitle(const BookEntry &entryA, const BookEntry &entryB);

/**
 * Compares the authors of two BookEntry objects.
 * @param entryA The first BookEntry object.
 * @param entryB The second BookEntry object.
 * @return true if the author of the first BookEntry object is alphabetically smaller or equal to that of the second, false otherwise.
 */
static bool compareAuthor(const BookEntry &entryA, const BookEntry &entryB);

/**
 * Compares the numbers of pages of two BookEntry objects.
 * @param entryA The first BookEntry object.
 * @param entryB The second BookEntry object.
 * @return true if the number of pages of the first BookEntry object is smaller or equal to that of the second, false otherwise.
 */
static bool compareNumOfPages(const BookEntry &entryA, const BookEntry &entryB);

/**
 * Compares the release years of two BookEntry objects.
 * @param entryA The first BookEntry object.
 * @param entryB The second BookEntry object.
 * @return true if the release year of the first BookEntry object is smaller or equal to that of the second, false otherwise.
 */
static bool compareReleaseYear(const BookEntry &entryA, const BookEntry &entryB);

/**
 * Compares the numbers of copies of two BookEntry objects.
 * @param entryA The first BookEntry object.
 * @param entryB The second BookEntry object.
 * @return true if the number of copies of the first BookEntry object is smaller or equal to that of the second, false otherwise.
 */
static bool compareNumOfCopies(const BookEntry &entryA, const BookEntry &entryB);
};


#endif //LIBRARY_BOOKENTRY_H
