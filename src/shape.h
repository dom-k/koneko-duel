#pragma once
#include <string>

class Shape
{
public:
  Shape(std::string name, int level = 1, int healthPoints = 10, int baseAttack = 0);
  std::string getName();
  int getLevel();
  int getHP();
  int getBaseAttack();
  void decreaseHP(int hpToDecrease);

protected:
  std::string m_name;
  int m_level;
  int m_HP;
  int m_baseAttack;
};
