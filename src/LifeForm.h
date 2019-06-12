#ifndef KONEKO_DUEL_LIFEFORM_H
#define KONEKO_DUEL_LIFEFORM_H

#include <iostream>

class LifeForm {
 protected:
  int health_points;
  int attack_points;
  int level;
  std::string name;

 public:
  void TakeDamage(int damage);

  int GetHealthPoints();

  void SetHealthPoints(int health_points);

  int GetAttackpoints();

  void SetAttackPoints(int attack_points);

  void SetLevel(int Level);

  int GetLevel();

  void SetName(std::string name);

  std::string GetName();
};

#endif  // KONEKO_DUEL_LIFEFORM_H
