#include <iostream>
#include "GameController.h"
#include "Component/MainMenuComponent.h"

GameController::GameController() {
    GameController::state = MAIN_MENU;
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
    
    while (this->state != EXIT) {
        switch(this->state) {
            case MAIN_MENU:
                mainMenuComponent->run(this);
                break;
            case PLAYER_CREATION:
                std::cout << "Player creation coming soon!" << std::endl;
                this->setState(EXIT);
                break;
            case DUEL:
                break;
            case WORLD_MAP:
                break;
            default:
                mainMenuComponent->run(this);
        }
    }
}


