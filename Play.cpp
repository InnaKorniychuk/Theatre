#include "Play.h"
Play::Play(std::vector<std::string> play_data) {
     this->setName(play_data[0]);
     this->setPlayName(play_data[1]);
     this->setTime(play_data[2]);
     this->setPrice(play_data[3]);
     this->setDuration(play_data[4]);
   //  this->setDescription(play_data[5]);
     this->actorList = play_data[5];
}
void Play::setDescription(string description) {
    this->description = description;
}

void Play::setDuration(string duration) {
    this->duration = duration;
}


string Play::getDescription() {
    return description;
}

string Play::getDuration() {
    return duration;
}

void Play::setActors(string actorList) {
    this->actorList = actorList;
}


string Play::getActors() {
    return actorList;
}

void Play::setTickets(string tickets) {
    this->tickets = tickets;
}

string Play::getTickets() {
    return tickets;
}

void Play::operator--() { //аналог методу printInfo (префіксний) (функціонал однаковий)
    this->printInfo();
}
void  Play::operator--(int) { //аналог методу printInfo (постфіксний)
    this->printInfo();
}

void Play::place_play() {
    place_of_play("Lviv");
}

void Play::printInfo() {
    cout << "Theatre name: " << getName() << endl;
    cout << "Play name: " << getPlayName() << endl;
    cout << "Start time: " << getTime() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Duration: " << getDuration() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Actors: " << getActors() << endl;

}
bool operator<(Play lhs, Play rhs) {
    return std::vector<std::string>({ lhs.getName(), lhs.getPlayName(), lhs.getTime(), lhs.getPrice(),lhs.getDuration(),lhs.getDescription()
        ,lhs.getActors()}) <
        std::vector<std::string>({ rhs.getName(), rhs.getPlayName(), rhs.getTime(), rhs.getPrice(),rhs.getDuration(),rhs.getDescription()
        ,rhs.getActors() });
}
