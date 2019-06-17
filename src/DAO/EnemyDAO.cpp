#include <iostream>
#include "../KeyValueStore.h"
#include "EnemyDAO.h"

EnemyDAO::EnemyDAO() {
  DatabaseAdapter* database_adapter = new DatabaseAdapter();
  this->database_adapter = database_adapter;
}

void EnemyDAO::AddEnemy(Enemy& enemy) {}

void EnemyDAO::DeleteEnemy(Enemy& enemy) {}

Enemy EnemyDAO::GetRandomEnemy() {
  Enemy enemy = Enemy();
  std::vector<KeyValueStore> db_result;

  db_result = this->database_adapter->Exec(
      "SELECT * FROM ENEMIES ORDER BY RANDOM() LIMIT 1");

  for (auto entry : db_result) {
    std::cout << entry.GetValue() << "\n";
  }

  return enemy;
}