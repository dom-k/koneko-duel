#include <vector>
#include "DuelComponent.h"
#include "../DatabaseAdapter.h"

void DuelComponent::generateEnemies(int number) {
    Enemy* enemy = new Enemy();
}

void DuelComponent::startNewDuel(Player player) {

}

void DuelComponent::run(GameController* gameController) {
    char* db_file = "../assets/koneko-duel.sqlite3";
    DatabaseAdapter* database_adapter = new DatabaseAdapter(db_file);
    database_adapter->exec("SELECT * FROM Enemies");


    database_adapter->~DatabaseAdapter();
    return;
}