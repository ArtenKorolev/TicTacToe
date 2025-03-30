#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "Logger.hpp"


const File GAME_LOG_FILE{"TicTacToe_logs.txt", "./"};
const File ERROR_LOG_FILE{"TicTacToe_errors.txt", "./"};

const ConsoleLogger GAME_CONSOLE_LOGGER;
const FileLogger GAME_FILE_LOGGER(GAME_LOG_FILE);
const FileLogger ERROR_FILE_LOGGER(ERROR_LOG_FILE);


#endif // GLOBALS_HPP
