#include "DuelComponent.h"
#include <vector>
#include "../DAO/EnemyDAO.h"

void DuelComponent::GenerateEnemies(int number) { Enemy* enemy = new Enemy(); }

void DuelComponent::StartNewDuel(Player& player) {}

void DuelComponent::Run(GameController& game_controller) {
  Enemy enemy = Enemy();
  EnemyDAO enemy_DAO = EnemyDAO();
  enemy = enemy_DAO.GetRandomEnemy();
}