#include "enemy.h"
#include <iostream>

Enemy::Enemy(std::string name, int level, int healthPoints, int baseAttack, int goldToDrop, int experiencePointsToDrop)
{
    m_name = name;
    m_level = level;
    m_healthPoints = healthPoints;
    m_baseAttack = baseAttack;
    m_goldToDrop = goldToDrop;
    m_experiencePointsToDrop = experiencePointsToDrop;
}

std::string Enemy::getName()
{
    return m_name;
}

int Enemy::dropGold()
{
    return m_goldToDrop;
}

int Enemy::getLevel()
{
    return m_level;
}

int Enemy::dropExperiencePoints()
{
    return m_experiencePointsToDrop;
}

int Enemy::getBaseAttack()
{
    return m_baseAttack;
}

int Enemy::getHealthPoints()
{
    return m_healthPoints;
}

void Enemy::decreaseHealthPoints(int healthPointsToDecrease)
{
    if (m_healthPoints - healthPointsToDecrease <= 0)
    {
        m_healthPoints = 0;
    }
    else
    {
        m_healthPoints -= healthPointsToDecrease;
    }
}

void Enemy::printStatusBar()
{
    std::cout << m_name << ": { ";
    std::cout << "HP: " << m_healthPoints << " | ";
    std::cout << "ATK: " << m_baseAttack << " | ";
    std::cout << "LVL: " << m_level << " }\n";
}