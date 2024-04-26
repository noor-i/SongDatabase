// Database Class: stores all records.

#ifndef DATABASE_H
#define DATABASE_H
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
    // Printing songs
    void printSongs(Song *songs);

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
    void swap(Song song1, Song song2);

    // Deleting songs
    void deleteByString(std::string string);
    void deleteBySubString(std::string string);
    void deleteByYear(int year);
    void deleteByRange(int year1, int year2);

    // Listing songs alphabetically 
    void swap(Song song1, Song song2);
    void genreAlphaOrder(Song* songs);
    void printGenreAlpha(Song* songs);
    void artistAlphaOrder(Song* songs);
    void printArtistAlpha(Song* songs);
    void songNameAlphaOrder(Song* songs);
    void printSongNameAlpha(Song* songs);

    // Listing songs reverse alphabetically 
    void swap(Song song1, Song song2);
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
