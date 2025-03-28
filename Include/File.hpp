#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>


struct File {
    std::string name, path;
};


class FileWriter {
public:
    void appendToFile(const File &file, const std::string &content);
};


#endif // FILE_HPP
