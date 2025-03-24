#include "Utils.hpp"


void utils::log(const std::string &message) {
    std::cout << message << '\n';
}

int utils::getRandomNumberBetween(int min, int max) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen(static_cast<unsigned>(seed));
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}
