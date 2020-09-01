#pragma once
#include <string>
#include "shape.h"

class Player: public Shape
{
public:
    Player(std::string name, int level = 1, int healthPoints = 10, int baseAttack = 1, int gold = 0): Shape(name, level, healthPoints, baseAttack) { 
      m_gold = gold;
      m_XP = 0;
    }
    void addXP(int points);
    int getXP();
    bool nextLevelReached();
    void addGold(int gold);
    int getGold();
    std::string getStatusBar();

private:
    int m_XP;
    int m_XPNeededForNextLevel;
    int m_gold;

private:
    bool levelUp();
    void calculateXPNeededForNextLevel();
};
