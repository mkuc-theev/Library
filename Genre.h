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

constexpr const char* GenreToString(Genre genre) {
    switch(genre) {
        case Genre::HORROR: return "Horror";
        case Genre::FANTASY: return "Fantasy";
        case Genre::ROMANCE: return "Romance";
        case Genre::SCI_FI: return "Science Fiction";
        case Genre::NON_FICTION: return "Non-fiction";
        case Genre::BIOGRAPHY: return "Biography";
        case Genre::HISTORY: return "Historical";
        case Genre::SELF_HELP: return "Self Help";
        case Genre::THRILLER: return "Thriller";
        case Genre::CRIME: return "Crime";
        case Genre::COMIC: return "Comic Book";
        case Genre::POETRY: return "Poetry";
        case Genre::PLAY: return "Theatrical Play";
        case Genre::COOKING: return "Cookbook";
        default: throw std::invalid_argument("Genre does not exist");
    }
}

Genre GenreFromString(std::string genreString) {
    return genreStringMap.find(genreString)->second;
}

#endif //LIBRARY_GENRE_H
