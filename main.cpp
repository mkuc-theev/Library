#include <iostream>
#include "Book.h"

int main() {
    std::set<Genre> genres = {Genre::CRIME, Genre::SCI_FI, Genre::HORROR, Genre::COMIC};
    Book book1 = Book("Book", "Book Writer", 690, 1987, genres);
    std::cout << book1.toString(true) << std::endl << book1.toString(false);
    return 0;
}
