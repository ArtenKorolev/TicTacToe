#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include "File.hpp"
#include "Utils.hpp"


class FileLogger {
public:
    FileLogger(const File &logFile);
    void log(const std::string &message);
private:
    const File _logFile;
};


class ConsoleLogger {
public:
    ConsoleLogger(const File &logFile);
    void log(const std::string &message);
private:
    const File _logFile;
};


#endif // LOGGER_HPP
