#pragma once
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Play.h"
#include <set>

//class to store paths to data files and contain methods to read/write from txt files - клас для зберігання шляхів до файлів даних і містить методи читання/запису з текстових файлів

class FileWork
{
public:
    FileWork();//default constructor - конструктор за замовчуванням 

    std::string path = "D:\\C#\\CourseWork\\data.txt";//original data file - вихідний файл даних 
    std::string backup_path = "data_copy.txt";//backup file that has a copy of original data for case if program crashes while rewriting original file - файл резервної копії, який містить копію вихідних даних на випадок, якщо пр 

    void LoadData(std::string path, std::set<Play>& plays);//reads structured data from file and loads it into set<Student> - читає структуровані дані з файлу та завантажує їх у set<Student> 
    void WriteAllData(std::string path, std::set<Play> plays);//rewrites chosen file with structured data that is present in set<Student>, all original data inside of file is deleted - перезаписує вибраний файл зі структурованими даними, які присутні в наборі<Student>, усі вихідні дані всередині файлу видаляються

private:
    void WritePlaytData(std::ofstream& stream, Play person);//helper method to structurize Student data and write it in ofstream - допоміжний метод для структурування даних Student і запису їх в ofstream 
    std::vector<char> formatting = { ',',
                                 ',' ,
                                 ',' ,
                                 ',' ,
                                 ',' ,
                                 '\n' };//this vector stores the sequence of characters that are used to delimit single Students' data in file - цей вектор зберігає послідовність символів, які використовуються для розмежування окремих даних учнів у файлі 

};

