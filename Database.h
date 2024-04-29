// Database Class: stores all records.
#ifndef DATABASE_H
#define DATABASE_H
#include "Song.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

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
    void printSongs(Song *songs);

    // Adding songs
    void addSong(const Song& song); 

    // Read songs from file
    void readFromFile(const std::string& filename);

    // Finding songs
    void genreSearch(std::string string);
    void songNameSearch(std::string string);
    void artistSearch(std::string string);
    void substringSearch(std::string string);
    void yearSearch(int year);
    void rangeSearch(int year1, int year2);

    // Helpers
    bool songDuplicate(const Song &song);
    bool isValidYear(int year);
    void deleteRecord(int index);
    void swap(Song song1, Song song2);

    // Deleting songs
    void deleteByString(std::string string);
    void deleteBySubString(std::string string);
    void deleteByYear(int year);
    void deleteByRange(int year1, int year2);

    // Listing songs alphabetically 
    void genreAlphaOrder(Song* songs);
    void printGenreAlpha(Song* songs);
    void artistAlphaOrder(Song* songs);
    void printArtistAlpha(Song* songs);
    void songNameAlphaOrder(Song* songs);
    void printSongNameAlpha(Song* songs);

    // Listing songs reverse alphabetically 
    void genreRevAlphaOrder(Song* songs);
    void printGenreRevAlpha(Song* songs);
    void artistRevAlphaOrder(Song* songs);
    void printArtistRevAlpha(Song* songs);
    void songNameRevAlphaOrder(Song* songs);
    void printSongNameRevAlpha(Song* songs);

    // Listing songs ascending/descending by year
    void printAscendOrder(Song *songs);
    void printDescendOrder(Song *songs);
};

#endif //DATABASE_H
