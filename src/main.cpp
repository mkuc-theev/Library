#include <iostream>
#include "headers/Library.h"
#include"headers/CSVHandler.h"

int main() {
    std::set<Genre> genres = {Genre::CRIME, Genre::SCI_FI, Genre::HORROR, Genre::COMIC};
    std::set<Genre> genres2 = {Genre::CRIME, Genre::SCI_FI, Genre::COOKING};

    BookEntry book1 = BookEntry("Book", "Book Writer", 690, 1987,3, genres);
    BookEntry book1Copy = BookEntry("Book", "Book Writer", 690, 1987, 2,genres);
    BookEntry book2 = BookEntry("BookTwo", "Another Book Writer", 420, 1969, 1, genres2);

    Library mainLib;

    mainLib.addBookEntry(book1);
    mainLib.addBookEntry(book2);
    mainLib.addBookEntry(book1Copy);

    mainLib.removeBookEntry(book1, 5);

    CSVHandler::exportFile("file.tsv", mainLib);

    Library secondaryLib(CSVHandler::importFile("file.tsv"));

    std::cout << secondaryLib.toString();

    return 0;
}
