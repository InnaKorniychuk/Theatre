#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include "User.h"
#include "Play.h"
#include "FileWork.h"

//Session class stores current logging User and provides methods to operate with data - ���� ������ ������ �������� ������ ����������� �� ���� ������ ��� ������ � ������

class Session
{
public:
	Session();//default constructor - ����������� �� ������������� 
	FileWork fileWork;//object to be able to work with files - ��'��� ��� ��������� ������ � ������� 
	std::set<Play> plays;//"set" object that is used to store data from file in current operating memory and work with that data - "set" ��'���, ���� ��������������� ��� ��������� ����� �� ����� � ������� ���������� ���'�� �� ������ � ���� ������

	void StartSession();//starts entering user - ������ ������� ����������� 
	void StartAsAdmin();//helper function if you want to skip logging in and immidiately start as ADMIN - �������� �������, ���� �� ������ ���������� ���� � ������� ������ �� ��̲Ͳ������� 
	bool SessionCheck();//method sends a message to see what type of session you're currently in - ����� ������� �����������, ��� ��������, ���� ��� ������ �� ����� ���������� 
	bool IfAdminSession();//returns 1 if it is an admin session - ������� 1, ���� �� ���� ������������ 

	void PrintAll();//prints out on the screen every Student data that is present in set<Student> - ����� �� ����� ��� ������� ��������, �� ������� � �����<Student> 
	std::pair<bool, Play> FindByName();//starts search and asks for students' name, returns a pair<bool, Student>  - ������ ����� � ������ ����� ��������, ������� ����<bool, Student> 
	//with bool==true if it finds a student with asked name and a matching Student object,  - � bool==true, ���� �� ��������� �������� �� ����������� ������ � ��������� �ᒺ���� Student,
	//or bool==false if such student wasn't found - ��� bool==false, ���� ����� ������� �� ��������
	//std::pair<bool, Play> FindByName1();

	void PrintPlayData(Play play);//helper function, prints out Student data on the screen - �������� �������, ����� ��� �������� �� �����
	void DeletePlay();//starts searching student via FindByName() method, and if found will ask if you want to delete its data from set<Student> - ��������� ����� ���� �� ��������� ������ FindByName(), � ���� ���� ��������, ������, �� ������ �� �������� ���� ��� � ������<Student>
	void AddPlay();//will start input for all Student data fields and ask if you want to confirm adding such Student object - ����� �������� ��� ��� ���� ����� Student � ������, �� ������ �� ���������� ��������� ������ �ᒺ��� Student
	void ChangeStudentData();//starts searching for student via FindByName() method, and if found will ask to input updated data fields(group/number, phone number) - �������� ����� �������� �� ��������� ������ FindByName(), � ���� ��������, ��������� ������ ������� ���� ����� (�����/�����, ����� ��������)
	bool BuyTickets();
private:

	User user;//user object for current session - ��'��� ����������� ��� ��������� ������ 
	bool isAdminSession = 0;//flag to know if session is ADMIN or GUEST type - ���������, ��� ��������, �� � ����� ���� ��̲Ͳ�������� �� �����
};

