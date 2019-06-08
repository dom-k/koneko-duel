#include <iostream>
#include "Component/MainMenuComponent.h"
#include "Component/PlayerCreationComponent.h"
#include "Component/DuelComponent.h"
#include "Player.h"
#include "GameController.h"

GameController::GameController() {
    GameController::state = MAIN_MENU;
    this->player = new Player();
}

void GameController::setState(int state) {
    this->state = state;
}

int GameController::getState() {
    return this->state;
}

int GameController::getScore() {
    return this->score;
}

void GameController::run() {
    MainMenuComponent* mainMenuComponent = new MainMenuComponent();
    PlayerCreationComponent* playerCreationComponent = new PlayerCreationComponent();
    DuelComponent* duelComponent = new DuelComponent();

    // Player* player = new Player();
    this->player->resetPlayer();
    
    while (this->state != EXIT) {
        switch(this->state) {
            case MAIN_MENU:
                mainMenuComponent->run(this);
                break;
            case PLAYER_CREATION:
                playerCreationComponent->run(this->player);
                this->setState(DUEL);
                break;
            case DUEL:
                duelComponent->run(this);
                this->setState(EXIT);
                break;
            case WORLD_MAP:
                std::cout << "Worldmap is coming soon." << std::endl;
                this->setState(EXIT);
                break;
            default:
                mainMenuComponent->run(this);
        }
    }
}


