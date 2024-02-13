//
// Created by steam on 1/26/2024.
//

#ifndef LIBRARY_TSVHANDLER_H
#define LIBRARY_TSVHANDLER_H

#include <string>
#include <vector>
#include <fstream>
#include "BookRepository.h"
#include "Genre.h"
/**
 * Provides functions for file I/O. The file format is TSV.
 */
namespace TSVHandler {
/**
 * Converts a BookEntry object to a string representation in the TSV format.
 * @param bookEntry The book entry to serialize.
 * @return The TSV string representation of provided entry.
 */
std::string serializeBookEntry(BookEntry &bookEntry);

/**
 * Converts a TSV string to a BookEntry object.
 * @param entryString The TSV string to deserialize.
 * @return The BookEntry object described by the string.
 */
BookEntry deserializeBookEntry(std::string &entryString);

/**
 * Imports book entries from a TSV file.
 * @param path Path to the file being imported.
 * @return Vector of book entries stored in the file.
 */
std::vector<BookEntry> importFile(const std::string &path);

/**
 * Converts a set of genre tags into a TSV string representation.
 * @param entry The entry for which to serialize genres.
 * @return String containing a TSV representation of the genre set.
 */
std::string serializeGenres(BookEntry &entry);

/**
 * Converts a TSV string representation of genres to a set of genres.
 * @param genresString String representation of a genre set.
 * @return Set of genre tags deserialized from the string.
 */
std::set<Genre> deserializeGenres(std::string &genresString);

/**
 * Exports the program's data repository to a TSV file.
 * @param path Path to the file being exported.
 * @param bookRepository Reference to the program's main data repository.
 */
void exportFile(const std::string &path, BookRepository &bookRepository);
}
#endif //LIBRARY_TSVHANDLER_H
