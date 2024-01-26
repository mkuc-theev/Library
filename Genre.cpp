//
// Created by steam on 1/26/2024.
//
#include "Genre.h"

std::string GenreToString(Genre genre) {
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

Genre GenreFromString(const std::string& genreString) {
    return genreStringMap.find(genreString)->second;
}
