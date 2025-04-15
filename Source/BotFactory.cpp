#include "BotFactory.hpp"


std::unique_ptr<Bot> BotFactory::getBot() {
    return std::make_unique<EasyBot>();
}
