// Database.cpp
#include "Database.h"

// Constructors
Database::Database(){}

Database::Database(Song *songs, int capacity, int numSongs){
    this->songs = new Song[capacity];
    this->capacity = capacity;
    this->numSongs = 0;
}

// Destructor
Database::~Database(){
    delete[] songs;
}

// Getters
int Database::getCapacity() const{
    return capacity;
}

int Database::getCurrentSize() const{
    return numSongs;
}

// Add a record
// if user enters wrong type of data for any field, ask to re-enter data
// do not let user enter invalid year, e.g cannot be negative, re-ask year if invalid
// if record already exists, send message to user and do not add record

void Database::addSong(const Song &song){
    std::string songName;
    std::string artist;
    int year;
    printf("Enter song name: \n");
    std::cin >> songName;
    printf("Enter artist name: \n");
    std::cin >> artist;
    printf("Enter year: \n");
    std::cin >> year;

    printf("New song added!\n");

}

