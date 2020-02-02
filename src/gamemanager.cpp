#include "gamemanager.h"
#include <iostream>
#include "randomgenerator.h"

GameManager::GameManager()
{
    m_gameIsRunning = true;
    enemyController = EnemyController();
}

void GameManager::run()
{
    Player player{getNewPlayer()};
    char input;

    printTitle();

    while (m_gameIsRunning)
    {
        std::cout << "You are wandering around the world.\n";

        if (enemyAppears())
        {
            startDuel(player);
        }
        else
        {
            std::cout << "Nothing happens. Press any button. Wait ... what's a button?\n";
            std::cin >> input;
            if (input == EXIT_BUTTON)
                m_gameIsRunning = false;
        }
    }
}

Player GameManager::getNewPlayer()
{
    std::string name = getPlayerName();
    Player player = Player(name);

    return player;
}

std::string GameManager::getPlayerName()
{
    std::string playerName = "";
    std::cout << "What's your name?\n";
    std::cin >> playerName;

    return playerName;
}

bool GameManager::enemyAppears()
{
    return RandomGenerator::GetInstance()->getRandomNumber(0, 1) == 1;
}

void GameManager::startDuel(Player &player)
{
    char input;
    int playerLevel{player.getLevel()};
    bool duelling{true};
    Enemy enemy = spawnNewEnemy(playerLevel);

    std::cout << "Hey, watch out " << player.getName() << "!\n";
    std::cout << "An enemy is blocking your path!\n";
    std::cout << "Name: " << enemy.getName() << '\n';
    std::cout << "ATK: " << enemy.getBaseAttack() << '\n';
    std::cout << "HP: " << enemy.getHealthPoints() << '\n';
    std::cout << "G: " << enemy.dropGold() << '\n';

    if (enemyAttacksFirst())
    {
        std::cout << "Enemy quickly attacks!\n";
        int enemyBaseAttack{enemy.getBaseAttack()};
        int enemyActualAttack = RandomGenerator::GetInstance()->getRandomNumber(0, enemyBaseAttack);

        if (enemyActualAttack != 0)
        {
            std::cout << "Ouch! You lose " << enemyActualAttack << " HP!\n";
            player.decreaseHealthPoints(enemyActualAttack);
        }
        else
        {
            std::cout << "Hah! The enemy missed the attack!\n";
        }
    }

    while (duelling)
    {

        std::cout << "What's your next step?\n";
        std::cin >> input;

        if (input == EXIT_BUTTON)
            duelling = false;

        if (input == ATTACK_BUTTON)
        {
            int playerBaseAttack{player.getBaseAttack()};
            int playerActualAttack{RandomGenerator::GetInstance()->getRandomNumber(0, playerBaseAttack)};

            if (playerActualAttack != 0)
            {
                std::cout << "You attack the enemy with " << playerActualAttack << " ATK!\n";
                enemy.decreaseHealthPoints(playerActualAttack);

                if (enemy.getHealthPoints() <= 0) {
                    std::cout << "Enemy is dead! You win!\n";
                    duelling = false;
                }
            }
            else
            {
                std::cout << "Oh no, that's a miss.\n";
            }
        }

        if (input == FLEE_BUTTON)
            std::cout << "You are trying to flee but the developer didn't implement fleeing yet. :/\n";
    }
}

bool GameManager::enemyAttacksFirst()
{
    return RandomGenerator::GetInstance()->getRandomNumber(0, 1) == 1;
}

void GameManager::printTitle()
{
    std::cout << "---------------------\n";
    std::cout << "K O N E K O - D U E L\n";
    std::cout << "---------------------\n";
    std::cout << "\n";
    std::cout << "a – Attack\n";
    std::cout << "f – Flee\n";
    std::cout << "x – Exit\n";
    std::cout << "\n";
}

Enemy GameManager::spawnNewEnemy(int level)
{
    Enemy enemy = enemyController.getRandomlyGeneratedEnemy();
    return enemy;
}