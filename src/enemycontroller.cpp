#include "enemycontroller.h"
#include <iostream>
#include <string>
#include "randomgenerator.h"

EnemyController::EnemyController()
{
}

Enemy EnemyController::getRandomlyGeneratedEnemy(int level)
{
    int healthPoints{RandomGenerator::GetInstance()->getRandomNumber(
        level, level + 5)};
    int attack{RandomGenerator::GetInstance()->getRandomNumber(
        level, level + 3)};
    int goldToDrop{RandomGenerator::GetInstance()->getRandomNumber(
        level, level + 10)};
    int experiencePointsToDrop{RandomGenerator::GetInstance()->getRandomNumber(
        level, level + 4)};
    std::string name{RandomGenerator::GetInstance()->getRandomName()};
    Enemy enemy = Enemy(name, level, healthPoints, attack, goldToDrop,
                        experiencePointsToDrop);

    return enemy;
}
