#include "Logger.hpp"


FileLogger::FileLogger(const File &logFile) 
    : _logFile(logFile)
{}

void FileLogger::log(const std::string &message) const {
    FileWriter fileWriter;
    std::string currentDate = utils::getCurrentDateTime();
    std::string logString = "[" + currentDate + "] " + message + "\n";
    fileWriter.appendToFile(_logFile, logString);
}

void ConsoleLogger::log(const std::string &message) const {
    std::cout << message << '\n';
}
