#include <iostream>
#include <set>
#include "FileWork.h"

FileWork::FileWork() {

}

void FileWork::LoadData(std::string path, std::set<Play>& plays) {
    std::ifstream file;
    file.open(path, std::ios::in);
    if (!file) {
        std::cout << "No file!\n";
    }
    else {
        std::cout << "Loading from file..." << path << "\n";
        while (file) {
            if (file.peek() == EOF) {
                break;
            }
            std::vector<std::string> play_data;
            for (char delim : formatting) {
                std::string info;
                getline(file, info, delim);
                play_data.push_back(info);
            }
            Play play(play_data);
            plays.insert(play);
        }
        std::cout << "Loading finished!\n";
    };
    file.close();
}

void FileWork::WritePlaytData(std::ofstream& stream, Play play) {
    /*stream << play.getName() << ","
        << play.getDescription()<< ","
        << play.getActors() << ","
        << play.getDuration() << ","
        << play.getPrice() << ","
        << play.getTime() << "\n";*/ 
    stream << play.namePlay<< ","
        << play.getDescription() << ","
        << play.getActors() << ","
        << play.getDuration() << ","
        << play.getPrice() << ","
        << play.getTime() << "\n";
}

void FileWork::WriteAllData(std::string path, std::set<Play> plays) {
    std::ofstream file;
    file.open(path, std::ios::out);
    for (Play play : plays) {
        WritePlaytData(file, play);
    }
    file.close();
}