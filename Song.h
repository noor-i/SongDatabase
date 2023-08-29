// Song Class: A class that stores a single database record.
#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <string>


class Song
{
//Encapsulation: granting access to private data only through controlled public interfaces
private:
    std::string title;
    std::string singer;
    int year;

public:
    //Setters/Mutators 
    void setTitle(std::string title){this->title = title;}
    void setSinger(std::string singer){this->singer = singer;}
    void setYear(int year){this->year = year;}
    //Getters
    std::string getTitle(){return title;}
    std::string getSinger(){return singer;}
    int getYear(){return year;}
    std::string getSong(){return title + ", " + singer + ", " + std::to_string(year);}

};

#endif