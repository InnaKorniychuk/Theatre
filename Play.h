#pragma once
#include "Theatre.h"
#include <vector>

class Play : public Theatre {
    string duration;
    string description;
    string actorList;
    string tickets;

public:

    string getDescription();
    void setDescription(string description);
    string getDuration();
    void setDuration(string duration);
    string getActors();
    void setActors(string actorList);
    void printInfo();
    void setTickets(string tickets);
    string getTickets();
    void place_play();

    Play(std::vector<std::string> play_data);
    Play(string n, string pn, string st, string p, string dur, string des, string ac,string tic)
        :Theatre(n, pn, st, p)
    {
        duration = dur;
        description = des;
        actorList = ac;
        tickets = tic;
    }

    Play() : Theatre() {

        duration = "";
        description = "";
        actorList = "";
    }

    void operator--();
    void operator--(int);
    /*~Play() {
        cout << "Theatre was delated" << endl;
    }*/

};
bool operator<(Play lhs, Play rhs);
//"<" operator overload to allow usage of Student objects in "set" container - Перевантаження оператора "<", щоб дозволити використання об’єктів Student у контейнері "set"