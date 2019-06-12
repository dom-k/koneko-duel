#include "Player.h"

Player::Player() {}

int Player::GetLevel() { return this->level; }

void Player::ResetPlayer() {
  this->experience_points = 0;
  this->level = 1;
}

/**
 * @param experience_points
 */
void Player::ConsumeExperiencePoints(int experience_points) {
  this->experience_points += experience_points;

  for (std::vector<int>::size_type i = 0; i != levels.size(); i++) {
    if (this->experience_points >= levels[i]) {
      this->LevelUp();
    }
  }
}

int Player::GetExperiencePoints() { return this->experience_points; }

void Player::LevelUp() {
  this->level += 1;
  this->attack_points += 5;
  this->health_points += 10;
}
