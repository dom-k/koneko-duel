#ifndef KONEKO_DUEL_GAMECONTROLLER_H
#define KONEKO_DUEL_GAMECONTROLLER_H

#include <string>
#include "Player.h"

class GameController {
    int score{};
    int state;
    Player* player;
    
public:
    /**
     * Available game states.
     */
    static const int EXIT = 0;;
    static const int MAIN_MENU = 1;
    static const int DUEL = 2;
    static const int PLAYER_CREATION = 3;
    static const int WORLD_MAP = 4;

    GameController();

    void SetState(int state);

    int GetState();

    int GetScore();

    void Run();
};


#endif //KONEKO_DUEL_GAMECONTROLLER_H
