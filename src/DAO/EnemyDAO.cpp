#include "EnemyDAO.h"

EnemyDAO::EnemyDAO() {
  DatabaseAdapter* database_adapter = new DatabaseAdapter();
  this->database_adapter = database_adapter;
}

void EnemyDAO::AddEnemy(Enemy* enemy) {}

void EnemyDAO::DeleteEnemy(Enemy* enemy) {}

Enemy EnemyDAO::GetRandomEnemy() {
  Enemy* enemy = new Enemy();
  this->database_adapter->Exec(
      "SELECT * FROM ENEMIES ORDER BY RANDOM() LIMIT 1");

  return *enemy;
}