//
// Created by steam on 1/26/2024.
//


#include "CSVHandler.h"
namespace CSVHandler {
    std::string serializeBookEntry(const BookEntry &bookEntry) {
        Book book = bookEntry.book;
        std::stringstream ss;
        ss << book.getTitle() << ','
           << book.getAuthor() << ','
           << book.getNumOfPages() << ','
           << book.getReleaseYear() << ','
           << serializeGenres(book) << ','
           << bookEntry.numOfCopies << std::endl;
        return ss.str();
    }

    BookEntry deserializeBookEntry(std::string& csvEntry) {
        std::vector<std::string> tokens;
        size_t pos;
        while ((pos = csvEntry.find(',')) != std::string::npos) {
            tokens.push_back(csvEntry.substr(0, pos));
            csvEntry.erase(0, pos + 1);
        }
        tokens.push_back(csvEntry);

        BookEntry result = {
                Book(
                        tokens.at(0),
                        tokens.at(1),
                        std::stoi(tokens.at(2), nullptr, 10),
                        std::stoi(tokens.at(3), nullptr, 10),
                        deserializeGenres(tokens.at(4))
                        ),
                        static_cast<unsigned int>(std::stoi(tokens.at(5), nullptr, 10))

        };

        return result;
    }

    std::vector<BookEntry> ingestFile(const std::string &path) {
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
            for (const BookEntry &book : library.getBookEntries()) {
                outputFile << serializeBookEntry(book);
            }
            outputFile.close();
        } else {
            throw std::runtime_error("Couldn't open file.");
        }
    }

    std::string serializeGenres(const Book &book) {
        const std::set<Genre>& genres = book.getGenres();
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