#ifndef KONEKO_DUEL_PLAYER_H
#define KONEKO_DUEL_PLAYER_H

#include <iostream>
#include <vector>
#include "LifeForm.h"


class Player : LifeForm {
    std::string name;
    int experiencePoints;
    std::vector<int> levels = {0, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000};

    /**
     * Increases playere level and therefore attack and health points.
     */
    void levelUp();

public:
    Player();
    std::string getName();

    void setName(std::string name);

    int getLevel();

    /**
     * Reset player's level and XP.
     */
    void resetPlayer();

    void consumeExperiencePoints(int experiencePoints);

    int getExperiencePoints();
};


#endif //KONEKO_DUEL_PLAYER_H
