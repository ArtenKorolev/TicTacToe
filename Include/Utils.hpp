#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>


namespace utils 
{

void log(const std::string &message);

int getRandomNumberBetween(int min, int max);

std::string getCurrentDateTime();

}


#endif // UTILS_HPP
