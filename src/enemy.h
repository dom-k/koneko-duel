#pragma once
#include <string>

class Enemy
{
public:
    Enemy(std::string name, int level, int healthPoints, int baseAttack, int goldToDrop, int experiencePointsToDrop);
    std::string getName();
    int dropGold();
    int getLevel();
    int dropExperiencePoints();
    int getBaseAttack();
    int getHealthPoints();
    void decreaseHealthPoints(int healthPointsToDecrease);

private:
    std::string m_name;
    int m_level;
    int m_healthPoints;
    int m_baseAttack;
    int m_goldToDrop;
    int m_experiencePointsToDrop;
};
