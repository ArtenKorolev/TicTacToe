#ifndef _BOTFACTORY_HPP_
#define _BOTFACTORY_HPP_


#include <memory>
#include "Bot.hpp"
#include "Field.hpp"


class BotFactory {
public:
    static std::unique_ptr<Bot> getBot();
};


#endif // _BOTFACTORY_HPP_
