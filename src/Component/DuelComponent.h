#ifndef KONEKO_DUEL_DUELCOMPONENT_H
#define KONEKO_DUEL_DUELCOMPONENT_H

#include <vector>
#include "../Models/Enemy.h"
#include "../GameController.h"
#include "../Player.h"

class DuelComponent {
  std::vector<Enemy> enemies;
  std::vector<Enemy> GetRandomEnemy(int number = 1);

 public:
  void Run(GameController& game_controller);
  void StartNewDuel(Player& player);
};

#endif  // KONEKO_DUEL_DUELCOMPONENT_H
