#include "Logger.hpp"


FileLogger::FileLogger(const File &logFile) 
    : _logFile(logFile)
{}

void FileLogger::log(const std::string &message) {
    FileWriter fileWriter;
    fileWriter.appendToFile(_logFile, message);
}

ConsoleLogger::ConsoleLogger(const File &logFile) 
    : _logFile(logFile)
{}

void ConsoleLogger::log(const std::string &message) {
    std::cout << message << '\n';
}
