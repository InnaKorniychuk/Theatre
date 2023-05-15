#include <iostream>
#include <conio.h>
#include <set>
#include <fstream>
#include <vector>
#include <Windows.h>

#include "Play.h"
#include "User.h"
#include "Session.h"

//Contains main loops of the program - Містить основні цикли програми
//Outer loop that enters session or quits it - Зовнішній цикл, який входить у сеанс або виходить з нього
//Inner loop inside of which you do commands as either ADMIN or GUEST - Внутрішній цикл, у якому ви виконуєте команди як АДМІНІСТРАТОР або ГІСТЬ
//Loops are controlled via _getch() capturing input from key, correct key will either invoke matching function or break the loop - Цикли контролюються за допомогою _getch(), що фіксує вхідні дані з ключа, правильний ключ або викличе функцію відповідності, або розірве цикл


int main()
{
    while (true) {//outer loop, session creation and quitting program - зовнішній цикл, створення сеансу та вихід з програми
        std::cout << "Starting new session...\n";

        Session session;
        session.StartSession();
       // session.StartAsAdmin();
        session.fileWork.LoadData(session.fileWork.path, session.plays);

        while (true) {// admin/guest commands loop - цикл команд admin/guest
            std::cout << "\n";
            Sleep(1500);
            session.SessionCheck();
            if (session.IfAdminSession()) {
                std::cout << "Available admin operations:\n";
                std::cout << "1) Print all students\n";
               // std::cout << "2) Search by name\n";
                std::cout << "3) Delete student\n";
                std::cout << "4) Add student\n";
            //    std::cout << "5) Change student data\n";
                std::cout << "Type 'number' to choose operation, 'q' to quit admin session and save changed data...\n";
                char cmd3;
                while (cmd3 = _getch()) {
                    if (cmd3 == '1') {
                        std::cout << cmd3 << "\n";
                        session.PrintAll();
                        break;
                    }
                    /*else if (cmd3 == '2') {
                        std::cout << cmd3 << "\n";
                        std::pair<bool, Student> search = session.FindByName();
                        if (search.first) {
                            std::cout << "Found student:\n";
                            session.PrintStudentData(search.second);
                        }
                        else {
                            std::cout << "Didn't find such student!\n";
                        }
                        break;
                    }*/
                    else if (cmd3 == '3') {
                        std::cout << cmd3 << "\n";
                        session.DeletePlay();
                        break;
                    }
                    else if (cmd3 == '4') {
                        std::cout << cmd3 << "\n";

                        session.AddPlay();
                        break;
                    }
                   /* else if (cmd3 == '5') {
                        std::cout << cmd3 << "\n";
                      //  session.ChangeStudentData();
                        break;
                    }*/
                    else if (cmd3 == 'q') {
                        std::cout << cmd3 << "\n";
                        session.fileWork.WriteAllData(session.fileWork.path, session.plays);
                        session.fileWork.WriteAllData(session.fileWork.backup_path, session.plays);
                        std::cout << "Quitting admin session...\n";
                        break;
                    }
                    else {
                        std::cout << cmd3 << " - Wrong command!" << "\n";
                        Sleep(200);
                      /*  std::cout << "\n";
                        std::cout << "Available admin operations:\n";
                        std::cout << "1) Print all students\n";
                     //   std::cout << "2) Search by name\n";
                        std::cout << "3) Delete student\n";
                        std::cout << "4) Add student\n";
                      //  std::cout << "5) Change student data\n";
                        std::cout << "Type 'number' to choose operation, 'q' to quit admin session and save changed data...\n";*/
                    }
                }
                if (cmd3 == 'q') {
                    break;
                }
                else {
                    continue;
                }
            }
            else {
                std::cout << "Available guest operations:\n";
                std::cout << "1) Print all plays\n";
              //  std::cout << "2) Search by name\n";
                std::cout << "Buy tickets\n";
                std::cout << "Type 'number' to choose operation, 'q' to go quit guest session...\n";
                char cmd3;
                while (cmd3 = _getch()) {
                    if (cmd3 == '1') {
                        session.PrintAll();
                        break;
                    }
                   /* else if (cmd3 == '2') {
                        std::pair<bool, Student> search = session.FindByName();
                        if (search.first) {
                            std::cout << "Found student:\n";
                            session.PrintStudentData(search.second);
                        }
                        else {
                            std::cout << "Didn't find such student!\n";
                        }
                        break;
                    }*/
                    else if (cmd3 == '2') {
                        session.BuyTickets();
                        //std::pair<bool, Play> search = session.FindByName();
                       /* if (search.first) {
                            std::cout << "Found student:\n";
                            session.PrintStudentData(search.second);
                        }
                        else {
                            std::cout << "Didn't find such student!\n";
                        }*/
                        break;
                    }
                    else if (cmd3 == 'q') {
                        std::cout << "Quitting guest session...\n";
                        break;
                    }
                    else {
                        std::cout << cmd3 << " - Wrong command!" << "\n";
                        Sleep(200);
                        std::cout << "\n";
                        std::cout << "Available guest operations:\n";
                        std::cout << "1) Print all students\n";
                        std::cout << "2) Search by name\n";
                        std::cout << "Type 'number' to choose operation, 'q' to quit admin session and save changed data...\n";
                    }
                }
                if (cmd3 == 'q') {
                    break;
                }
                else {
                    continue;
                }
            }
        }

        std::cout << "\nType 'y' to start new session, 'q' to exit program\n";
        char cmd1;
        while (cmd1 = _getch()) {
            Sleep(100);
            if (cmd1 == 'y') {
                std::cout << cmd1 << "\n" << "\n";
                break;
            }
            else if (cmd1 == 'q') {
                std::cout << cmd1 << "\n" << "\n";
                break;
            }
        }
        if (cmd1 == 'y') {
            continue;
        }
        else if (cmd1 == 'q') {
            std::cout << "Exiting program...\n";
            break;
        }
    }
   // _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
   // _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
    std::cout << "Progam finished!\n";
    return 1;
}

