//
// Created by dominik on 03.06.19.
//

#ifndef KONEKO_DUEL_GAMECONTROLLER_H
#define KONEKO_DUEL_GAMECONTROLLER_H


#include <string>

class GameController {
    int score{};
    int state;
    /**
     * Available game states.
     */
    const int DUEL = 1;
    const int MAIN_MENU = 2;
    const int PLAYER_CREATION = 3;
    const int WORLD_MAP = 4;


public:
    GameController();

    void setState(int state);

    int getState();

    int getScore();

    void run();
};


#endif //KONEKO_DUEL_GAMECONTROLLER_H
