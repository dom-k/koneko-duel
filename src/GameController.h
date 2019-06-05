#ifndef KONEKO_DUEL_GAMECONTROLLER_H
#define KONEKO_DUEL_GAMECONTROLLER_H

#include <string>

class GameController {
    int score{};
    int state;
    
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

    void setState(int state);

    int getState();

    int getScore();

    void run();
};


#endif //KONEKO_DUEL_GAMECONTROLLER_H
