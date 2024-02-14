#ifndef LIBRARY_GENRE_H
#define LIBRARY_GENRE_H

#include <iostream>
#include <string>
#include <map>

/**
 * Enumeration of genre tags allowed by the program.
 */
enum class Genre {
    HORROR, FANTASY, ROMANCE, SCI_FI, NON_FICTION, BIOGRAPHY, HISTORY,
    SELF_HELP, THRILLER, CRIME, COMIC, POETRY, PLAY, COOKING,
};
/**
 * Maps string representations of genre tags to their enumeration counterparts.
 */
const std::map<std::string, Genre> genreStringMap{
        {"Horror",          Genre::HORROR},
        {"Fantasy",         Genre::FANTASY},
        {"Romance",         Genre::ROMANCE},
        {"Science Fiction", Genre::SCI_FI},
        {"Non-fiction",     Genre::NON_FICTION},
        {"Biography",       Genre::BIOGRAPHY},
        {"Historical",      Genre::HISTORY},
        {"Self Help",       Genre::SELF_HELP},
        {"Thriller",        Genre::THRILLER},
        {"Crime",           Genre::CRIME},
        {"Comic Book",      Genre::COMIC},
        {"Poetry",          Genre::POETRY},
        {"Theatrical Play", Genre::PLAY},
        {"Cookbook",        Genre::COOKING},
};

/**
 * Converts a Genre enum value to its string representation.
 * @param genre The enum value to convert.
 * @return String representing the genre tag.
 */
std::string GenreToString(Genre genre);

/**
 * Converts a genre tag string representation to its enum value.
 * @param genreString The string to convert.
 * @return Enum value representing the genre tag.
 */
Genre GenreFromString(const std::string &genreString);

#endif //LIBRARY_GENRE_H