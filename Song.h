// Song Class: A class that stores a single database record.
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

class Song {
    std::string title;
    std::string artist;
    int year;

public:
    //Constructors
    Song(){}
    Song(std::string title, std::string artist, int year);
    Song(const Song& other);

    //Destructor
    ~Song();

    //Getters
    std::string getTitle() const;
    std::string getArtist() const;
    int getYear() const;

    //Setters
    void setTitle(std::string title);
    void setArtist(std::string title);
    void setYear(int year);

};
