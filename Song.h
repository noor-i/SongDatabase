#ifndef SONG_H
#define SONG_H

// Song Class: A class that stores a single database record.
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

class Song {
    std::string genre;
    std::string title;
    std::string artist;
    int year;

public:
    //Constructors
    Song(); // default constructor 
    Song(std::string genre, std::string title, std::string artist, int year); // parameterized constructor 
    Song(const Song& other); // copy constructor 

    //Destructor
    ~Song();

    //Getters
    std::string getGenre() const;
    std::string getTitle() const;
    std::string getArtist() const;
    int getYear() const;

    //Setters
    void setGenre(std::string genre);
    void setTitle(std::string title);
    void setArtist(std::string artist);
    void setYear(int year);

};

#endif // SONG_H