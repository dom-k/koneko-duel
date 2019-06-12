#ifndef KONEKO_DUEL_PLAYER_H
#define KONEKO_DUEL_PLAYER_H

#include <iostream>
#include <vector>
#include "LifeForm.h"


class Player : public LifeForm {
    int experience_points;
    std::vector<int> levels = {0, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000};

    /**
     * Increases playere level and therefore attack and health points.
     */
    void LevelUp();

public:
    Player();

    int GetLevel();

    /**
     * Reset player's level and XP.
     */
    void ResetPlayer();

    void ConsumeExperiencePoints(int experience_points);

    int GetExperiencePoints();
};


#endif //KONEKO_DUEL_PLAYER_H
