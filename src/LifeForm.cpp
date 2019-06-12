#include "LifeForm.h"

void LifeForm::TakeDamage(int damage) { this->health_points -= damage; }

int LifeForm::GetHealthPoints() { return 0; }

void LifeForm::SetHealthPoints(int health_points) {
  this->health_points = health_points;
}

int LifeForm::GetAttackpoints() { return 0; }

void LifeForm::SetAttackPoints(int attack_points) {
  this->attack_points = attack_points;
}

void LifeForm::SetLevel(int level) { this->level = level; }

int LifeForm::GetLevel() { return 0; }

void LifeForm::SetName(std::string name) { this->name = name; }

std::string LifeForm::GetName() { return this->name; }
