//
// Created by dominik on 03.06.19.
//

#ifndef KONEKO_DUEL_ENEMY_H
#define KONEKO_DUEL_ENEMY_H


#include <string>
#include "LifeForm.h"

class Enemy : public LifeForm {
    std::string bawl;
    std::string asciiImage;
    int droppableExperiencePoints;

public:
    int dropExperiencePoints() {
        return this->droppableExperiencePoints;
    };

    void setBawl(std::string bawl) {
        this->bawl = bawl;
    };

    std::string getBawl() {
        return this->bawl;
    };

    void setAsciiImage(std::string asciiImage) {
        this->asciiImage = asciiImage;
    };

    std::string getAsciiImage() {
        return this->asciiImage;
    };
};


#endif //KONEKO_DUEL_ENEMY_H
