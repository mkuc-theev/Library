//
// Created by steam on 1/26/2024.
//


#include "headers/CSVHandler.h"
namespace CSVHandler {
    std::string serializeBookEntry(const BookEntry &entry) {
        std::stringstream ss;
        ss << entry.getTitle() << '\t'
           << entry.getAuthor() << '\t'
           << entry.getNumOfPages() << '\t'
           << entry.getReleaseYear() << '\t'
           << entry.getNumOfCopies() << '\t'
           << serializeGenres(entry) << std::endl;

        return ss.str();
    }

    BookEntry deserializeBookEntry(std::string& csvEntry) {
        std::vector<std::string> tokens;
        size_t pos;
        while ((pos = csvEntry.find('\t')) != std::string::npos) {
            tokens.push_back(csvEntry.substr(0, pos));
            csvEntry.erase(0, pos + 1);
        }
        tokens.push_back(csvEntry);

        return BookEntry(
                tokens.at(0),
                tokens.at(1),
                std::stoi(tokens.at(2), nullptr, 10),
                std::stoi(tokens.at(3), nullptr, 10),
                std::stoi(tokens.at(4), nullptr, 10),
                deserializeGenres(tokens.at(5))
        );
    }

    std::vector<BookEntry> importFile(const std::string &path) {
        std::vector<BookEntry> result;
        std::ifstream inputFile(path);
        std::string line;
        if(inputFile.is_open()) {
            while(std::getline(inputFile, line)) {
                result.push_back(deserializeBookEntry(line));
            }
            inputFile.close();
            return result;
        } else {
            throw std::runtime_error("Couldn't open file.");
        }
    }

    void exportFile(const std::string &path, const Library &library) {
        std::ofstream outputFile(path);
        if(outputFile.is_open()) {
            for (const BookEntry &entry : library.getBookEntries()) {
                outputFile << serializeBookEntry(entry);
            }
            outputFile.close();
        } else {
            throw std::runtime_error("Couldn't open file.");
        }
    }

    std::string serializeGenres(const BookEntry &entry) {
        const std::set<Genre>& genres = entry.getGenres();
        std::stringstream ss;
        std::set<Genre>::iterator itr;
        for (itr = genres.begin(); itr != genres.end(); ++itr) {
            ss << GenreToString(*itr) << (itr == --genres.end() ? "" : "|");
        }
        return ss.str();
    }

    std::set<Genre> deserializeGenres(std::string& genresString) {
        std::set<Genre> result;
        size_t pos;
        while ((pos = genresString.find('|')) != std::string::npos) {
            result.insert(
                    GenreFromString(
                            genresString.substr(0, pos)
                            )
                    );
            genresString.erase(0, pos + 1);
        }
        result.insert(GenreFromString(genresString));
        return result;
    }
}