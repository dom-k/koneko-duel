#include "enemy.h"

int Enemy::dropGold()
{
    return m_goldToDrop;
}

int Enemy::dropXP()
{
    return m_xpToDrop;
}

std::string Enemy::getStatusBar()
{
  return m_name + ": { HP: " + std::to_string(m_HP) +
    ", ATK: " + std::to_string(m_baseAttack) + 
    ", LVL: " + std::to_string(m_level) + 
    " }\n";
}
