#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>


struct File {
    std::string name;
    std::string path;
};


class FileWriter {
public:
    void writeFile(const File &file, const std::string &content);
};


#endif // FILE_HPP
