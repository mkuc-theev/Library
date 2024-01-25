//
// Created by Michał Kuć on 18/12/2023.
//

#include "Book.h"

#include <utility>
#include <sstream>

Book::Book(std::string title, std::string author, unsigned int numOfPages, unsigned int releaseYear,
           std::set<Genre> genres) {
    this -> title = std::move(title);
    this -> author = std::move(author);
    this -> numOfPages = numOfPages;
    this -> releaseYear = releaseYear;
    this -> genres = std::move(genres);
}

std::string Book::toString(bool singleLine) {
    std::stringstream ss;
    if (singleLine) {
        ss << "{ Title: \"" << title
           << "\", Author: " << author
           << ", Number of pages: " << numOfPages
           << ", Release year: " << releaseYear
           << ", Genres: [ ";
        std::set<Genre>::iterator itr;
        for (itr = genres.begin(); itr != genres.end(); ++itr) {
            ss << GenreToString(*itr)
               << (itr == --genres.end() ? " " : ", ");
        }
        ss << "] }";
    } else {
        ss << "{ " << std::endl
           << "    Title: \"" << title << "\"," << std::endl
           << "    Author: " << author << ',' << std::endl
           << "    Number of pages: " << numOfPages << ',' << std::endl
           << "    Release year: " << releaseYear << ',' << std::endl
           << "    Genres: [ ";
        std::set<Genre>::iterator itr;
        for (itr = genres.begin(); itr != genres.end(); ++itr) {
            ss << GenreToString(*itr) << (itr == --genres.end() ? " " : ", ");
        }
        ss << "]\n}";
    }
    return ss.str();
}
