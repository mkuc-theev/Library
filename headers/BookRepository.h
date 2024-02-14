#ifndef LIBRARY_BOOKREPOSITORY_H
#define LIBRARY_BOOKREPOSITORY_H

#include "BookEntry.h"
#include <chrono>
#include <vector>
#include <regex>
#include <functional>

/**
 * Data repository containing BookEntry objects and allowing operations on stored values.
 */
class BookRepository {
private:
    std::vector<BookEntry> bookEntries; /**< Vector containing the BookEntry objects stored in the program's memory. */
public:
/**
 * Constructor for the BookRepository class, given an existing vector of BookEntry objects.
 * @param bookEntries Vector of BookEntry objects to populate the repository with.
 */
explicit BookRepository(std::vector<BookEntry> bookEntries);

/**
 * Default no-param constructor that initializes an empty repository.
 */
BookRepository();

/**
 * Adds a new BookEntry object to the repository, or increases the number of copies in an existing entry
 * if both entries refer to the same book.
 * @param newEntry The BookEntry object to add or increment.
 */
void addBookEntry(const BookEntry& newEntry);

/**
 * Changes the number of copies of a book in the repository. Deletes the entry if the resulting number of copies is 0.
 * @param book The BookEntry object to change the number of copies of.
 * @param numOfCopies The positive or negative value to change the number of copies by.
 * @return true if the passed entry was deleted, false otherwise.
 */
bool changeNumOfCopies(BookEntry &book, int numOfCopies);

/**
 * Fetches the vector of BookEntry objects from the repository.
 * @return Vector of BookEntry objects from the repository.
 */
std::vector<BookEntry> &getBookEntries();

/**
 * Overwrites the vector of BookEntry objects in the repository.
 * @param newEntries The new vector of BookEntry objects to be stored in the repository.
 */
void setBookEntries(std::vector<BookEntry> newEntries);

/**
 * Searches a vector of book entries for given release year.
 * @param entries The vector of book entries to search.
 * @return Vector of book entries matching the search query provided by user.
 */
    static std::vector<BookEntry> searchByYear(std::vector<BookEntry> &entries, unsigned int year);

/**
 * Searches a vector of book entries for given set of genres.
 * @param entries The vector of book entries to search.
 * @return Vector of book entries matching the search query provided by user.
 */
    static std::vector<BookEntry> searchByGenre(std::vector<BookEntry> &entries, std::set<Genre> &genres);

/**
 * Searches a vector of book entries for given title.
 * @param entries The vector of book entries to search.
 * @return Vector of book entries matching the search query provided by user.
 */
    static std::vector<BookEntry> searchByTitle(std::vector<BookEntry> &entries, std::string &title);

/**
 * Searches a vector of book entries for given author name.
 * @param entries The vector of book entries to search.
 * @return Vector of book entries matching the search query provided by user.
 */
    static std::vector<BookEntry> searchByAuthor(std::vector<BookEntry> &entries, std::string &author);

/**
 * Sorts a vector of BookEntry objects by given field using the merge sort algorithm.
 * @param start Iterator pointing to the first element of the vector.
 * @param end Iterator pointing to the last element of the vector.
 * @param comparator Pointer to a comparator function from the BookEntry class.
 * @return A vector of the given entries in sorted order.
 */
static std::vector<BookEntry> mergeSort(
        std::vector<BookEntry>::iterator start,
        std::vector<BookEntry>::iterator end,
        bool (*comparator)(const BookEntry &, const BookEntry &));

/**
 * Sorts a vector of BookEntry objects by given field using a variation of the insertion sort algorithm.
 * @param inputVec The vector of BookEntry objects to sort.
 * @param comparator Pointer to a comparator function from the BookEntry class.
 * @return A vector of the given entries in sorted order.
 */
static std::vector<BookEntry> insertionSort(
        std::vector<BookEntry> &inputVec,
        bool (*comparator)(const BookEntry &, const BookEntry &));

};

#endif //LIBRARY_BOOKREPOSITORY_H