// Menu Class: represents a menu of choices that the user can choose from.
#ifndef MENU_H
#define MENU_H
#include "Database.h"
#include <iostream>

class Menu {
private:
    Database &db;
public:
    Menu(Database& db);
    void displayMainMenu() const;
    int getUserChoice() const;

    void addMenu();

    void deleteMenu();

    void findMenu();

    void listMenu();
    void subListGenreMenu();
    void subListSongNameMenu(); 
    void subListArtistMenu();
    void subListYearMenu();

    void fullMenu();
};

#endif // MENU_H