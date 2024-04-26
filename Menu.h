// Menu Class: represents a menu of choices that the user can choose from.
#ifndef MENU_H
#define MENU_H
#include "Database.h"
#include <iostream>

class Menu {
public:
    Menu();
    void displayMainMenu() const;
    char getUserChoice() const;
};

#endif // MENU_H