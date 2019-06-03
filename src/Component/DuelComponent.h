#ifndef KONEKO_DUEL_DUELCOMPONENT_H
#define KONEKO_DUEL_DUELCOMPONENT_H

#include <vector>
#include "Component.h"
#include "../Enemy.h"
#include "../Player.h"


class DuelComponent : Component {
    std::vector<Enemy> enemies;
    void generateEnemies(int number = 1);

public:
    void startNewDuel(Player player);

};


#endif //KONEKO_DUEL_DUELCOMPONENT_H
