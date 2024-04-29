// Menu Class: represents a menu of choices that the user can choose from.
#ifndef MENU_H
#define MENU_H
#include "Database.h"
#include <iostream>

class Menu {
private:
    Database db;
public:
    Menu();
    void displayMainMenu() const;
    int getUserChoice() const;
    void subFindMenu();
    void fullMenu();
};

#endif // MENU_H