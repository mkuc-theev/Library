//
// Created by Michał Kuć on 18/12/2023.
//

#ifndef LIBRARY_GENRE_H
#define LIBRARY_GENRE_H

#include <iostream>
#include <string>
#include <map>

enum class Genre {
    HORROR, FANTASY, ROMANCE, SCI_FI, NON_FICTION, BIOGRAPHY, HISTORY,
    SELF_HELP, THRILLER, CRIME, COMIC, POETRY, PLAY, COOKING,
};

const std::map<std::string, Genre> genreStringMap {
        {"Horror", Genre::HORROR},
        {"Fantasy", Genre::FANTASY},
        {"Romance", Genre::ROMANCE},
        {"Science Fiction", Genre::SCI_FI},
        {"Non-fiction", Genre::NON_FICTION},
        {"Biography", Genre::BIOGRAPHY},
        {"Historical", Genre::HISTORY},
        {"Self Help", Genre::SELF_HELP},
        {"Thriller", Genre::THRILLER},
        {"Crime", Genre::CRIME},
        {"Comic Book", Genre::COMIC},
        {"Poetry", Genre::POETRY},
        {"Theatrical Play", Genre::PLAY},
        {"Cookbook", Genre::COOKING},
};

std::string GenreToString(Genre genre);

Genre GenreFromString(const std::string& genreString);

#endif //LIBRARY_GENRE_H
