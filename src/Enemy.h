#ifndef KONEKO_DUEL_ENEMY_H
#define KONEKO_DUEL_ENEMY_H

#include <string>
#include "LifeForm.h"

class Enemy : public LifeForm {
  std::string ascii_image;
  int droppable_experiencepoints;

 public:
  int DropExperiencePoints() { return this->droppable_experiencepoints; };

  void SetAsciiImage(std::string ascii_image) {
    this->ascii_image = ascii_image;
  };

  std::string GetAsciiImage() { return this->ascii_image; };
};

#endif  // KONEKO_DUEL_ENEMY_H
