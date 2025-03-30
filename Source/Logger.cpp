#include "Logger.hpp"


FileLogger::FileLogger(const File &logFile) 
    : _logFile(logFile)
{}

void FileLogger::log(const std::string &message) const {
    FileWriter fileWriter;
    fileWriter.appendToFile(_logFile, _getLogStringByMessage(message));
}

std::string FileLogger::_getLogStringByMessage(const std::string &message) const {
    std::string currentDate = utils::getCurrentDateTime();
    return "[" + currentDate + "] " + message + "\n";
}

void ConsoleLogger::log(const std::string &message) const {
    std::cout << message << '\n';
}
