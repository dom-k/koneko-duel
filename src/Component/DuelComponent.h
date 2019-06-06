#ifndef KONEKO_DUEL_DUELCOMPONENT_H
#define KONEKO_DUEL_DUELCOMPONENT_H

#include <vector>
#include "../GameController.h"
#include "../Enemy.h"
#include "../Player.h"


class DuelComponent {
    std::vector<Enemy> enemies;
    void generateEnemies(int number = 1);

public:
    void run(GameController* gameController);
    void startNewDuel(Player player);
};


#endif //KONEKO_DUEL_DUELCOMPONENT_H
