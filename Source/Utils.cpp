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

std::string utils::getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();

    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    std::tm* now_tm = std::localtime(&now_time_t);

    std::ostringstream oss;
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
    oss << buffer;
    return oss.str();
}

