#include "Tickets.h"
CountOfTicketsException::CountOfTicketsException() :exception("The count of tickets must be greater than 0") {};

void Tickets::place_play() {
    place_of_play("Chernihiv");
}

void Tickets::setSoldTickets(int soldQuantity) {
    if (soldQuantity <= 0)
        throw CountOfTicketsException();
    this->soldQuantity = soldQuantity;
}

void Tickets::setBookTickets(int bookQuantity) {
    if (bookQuantity <= 0)
        throw CountOfTicketsException();
    this->bookQuantity = bookQuantity;
}

int Tickets::getBookTickets() {
    return bookQuantity;
}

void Tickets::setTickets(int totalQuantity) {
    if (totalQuantity <= 0)
        throw CountOfTicketsException();
    this->totalQuantity = totalQuantity;
}

int Tickets::getTickets() {
    return totalQuantity;
}

void Tickets::setAvailiableTeckets(int availableQuantity) {
    if (availableQuantity <= 0)
        throw CountOfTicketsException();
    this->availableQuantity = availableQuantity;
}

int Tickets::getAvailableTickets() {
    return availableQuantity;
}

void Tickets::book() {
    bookQuantity++;
    availableQuantity--;
}

void Tickets::buy() {
    bookQuantity--;
    soldQuantity++;
    availableQuantity = totalQuantity - bookQuantity - soldQuantity;
}
bool Tickets::returnTicket() {
    soldQuantity--;
    availableQuantity++;
    return true;
}

bool Tickets::changeTicket() {
    return true;
}

void operator*=(Tickets& A, int new_bookQuantity) // встановити нове значення bookQuantity
{
    A.bookQuantity = new_bookQuantity;
}

void Tickets::operator--() { //аналог методу printInfo (префіксний) (функціонал однаковий)
    this->printInfo();
}
void Tickets::operator--(int) { //аналог методу printInfo  (функціонал однаковий)
    this->printInfo();
}
void Tickets::operator++() {
    this->availableQuantity++;
}
void Tickets::operator++(int) {
    this->availableQuantity++;
}

void ToShowOverride() {
    cout << "Tickets class" << endl;
}

void Tickets::printInfo() {
    cout << "Theatre name: " << getName() << endl;
    cout << "Play name: " << getPlayName() << endl;
    cout << "Start time: " << getTime() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Sold quantity: " << soldQuantity << endl;
    cout << "Booked quantity: " << bookQuantity << endl;
    cout << "Total quantity: " << totalQuantity << endl;
    cout << "Aveilable quantity: " << availableQuantity << endl;
}
