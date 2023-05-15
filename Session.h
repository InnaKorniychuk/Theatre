#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include "User.h"
#include "Play.h"
#include "FileWork.h"

//Session class stores current logging User and provides methods to operate with data - Клас сеансу зберігає поточний журнал користувача та надає методи для роботи з даними

class Session
{
public:
	Session();//default constructor - конструктор за замовчуванням 
	FileWork fileWork;//object to be able to work with files - об'єкт для можливості роботи з файлами 
	std::set<Play> plays;//"set" object that is used to store data from file in current operating memory and work with that data - "set" об'єкт, який використовується для зберігання даних із файлу в поточній операційній пам'яті та роботи з цими даними

	void StartSession();//starts entering user - починає вводити користувача 
	void StartAsAdmin();//helper function if you want to skip logging in and immidiately start as ADMIN - допоміжну функцію, якщо ви хочете пропустити вхід і негайно почати як АДМІНІСТРАТОР 
	bool SessionCheck();//method sends a message to see what type of session you're currently in - метод надсилає повідомлення, щоб дізнатися, який тип сеансу ви зараз перебуваєте 
	bool IfAdminSession();//returns 1 if it is an admin session - повертає 1, якщо це сесія адміністратора 

	void PrintAll();//prints out on the screen every Student data that is present in set<Student> - друкує на екрані дані кожного студента, які присутні в наборі<Student> 
	std::pair<bool, Play> FindByName();//starts search and asks for students' name, returns a pair<bool, Student>  - починає пошук і запитує імена студентів, повертає пару<bool, Student> 
	//with bool==true if it finds a student with asked name and a matching Student object,  - з bool==true, якщо він знаходить студента із запитуваним іменем і відповідним об’єктом Student,
	//or bool==false if such student wasn't found - або bool==false, якщо такий студент не знайдено
	//std::pair<bool, Play> FindByName1();

	void PrintPlayData(Play play);//helper function, prints out Student data on the screen - допоміжна функція, друкує дані студента на екрані
	void DeletePlay();//starts searching student via FindByName() method, and if found will ask if you want to delete its data from set<Student> - розпочинає пошук учня за допомогою методу FindByName(), і якщо буде знайдено, запитає, чи хочете ви видалити його дані з набору<Student>
	void AddPlay();//will start input for all Student data fields and ask if you want to confirm adding such Student object - почне введення для всіх полів даних Student і запитає, чи хочете ви підтвердити додавання такого об’єкта Student
	void ChangeStudentData();//starts searching for student via FindByName() method, and if found will ask to input updated data fields(group/number, phone number) - розпочне пошук студента за допомогою методу FindByName(), і якщо знайдено, попросить ввести оновлені поля даних (група/номер, номер телефону)
	bool BuyTickets();
private:

	User user;//user object for current session - об'єкт користувача для поточного сеансу 
	bool isAdminSession = 0;//flag to know if session is ADMIN or GUEST type - прапорець, щоб дізнатися, чи є сеанс типу АДМІНІСТРАТОРА чи ГОСТЯ
};

