#pragma once
#include <string>
#include "player.h"
#include "enemycontroller.h"

class GameManager
{
public:
    GameManager();
    void run();

private:
    enum KEYBOARD_CONF
    {
        EXIT_BUTTON = 'x',
        ATTACK_BUTTON = 'a',
        FLEE_BUTTON = 'f',
        WALK_BUTTON = 'w'
    };
    EnemyController enemyController;
    bool m_gameIsRunning;

private:
    void printTitle();
    Player getNewPlayer();
    std::string getPlayerName();
    bool enemyAppears();
    void startDuel(Player &player);
    bool enemyAttacksFirst();
    Enemy spawnNewEnemy(int level);
};