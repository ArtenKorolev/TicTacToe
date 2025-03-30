#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include "File.hpp"
#include "Utils.hpp"


class FileLogger {
public:
    FileLogger(const File &logFile);
    void log(const std::string &message) const;
private:
    std::string _getLogStringByMessage(const std::string &message) const ;
    const File _logFile;
};


class ConsoleLogger {
public:
    void log(const std::string &message) const;
};


#endif // LOGGER_HPP
