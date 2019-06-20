#ifndef KONEKO_DUEL_ENEMY_H
#define KONEKO_DUEL_ENEMY_H

#include <string>
#include "../LifeForm.h"

class Enemy : public LifeForm {
 private:
  int id;
  std::string ascii_image;
  int droppable_experiencepoints;

 public:
  void SetId(int);
  int GetId();

  void SetAsciiImage(std::string ascii_image) {
    this->ascii_image = ascii_image;
  };

  std::string GetAsciiImage() { return this->ascii_image; };

  void SetDroppableExperiencePoints(int droppable_experiencepoints) {
    this->droppable_experiencepoints = droppable_experiencepoints;
  };

  int DropExperiencePoints() { return this->droppable_experiencepoints; };
};

#endif  // KONEKO_DUEL_ENEMY_H
