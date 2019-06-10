#include <vector>
#include "DuelComponent.h"
#include "../DAO/EnemyDAO.h"

void DuelComponent::generateEnemies(int number) {
    Enemy* enemy = new Enemy();
}

void DuelComponent::startNewDuel(Player player) {

}

void DuelComponent::run(GameController* gameController) {
  Enemy* enemy = new Enemy();
  EnemyDAO* enemy_DAO = new EnemyDAO();
  *enemy = enemy_DAO->GetRandomEnemy();
}