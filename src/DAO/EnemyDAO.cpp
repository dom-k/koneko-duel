#include "EnemyDAO.h"
#include <iostream>
#include "../KeyValueStore.h"

EnemyDAO::EnemyDAO() {
  DatabaseAdapter *database_adapter = new DatabaseAdapter();
  this->database_adapter = database_adapter;
}

void EnemyDAO::AddEnemy(Enemy &enemy) {}

void EnemyDAO::DeleteEnemy(Enemy &enemy) {}

Enemy EnemyDAO::GetRandomEnemy() {
  Enemy enemy = Enemy();
  std::vector<KeyValueStore> db_result;

  db_result = this->database_adapter->Exec(
      "SELECT * FROM ENEMIES ORDER BY RANDOM() LIMIT 1");

  // TODO: Use Try Catch & Create class function.
  for (auto entry : db_result) {
    if (entry.GetKey() == "Name") enemy.SetName(entry.GetValue());

    if (entry.GetKey() == "HealthPoints")
      enemy.SetHealthPoints(std::stoi(entry.GetValue()));

    if (entry.GetKey() == "AttackPoints")
      enemy.SetAttackPoints(std::stoi(entry.GetValue()));

    if (entry.GetKey() == "AsciiImage") enemy.SetAsciiImage(entry.GetValue());

    if (entry.GetKey() == "DroppableExperiencePoints")
      enemy.SetDroppableExperiencePoints(std::stoi(entry.GetValue()));
  }

  return enemy;
}