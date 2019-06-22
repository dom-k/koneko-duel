#include "DuelComponent.h"
#include "../DAO/EnemyDAO.h"

std::vector<Enemy> DuelComponent::GetRandomEnemy(int number) {
  std::vector<Enemy> enemies;
  EnemyDAO enemy_DAO = EnemyDAO();

  for (int i = 0; i < number; i++) {
    Enemy enemy = enemy_DAO.GetRandomEnemy();
    enemies.push_back(enemy);
  }

  return enemies;
}

void DuelComponent::StartNewDuel(Player& player) {}

void DuelComponent::Run(GameController& game_controller) {
  std::vector<Enemy> enemies = this->GetRandomEnemy(5);

  for (auto enemy : enemies) {
    std::cout << enemy.GetName() << "\n";
  }
}