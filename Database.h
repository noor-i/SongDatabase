// Database Class: stores all records.
#ifndef DATABASE_H
#define DATABASE_H
#include "Song.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype> // used for tolower() & toupper()
#include <algorithm> // used for std::transform()

class Database {
private:
    Song *songs; // pointer to the 1st element of array
    int capacity; // total size of array
    int numSongs; // current number of songs in array

public:
    // Constructors
    Database();
    Database(Song *songs, int capacity, int numSongs);
    Database(const Database& other);
    Database(int initialCapacity);

    // Destructor
    ~Database();

    //Getters
    int getCapacity() const; // get capacity 
    int getCurrentSize() const; // get current number of songs in playlist

    // Printing songs
    void printSongs();
    void printSong(int i);

    // Adding songs
    void addSong(const Song& song); 

    // Read songs from file
    void readFromFile(const std::string& filename);

    // Finding songs
    void genreSearch(std::string string);
    void songNameSearch(std::string string);
    void artistSearch(std::string string);
    void yearSearch(int year);
    void rangeSearch(int year1, int year2);

    // Helpers
    bool songDuplicate(const Song &song);
    bool isValidYear(int year);
    void deleteRecord(int index);
    void swap(Song &song1, Song &song2);
    std::string convertToUppercase(std::string str);
    std::string convertToLowercase(std::string str);

    // Deleting songs
    void deleteByString(const std::string& string);
    //void deleteByGenre(std::string string);
    //void deleteBySongName(std::string string);
    //void deleteByArtist(std::string string);
    void deleteByYear(int year);
    void deleteByRange(int year1, int year2);

    // Listing songs alphabetically 
    void genreAlphaOrder();
    void artistAlphaOrder();
    void songNameAlphaOrder();

    // Listing songs reverse alphabetically 
    void genreRevAlphaOrder();
    void artistRevAlphaOrder();
    void songNameRevAlphaOrder();

    // Listing songs ascending/descending by year
    void ascendOrder();
    void descendOrder();
};

#endif //DATABASE_H
