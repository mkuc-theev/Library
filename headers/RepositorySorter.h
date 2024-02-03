//
// Created by steam on 2/2/2024.
//

#ifndef LIBRARY_REPOSITORYSORTER_H
#define LIBRARY_REPOSITORYSORTER_H


#include <vector>
#include "BookEntry.h"

namespace RepositorySorter {

    std::vector<BookEntry> mergeSort(const std::vector<BookEntry>::iterator start,
                                     const std::vector<BookEntry>::iterator end,
                                     bool (*comparator)(const BookEntry&, const BookEntry&));
    std::vector<BookEntry> insertionSort();
};


#endif //LIBRARY_REPOSITORYSORTER_H
