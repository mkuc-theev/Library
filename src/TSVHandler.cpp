#include "headers/TSVHandler.h"

namespace TSVHandler {
    std::string serializeBookEntry(BookEntry &entry) {
        std::stringstream ss;
        ss << entry.getTitle() << '\t'
           << entry.getAuthor() << '\t'
           << entry.getNumOfPages() << '\t'
           << entry.getReleaseYear() << '\t'
           << entry.getNumOfCopies() << '\t'
           << serializeGenres(entry) << std::endl;

        return ss.str();
    }

    BookEntry deserializeBookEntry(std::string &entryString) {
        std::vector<std::string> tokens;
        size_t pos;
        //Tokenize each line by finding delimiter, then erasing the start of the string until the delimiter
        while ((pos = entryString.find('\t')) != std::string::npos) {
            std::string token = entryString.substr(0, pos);
            if (token.empty()) {
                throw std::ios_base::failure("Null value found in input file!");
            }
            std::regex negativeNumberRegex("^-\\d+$");
            if (std::regex_match(token, negativeNumberRegex)) {
                throw std::ios_base::failure("Negative numerical value found in input file!");
            }
            tokens.push_back(token);
            entryString.erase(0, pos + 1);
        }
        //After tokenization, all that's left in the entry string is the last token
        tokens.push_back(entryString);
        try {
            return {
                    tokens.at(0),
                    tokens.at(1),
                    static_cast<unsigned int>(std::stoi(tokens.at(2), nullptr, 10)),
                    static_cast<unsigned int>(std::stoi(tokens.at(3), nullptr, 10)),
                    static_cast<unsigned int>(std::stoi(tokens.at(4), nullptr, 10)),
                    deserializeGenres(tokens.at(5))
            };
        } catch (std::exception &e) {
            throw std::runtime_error("File import error! Couldn't build BookEntry object.");
        }
    }

    std::vector<BookEntry> importFile(const std::string &path) {
        std::vector<BookEntry> result;
        std::ifstream inputFile(path);
        std::string line;
        if (inputFile.is_open()) {
            while (std::getline(inputFile, line)) {
                result.push_back(deserializeBookEntry(line));
            }
            inputFile.close();
            return result;
        } else {
            throw std::runtime_error("Couldn't open file.");
        }
    }

    void exportFile(const std::string &path, BookRepository &bookRepository) {
        std::ofstream outputFile(path);
        if (outputFile.is_open()) {
            for (BookEntry &entry: bookRepository.getBookEntries()) {
                outputFile << serializeBookEntry(entry);
            }
            outputFile.close();
        } else {
            throw std::runtime_error("Couldn't open file.");
        }
    }

    std::string serializeGenres(BookEntry &entry) {
        const std::set<Genre> &genres = entry.getGenres();
        std::stringstream ss;
        std::set<Genre>::iterator itr;
        for (itr = genres.begin(); itr != genres.end(); ++itr) {
            //Ternary operator for putting '|' between genres but not after the last one
            ss << GenreToString(*itr) << (itr == --genres.end() ? "" : "|");
        }
        return ss.str();
    }

    std::set<Genre> deserializeGenres(std::string &genresString) {
        std::set<Genre> result;
        size_t pos;
        try {
            //Similar tokenizer to the deserializeBookEntry function.
            while ((pos = genresString.find('|')) != std::string::npos) {
                result.insert(
                        GenreFromString(
                                genresString.substr(0, pos)
                        )
                );
                genresString.erase(0, pos + 1);
            }
            result.insert(GenreFromString(genresString));
        } catch (std::exception &e) {
            throw e;
        }
        return result;
    }
}