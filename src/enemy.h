#pragma once
#include <string>
#include "shape.h"

class Enemy: public Shape
{
public:
    Enemy(std::string name, int level, int healthPoints, int baseAttack, int goldToDrop, int xpToDrop): Shape(name, level, healthPoints, baseAttack) {
      m_goldToDrop = goldToDrop;
      m_xpToDrop = xpToDrop;
    }
    int dropGold();
    int dropXP();
    std::string getStatusBar();

private:
    int m_goldToDrop;
    int m_xpToDrop;
};
