#pragma once
#include <string>

class Player
{
public:
    Player(std::string name);
    std::string getName();
    void addGold(int goldToAdd);
    int getGold();
    int getBaseAttack();
    int getHealthPoints();
    void decreaseHealthPoints(int healthPointsToDecrease);
    void addExperiencePoints(int experiencePointsToAdd);
    int getExperiencePoints();
    int getLevel();

private:
    std::string m_name;
    int m_gold;
    int m_healthPoints;
    int m_baseAttack;
    int m_level;
    int m_experiencePoints;
    int m_experiencePointsNeededForNextLevel;

private:
    void levelUp();
    void calculateAndSetExperiencePointsNeededForNextLevel();
};
