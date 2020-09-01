#include <iostream>
#include "player.h"
#include "randomgenerator.h"


void Player::addGold(int goldToAdd)
{
  m_gold += goldToAdd;
}

int Player::getGold()
{
  return m_gold;
}

void Player::addXP(int points)
{
  m_HP += points;
  levelUp();
}

int Player::getXP()
{
  return m_XP;
}

std::string Player::getStatusBar()
{
  return m_name + ": { HP: " + std::to_string(m_HP) + 
    ", ATK: " + std::to_string(m_baseAttack) + 
    ", LVL: " + std::to_string(m_level) + 
    ", XP: " + std::to_string(m_XP) + 
    ", G: " + std::to_string(m_gold) +
    " }";
}

bool Player::levelUp()
{
  if (m_XP < m_XPNeededForNextLevel)
  {
    return false;
  }

  m_level += 1;
  calculateXPNeededForNextLevel();

  return true;
}

void Player::calculateXPNeededForNextLevel()
{
  m_XPNeededForNextLevel = (m_level * 10) * 5;
}
