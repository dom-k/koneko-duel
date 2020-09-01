#include "shape.h"

Shape::Shape(std::string name, int level, int healthPoints, int baseAttack)
{
  m_name = name;
  m_level = level;
  m_HP = healthPoints;
  m_baseAttack = baseAttack;
}

std::string Shape::getName()
{
  return m_name;
}

int Shape::getLevel()
{
  return m_level;
}

int Shape::getHP()
{
  return m_HP;
}

int Shape::getBaseAttack()
{
  return m_baseAttack;
}

void Shape::decreaseHP(int hpToDecrease)
{
  if (m_HP - hpToDecrease > 0) {
    m_HP -= hpToDecrease;
  } else {
    m_HP = 0;
  }
}

