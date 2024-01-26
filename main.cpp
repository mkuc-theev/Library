#include <iostream>
#include "Library.h"
#include"CSVHandler.h"

int main() {
    std::set<Genre> genres = {Genre::CRIME, Genre::SCI_FI, Genre::HORROR, Genre::COMIC};
    std::set<Genre> genres2 = {Genre::CRIME, Genre::SCI_FI, Genre::COOKING};

    Book book1 = Book("Book", "Book Writer", 690, 1987, genres);
    Book book1Copy = Book("Book", "Book Writer", 690, 1987, genres);
    Book book2 = Book("BookTwo", "Another Book Writer", 420, 1969, genres2);

    Library mainLib;

    mainLib.addBook(book1, 4);
    mainLib.addBook(book2,3);
    mainLib.addBook(book1Copy,1);

    CSVHandler::exportFile("file.csv", mainLib);

    Library secondaryLib(CSVHandler::ingestFile("file.csv"));
    std::cout << secondaryLib.toString();

    return 0;
}
