#include "Player.h"

Player::Player() {
}

void Player::setName(std::string name) {
    this->name = name;
}

std::string Player::getName() {
    return this->name;
}

int Player::getLevel() {
    return this->level;
}

void Player::resetPlayer() {
    this->experiencePoints = 0;
    this->level = 1;
}

/**
 * @param experiencePoints
 */
void Player::consumeExperiencePoints(int experiencePoints) {
    this->experiencePoints += experiencePoints;

    for (std::vector<int>::size_type i = 0; i != levels.size(); i++) {
        if (this->experiencePoints >= levels[i]) {
            this->levelUp();
        }
    }
}

int Player::getExperiencePoints() {
    return this->experiencePoints;
}

void Player::levelUp() {
    this->level += 1;
    this->attackPoints += 5;
    this->healthPoints += 10;
}
