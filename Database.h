#ifndef DATABASE_H
#define DATABASE_H
// Database Class: stores all records.
#include <string>
#include "Song.h"

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

    // Methods //
    // Adding songs
    void addSong(const Song& song); 

    // Finding songs
    void stringSearch(std::string string); 
    void substringSearch(std::string string);
    void yearSearch(int year);
    void rangeSearch(int year1, int year2);

    // Helpers
    bool songDuplicate(const Song &song);
    bool isValidYear(int year);
    void deleteRecord(int index);

    // Deleting songs
    void deleteByString(std::string string);
    void deleteBySubString(std::string string);
    void deleteByYear(int year);
    void deleteByRange(int year1, int year2);

    // Listing songs
    void swap(std::string str1, std::string str2);
    void printGenreAlphaOrder(const Song* songs);
    void printArtistAlphaOrder(const Song* songs);
    void printSongNameAlphaOrder(const Song* songs);

    // Printing songs
    void printSongs(const Song *song);
};

#endif //DATABASE_H
