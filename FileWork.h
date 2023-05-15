#pragma once
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Play.h"
#include <set>

//class to store paths to data files and contain methods to read/write from txt files - ���� ��� ��������� ������ �� ����� ����� � ������ ������ �������/������ � ��������� �����

class FileWork
{
public:
    FileWork();//default constructor - ����������� �� ������������� 

    std::string path = "D:\\C#\\CourseWork\\data.txt";//original data file - �������� ���� ����� 
    std::string backup_path = "data_copy.txt";//backup file that has a copy of original data for case if program crashes while rewriting original file - ���� �������� ��ﳿ, ���� ������ ���� �������� ����� �� �������, ���� �� 

    void LoadData(std::string path, std::set<Play>& plays);//reads structured data from file and loads it into set<Student> - ���� ������������ ��� � ����� �� ��������� �� � set<Student> 
    void WriteAllData(std::string path, std::set<Play> plays);//rewrites chosen file with structured data that is present in set<Student>, all original data inside of file is deleted - ���������� �������� ���� � ��������������� ������, �� ������� � �����<Student>, �� ������ ��� �������� ����� �����������

private:
    void WritePlaytData(std::ofstream& stream, Play person);//helper method to structurize Student data and write it in ofstream - ��������� ����� ��� �������������� ����� Student � ������ �� � ofstream 
    std::vector<char> formatting = { ',',
                                 ',' ,
                                 ',' ,
                                 ',' ,
                                 ',' ,
                                 '\n' };//this vector stores the sequence of characters that are used to delimit single Students' data in file - ��� ������ ������ ����������� �������, �� ���������������� ��� ������������ ������� ����� ���� � ���� 

};

