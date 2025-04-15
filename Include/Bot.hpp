#ifndef BOT_HPP
#define BOT_HPP

#include "Field.hpp"
#include "Utils.hpp"


class Bot {
public:
    virtual void makeStep(FieldInteractor &field) = 0;
};


class EasyBot : public Bot{
public:
    void makeStep(FieldInteractor &field);
};


#endif // BOT_HPP
