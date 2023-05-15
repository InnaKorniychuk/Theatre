#pragma once
#include "Theatre.h"
class CountOfTicketsException :public exception {
public:
    CountOfTicketsException();
};

class Tickets : public Theatre {
    int soldQuantity;
    int bookQuantity;
    int totalQuantity;
    int availableQuantity;

public:
    void setSoldTickets(int soldQuantity);
    int getBookTickets();
    void setBookTickets(int bookQuantity);
    int getTickets();
    void setTickets(int totalQuantity);
    int getAvailableTickets();
    void setAvailiableTeckets(int availableQuantity);
    void book();
    void buy();
    bool returnTicket();
    bool changeTicket();
    void printInfo();
    void place_play();


    Tickets(string n, string pn, string st, string p, int so, int book, int tot, int ave) :Theatre(n, pn, st, p) {
        soldQuantity = so;
        bookQuantity = book;
        totalQuantity = tot;
        availableQuantity = ave;
    }

    Tickets() :Theatre() {
        soldQuantity = 0;
        bookQuantity = 0;
        totalQuantity = 0;
        availableQuantity = 0;
    }

    void operator--();
    void operator--(int);
    void operator++();
    void operator++(int);
    friend void operator*=(Tickets&, int);

};
