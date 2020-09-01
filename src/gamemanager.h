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
    // enum KEYBOARD_CONF
    // {
    //     EXIT_BUTTON = 'x',
    //     ATTACK_BUTTON = 'a',
    //     FLEE_BUTTON = 'f',
    //     WALK_BUTTON = 'w'
    // };
    std::string EXIT_BUTTON = "x";
    std::string ATTACK_BUTTON = "a";
    std::string FLEE_BUTTON = "f";
    std::string WALK_BUTTON = "w";
    EnemyController enemyController;
    bool m_gameIsRunning;

private:
    Player getNewPlayer();
    void printTitle();
    void printIntro();
    void printPlayerStatusBar(Player player);
    std::string getPlayerName();
    bool enemyAppears();
    void startDuel(Player &player);
    bool enemyAttacksFirst();
    Enemy spawnNewEnemy(int level);
    void printEnemyStatus(Enemy enemy);
    void printControlOptions();
};
