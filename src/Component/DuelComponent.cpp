//
// Created by dominik on 03.06.19.
//
#include <sqlite3.h>
#include <vector>
#include "DuelComponent.h"

void DuelComponent::generateEnemies(int number) {
    Enemy* enemy = new Enemy();
}

void DuelComponent::startNewDuel(Player player) {

}

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

void DuelComponent::run(GameController* gameController) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    char* sql;
    const char* data;
    char* errMsg = 0;

    if (sqlite3_open("../assets/koneko-duel.sqlite3", &db) == SQLITE_OK) {
        std::cout << "Opened database successfully" << std::endl;
    } else {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) <<  std::endl;
        return;
    }

    sql = "SELECT * FROM Enemies";

    if (sqlite3_exec(db, sql, callback, (void*) data, &errMsg) == SQLITE_OK) {
        std::cout << "Operation done succesfully" << std::endl;
    } else {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return;
    }

    sqlite3_close(db);
}