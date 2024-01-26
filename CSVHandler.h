//
// Created by steam on 1/26/2024.
//

#ifndef LIBRARY_CSVHANDLER_H
#define LIBRARY_CSVHANDLER_H

#include <string>
#include <vector>
#include <fstream>
#include "Library.h"
#include "Genre.h"

namespace CSVHandler {
    std::string serializeBookEntry(const BookEntry &bookEntry);

    BookEntry deserializeBookEntry(std::string& csvEntry);

    std::vector<BookEntry> ingestFile(const std::string &path);

    std::string serializeGenres(const Book &book);

    std::set<Genre> deserializeGenres(std::string& genresString);

    void exportFile(const std::string &path, const std::vector<BookEntry>& bookEntries);
}
#endif //LIBRARY_CSVHANDLER_H
