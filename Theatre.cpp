#include"Theatre.h"
//PriceException::PriceException() : exception("Price must be higher than 0!") {};

void Theatre::setName(string name) { this->name = name; };

void Theatre::setPlayName(string namePlay) { this->namePlay = namePlay; }

void Theatre::setTime(string time) { this->startTime = time; }

void Theatre::setPrice(string price) {
    if (price =="") {
       // throw PriceException();
    }
    this->price = price;
}

void Theatre::place_play() {
    this->city = city;
}
