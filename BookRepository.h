//
// Created by Michał Kuć on 28/12/2023.
//

#ifndef LIBRARY_BOOKREPOSITORY_H
#define LIBRARY_BOOKREPOSITORY_H

#include "Book.h"
#include <vector>

class BookRepository {
private:
    std::vector<Book> books;
public:
    BookRepository();
    void serialize(const char* path);
    void deserialize(const char* path);
    std::string toString();
};


#endif //LIBRARY_BOOKREPOSITORY_H
