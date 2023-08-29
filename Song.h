// Song Class: A class that stores a single database record.
#include <iostream>
#include <string>
#include <sstream>

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
    std::string getSong(){title + ", " + singer + ", " + std::to_string(year);}

};
