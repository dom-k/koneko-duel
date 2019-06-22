#include "DuelComponent.h"
#include "../DAO/EnemyDAO.h"

// TODO: Delete this method.
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
  // std::vector<Enemy> enemies = this->GetRandomEnemy(5);
  EnemyDAO enemyDAO = EnemyDAO();
  Enemy enemy = enemyDAO.GetRandomEnemy();
  Player *player = game_controller.GetPlayer();

  for (auto enemy : enemies) {
    std::cout << enemy.GetName() << "\n";
  }

  std::cout << player->GetName() << "\n";
  
}