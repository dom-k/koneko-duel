#pragma once
#include "enemy.h"

class EnemyController
{
public:
    EnemyController();
    Enemy getRandomlyGeneratedEnemy(int level = 1);
};
