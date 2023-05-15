#include "Session.h"
#include <conio.h>

Session::Session() : user() {

}

void Session::StartSession() {
    std::cout << "Hello, enter username('admin' or any name):\n";
    std::string name;
    std::cin >> name;
    if (name != "admin") {
        user.SetName(name);
        std::cout << "Successfully entered as guest with name: " << user.GetUsername() << std::endl;
    }
    else {
        std::cout << "Entering as admin, need password(default '1234'):\n";
        std::string password;
        std::cin >> password;
        if (user.AdminCheck(password)) {
            user.MakeAdmin();
            isAdminSession = true;
            std::cout << "Successfully entered as admin!\n";
        }
        else {
            std::cout << "Failed password, entering as: " << user.GetUsername() << std::endl;
        }
    }
}

void Session::StartAsAdmin() {
    user.MakeAdmin();
    isAdminSession = true;
}

bool Session::SessionCheck() {
    std::string session_type = (isAdminSession) ? "ADMIN" : "GUEST";
    std::cout << "Working in session as: " << session_type << std::endl;
    return isAdminSession;
}

bool Session::IfAdminSession() {
    return isAdminSession;
}

void Session::PrintAll() {
    /*Sleep(1000);
    std::cout << "\x1b[2J\x1b[H";*/
    std::cout << "Printing out all students:\n";
    for (Play play : plays) {
        PrintPlayData(play);
    }
    std::cout << "Printing finished!\n";
}

std::pair<bool, Play> Session::FindByName() {
    std::cout << "Search of a play by name: \n";

  //  std::vector<std::string> desired_person;
    //for (int i = 0; i < 3; ++i) {
      //  std::string word;
        //std::cin >> word;
       // desired_person.push_back(word);
    //}
    std::string name;
    std::cin >> name;
    for (Play play : plays) {
      // std::vector<std::string> this_person = {person.last_name, person.first_name, person.middle_name};
        //if (this_person == desired_person) {
      //    //  return std::pair<bool, Student>(true, person);
        //}
        if (play.getPlayName() == name) {
            return std::pair<bool, Play>(true, play);
        }
    }
    Play not_found;
    return std::pair<bool, Play>(false, not_found);
}



void Session::PrintPlayData(Play play) {
    cout << "Theatre name: " << play.getName() << endl;
    cout << "Play name: " << play.getPlayName() << endl;
    cout << "Start time: " << play.getTime() << endl;
    cout << "Price: " << play.getPrice() << endl;
    cout << "Duration: " << play.getDuration() << endl;
    cout << "Description: " << play.getDescription()<< endl;
    cout << "Actors: " << play.getActors() << endl; "\n";
}

void Session::DeletePlay() {
    std::cout << "Finding student to delete...\n";
    std::pair<bool, Play> search = FindByName();
    if (search.first) {
        std::cout << "Confirm if you want to delete this student('y') or cancel deleting('n'):\n";
        PrintPlayData(search.second);
        char confirm;
        while (confirm = _getch()) {
            std::cout << confirm << "\n";
            if (confirm == 'y') {
                plays.erase(search.second);
                std::cout << "Student data deleted!\n";
                break;
            }
            else if (confirm == 'n') {
                std::cout << "Deleting canceled.\n";
                break;
            }
        }
    }
    else {
        std::cout << "Didn't find such student!\n";
    }
}

void Session::AddPlay() {
    std::cout << "\nAdding student... Enter data:\n";
    Play new_play;
    string name;
    string namePlay;
    string startTime;
    string price;
    //   int soldQuantity;
    //   int bookQuantity;
       int totalQuantity;
      // int aveilableQuantity;
    string duration;
    string description;
    string actorList;
    std::cin.ignore(32767, '\n');//пропускаємо значення нового рядка
    std::cout << "Write the name of theatre: ";
    std::getline(std::cin, name);
    new_play.setName(name);
    std::cout << "Write the name of play: ";
   // std::cin.ignore(32767, '\n');//пропускаємо значення нового рядка
    std::getline(std::cin, namePlay);
    new_play.setPlayName(namePlay); 
   // std::cin.ignore(32767, '\n');//пропускаємо значення нового рядка
    std::cout << "Write the start time(hh.mm.ss): ";
    std::getline(std::cin, startTime);
    new_play.setTime(startTime);

  /*  std::cout << "Write the duration time(hh.mm.ss): ";
    std::getline(std::cin, duration);
    new_play.setTime(duration);*/
   // std::cin.ignore(32767, '\n');//пропускаємо значення нового рядка
    std::cout << "Write price for a ticket: ";
    std::cin >> price;
    new_play.setPrice(price);

   /* std::cout << "Write count of sold tickets: ";
    std::cin >> soldQuantity;

    std::cout << "Write count of booked tickets: ";
    std::cin >> bookQuantity;


    std::cout << "Write count of available tickets: ";
    std::cin >> aveilableQuantity;*/


    std::cout << "Write count of total tickets: ";
    std::cin >> totalQuantity;
    new_play.setTickets(""+totalQuantity);
    //std::cin.ignore(32767, '\n');//пропускаємо значення нового рядка
   // std::cout << "Write the duration of the play(hh.mm.ss): ";
    //std::getline(std::cin, duration);
    new_play.setDuration("duration");
    std::cin.ignore(32767, '\n');//пропускаємо значення нового рядка
    std::cout << "Write the decription of the play: ";
    std::getline(std::cin, description);
    new_play.setDescription(description);

    std::cout << "Write the actor list: ";
    std::getline(std::cin, actorList);
    new_play.setActors(actorList);
    std::cout << "Confirm if data is correct('y') or cancel adding('n'):\n";
    PrintPlayData(new_play);
    char confirm;
    while (confirm = _getch()) {
        std::cout << confirm << "\n";
        if (confirm == 'y') {
            std::cout << "Student data changed!\n";
            plays.insert(new_play);
            break;
        }
        else if (confirm == 'n') {
            std::cout << "Adding canceled.\n";
            break;
        }
    }
   /* std::cout << "Last name: ";
    std::cin >> new_person.last_name;
    std::cout << "First name: ";
    std::cin >> new_person.first_name;
    std::cout << "Middle name: ";
    std::cin >> new_person.middle_name;
    std::cout << "Group name: ";
    std::cin >> new_person.group_name;
    std::cout << "Group number: ";
    std::cin >> new_person.group_number;
    std::cout << "Phone number: ";
    std::cin >> new_person.phone_number;
    std::cout << "Confirm if data is correct('y') or cancel adding('n'):\n";
    PrintStudentData(new_person);
    char confirm;
    while (confirm = _getch()) {
        std::cout << confirm << "\n";
        if (confirm == 'y') {
            std::cout << "Student data changed!\n";
            students.insert(new_person);
            break;
        }
        else if (confirm == 'n') {
            std::cout << "Adding canceled.\n";
            break;
        }
    }*/
}

bool Session::BuyTickets() {
    std::cout << "What play do you choose?\n";
    std::pair<bool, Play> search = FindByName();
    if (search.first) {
        std::cout << "Available tickets: " + search.second.getTickets();
        std::cout << "How many tickets you want to buy: ";
        int tickets;
        std::cin >> tickets;
        if (("" + tickets) > (search.second.getTickets())||tickets<=0) {
            std::cout << "You can't buy this count of tickets.";
            return false;
        }
        std::cout << "Confirm if you want to buy('y') or cancel ('n'):\n";
        PrintPlayData(search.second);
        char confirm;
        while (confirm = _getch()) {
            std::cout << confirm << "\n";
            if (confirm == 'y') {
                plays.erase(search.second);
                std::cout << "You bought tickets!\n";
                break;
            }
            else if (confirm == 'n') {
                std::cout << "You didn't byu tickets.\n";
                break;
            }
        }
    }
    else {
        std::cout << "Didn't find such play!\n";
        return false;
    }
    return true;
}

/*void Session::ChangeStudentData()
{
    std::cout << "Find student to have its data changed:\n";
    std::pair<bool, Student> search = FindByName();
    if (search.first) {
        std::cout << "Found such student:\n";
        PrintStudentData(search.second);
        std::cout << "Enter this student's new data:\n";
        Student temp_person;
        temp_person.last_name = search.second.last_name;
        temp_person.first_name = search.second.first_name;
        temp_person.middle_name = search.second.middle_name;
        std::cout << "Group name: ";
        std::cin >> temp_person.group_name;
        std::cout << "Group number: ";
        std::cin >> temp_person.group_number;
        std::cout << "Phone number: ";
        std::cin >> temp_person.phone_number;
        std::cout << "Confirm if data is correct('y') or cancel adding('n):\n";
        PrintStudentData(temp_person);
        char confirm;
        while (confirm = _getch()) {
            std::cout << confirm << "\n";
            if (confirm == 'y') {
                std::cout << "Student data changed!\n";
                students.erase(search.second);
                students.insert(temp_person);
                break;
            }
            else if (confirm == 'n') {
                std::cout << "Changing canceled.\n";
                break;
            }
        }
    }
    else {
        std::cout << "Didn't find such student!\n";
    }
}*/
