// playlist.cpp 
#include "Song.h"
#include "Database.h"
#include "Menu.h"

int main() {
    Database db;
    db.readFromFile("database.txt");
    Menu menu(db);
    menu.fullMenu();
}

