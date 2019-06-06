#include <string>
#include "LifeForm.h"

void LifeForm::takeDamage(int damage) {
    this->healthPoints -= damage;
}

int LifeForm::getHealthPoints() {
    return 0;
}

void LifeForm::setHealthPoints(int healthPoints) {
    this->healthPoints = healthPoints;
}

int LifeForm::getAttackpoints() {
    return 0;
}

void LifeForm::setAttackPoints(int attackPoints) {
    this->attackPoints = attackPoints;
}

void LifeForm::setLevel(int level) {
    this->level = level;
}

int LifeForm::getLevel() {
    return 0;
}

void LifeForm::setName(std::string name) {
    this->name = name;
}

std::string LifeForm::getName() {
    return this->name;
}
