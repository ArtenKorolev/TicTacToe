#include "Utils.hpp"


void utils::log(const std::string &message) {
    std::cout << message << '\n';
}

int utils::getRandomNumberBetween(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}
