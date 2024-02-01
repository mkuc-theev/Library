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

namespace TSVHandler {
    std::string serializeBookEntry(const BookEntry &bookEntry);

    BookEntry deserializeBookEntry(std::string& entryString);

    std::vector<BookEntry> importFile(const std::string &path);

    std::string serializeGenres(const BookEntry &entry);

    std::set<Genre> deserializeGenres(std::string& genresString);

    void exportFile(const std::string &path, const BookRepository &library);
}
#endif //LIBRARY_TSVHANDLER_H
