// Song.cpp
#include "Song.h"

// Default Constructor
Song::Song() {}

// Parameterized Constructor
Song::Song(std::string genre, std::string title, std::string artist, int year)
{
    this->genre = genre;
    this->title = title;
    this->artist = artist;
    this->year = year;
}

// Copy Constructor
Song::Song(const Song &other)
{
    genre = other.genre;
    title = other.title;
    artist = other.artist;
    year = other.year;
}

//Destructor
Song::~Song(){

}

// Getters
std::string Song::getGenre() const{
    return genre;
}

std::string Song::getTitle() const{
    return title;
}

std::string Song::getArtist() const{
    return artist;
}

int Song::getYear() const{
    return year;
}


// Setters
void Song::setGenre(std::string genre){
    this->genre = genre;
}

void Song::setTitle(std::string title){
    this->title = title;
}

void Song::setArtist(std::string artist){
    this->artist = artist;
}

void Song::setYear(int year){
    this->year = year;
}