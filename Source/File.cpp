#include "File.hpp"


void FileWriter::appendToFile(const File &file, const std::string &content) {
    std::ofstream outFile(file.path + file.name, std::ios::app);

    if (!outFile) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    outFile << content;
    outFile.close();
}
