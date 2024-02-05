//
// Created by steam on 2/2/2024.
//

#include "headers/RepositorySorter.h"

namespace  RepositorySorter {

    std::vector<BookEntry> mergeSort(
            const std::vector<BookEntry>::iterator start,
            const std::vector<BookEntry>::iterator end,
            bool (*comparator)(const BookEntry&, const BookEntry&)) {
        if (start >= end) {
            return {*end};
        }

        auto midpoint = std::distance(start, end) / 2 + start;
        std::vector<BookEntry> sortedVectorA = mergeSort(
                start,
                midpoint,
                comparator
        );
        std::vector<BookEntry> sortedVectorB = mergeSort(
                midpoint + 1,
                end,
                comparator
        );

        std::vector<BookEntry> result;
        result.reserve(sortedVectorA.size() + sortedVectorB.size());
        auto itA = sortedVectorA.begin();
        auto itB = sortedVectorB.begin();

        while (result.size() < sortedVectorA.size() + sortedVectorB.size()) {
            if (comparator(*itA, *itB)) {
                result.push_back(*itA);
                if (itA == sortedVectorA.end() - 1) {
                    result.insert(result.end(), itB, sortedVectorB.end());
                    continue;
                }
                itA++;
            } else {
                result.push_back(*itB);
                if (itB == sortedVectorB.end() - 1) {
                    result.insert(result.end(), itA, sortedVectorA.end());
                    continue;
                }
                itB++;
            }
        }
        return result;
    }

    std::vector<BookEntry> insertionSort(std::vector<BookEntry>& inputVec,
            bool (*comparator)(const BookEntry&, const BookEntry&)) {
        if(inputVec.size() <= 1) {
            return inputVec;
        }
        std::vector<BookEntry> resultVec;
        resultVec.reserve(inputVec.size());
        resultVec.push_back(inputVec[0]);
        for (auto inputIt = inputVec.begin() + 1; inputIt != inputVec.end(); ++inputIt) {
            auto resultIt = resultVec.end() - 1;
            if (comparator(*resultIt, *inputIt) || !comparator(*inputIt, *resultIt)) {
                resultVec.push_back(*inputIt);
            } else {
                while (resultIt >= resultVec.begin() && !comparator(*resultIt, *inputIt)) {
                    --resultIt;
                }
                resultVec.insert(resultIt + 1, *inputIt);
            }
        }
        return resultVec;
    }

}