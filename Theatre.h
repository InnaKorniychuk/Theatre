#pragma once
#include <iostream>
#include <string>
#include <exception>
using std::exception;
using std::string;
using std::cout;
using std::endl;
#pragma once

class PriceException :public exception {
public:
   // PriceException();
};

class Theatre {
    string city;
    string name;
    //string namePlay;
    string startTime;
    string price;
protected:
    void place_of_play(string city) { this->city = city; };
    string place() { return "Called a method from protected field in theatre class"; };

public:
    string namePlay;
    string getName() { return name; }
    void setName(string name);
    string getPlayName() { return namePlay; }
    void setPlayName(string namePlay);
    string getTime() { return startTime; }
    void setTime(string time);
    string getPrice() { return price; }
    void setPrice(string price);
    string get_city()const { return city; }

    Theatre() {
        name = "";
        namePlay = "";
        startTime = "";
        price = "";
    }
    Theatre(string n, string pn, string st, string p) {
        name = n;
        namePlay = pn;
        startTime = st;
        price = p;

    }


    void operator=(int) { this->price = price; };
   // void operator++() { this->price++; };
    //void operator++(int) { this->price++; };
    void operator--() { this->printInfo(); };
    void operator--(int) { this->printInfo(); };
  //  void operator-=(int) { this->price -= price; };
    //void operator+=(int) { this->price += price; };
    void printInfo() {
        cout << "Theatre name: " << name << endl;
        cout << "Play name: " << namePlay << endl;
        cout << "Start time: " << startTime << endl;
        cout << "Price: " << price << endl;
        cout << place() << endl;
    };

    virtual void place_play() = 0;

};

