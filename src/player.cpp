#include "player.h"
#include "randomgenerator.h"

Player::Player(std::string name)
{
    m_name = name;
    m_gold = 0;
    m_level = 1;
    m_baseAttack = 5;
    m_healthPoints = 10;
    m_experiencePoints = 0;
}

std::string Player::getName()
{
    return m_name;
}

void Player::addGold(int goldToAdd)
{
    m_gold += goldToAdd;
}

int Player::getGold()
{
    return m_gold;
}

int Player::getBaseAttack()
{
    return m_baseAttack;
}

int Player::getHealthPoints()
{
    return m_healthPoints;
}

void Player::decreaseHealthPoints(int healthPointsToDecrease)
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

void Player::addExperiencePoints(int experiencePointsToAdd)
{
    m_experiencePoints += experiencePointsToAdd;

    if (m_experiencePoints >= m_experiencePointsNeededForNextLevel)
    {
        levelUp();
    }
}

int Player::getExperiencePoints()
{
    return m_experiencePoints;
}


int Player::getLevel()
{
    return m_level;
}

void Player::levelUp()
{
    m_level += 1;
    calculateAndSetExperiencePointsNeededForNextLevel();

    int minNewAttack = m_baseAttack + 3;
    int maxNewAttack = m_baseAttack + 8;
    int minNewHealth = m_healthPoints + 3;
    int maxNewHealth = m_healthPoints + 10;
    
    m_baseAttack = RandomGenerator::GetInstance()->getRandomNumber(
        minNewAttack, maxNewAttack);
    m_healthPoints = RandomGenerator::GetInstance()->getRandomNumber(
        minNewHealth, maxNewHealth);
}

void Player::calculateAndSetExperiencePointsNeededForNextLevel()
{
    m_experiencePointsNeededForNextLevel = (m_level * 10) + (m_level * 5);
}