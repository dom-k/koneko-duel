#ifndef KONEKO_DUEL_GAMECONTROLLER_H
#define KONEKO_DUEL_GAMECONTROLLER_H

#include <string>
#include "Player.h"

enum States {
  EXIT = 0,
  MAIN_MENU = 1,
  DUEL = 2,
  PLAYER_CREATION = 3,
  WORLD_MAP = 4,
};

class GameController {
  int score{};
  int state;
  Player* player;

 public:
  GameController();

  void SetState(int state);

  int GetState();

  int GetScore();

  Player* GetPlayer();

  void Run();
};

#endif  // KONEKO_DUEL_GAMECONTROLLER_H
