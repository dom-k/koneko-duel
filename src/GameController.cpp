//
// Created by dominik on 03.06.19.
//

#include "GameController.h"
#include "Component/MainMenuComponent.h"

GameController::GameController() {
    this->state = 0;
}


void GameController::setState(int state) {

}

int GameController::getState() {
    return this->state;
}

int GameController::getScore() {
    return this->score;
}

void GameController::run() {
    if (this->state == 0) {
        this->state = MAIN_MENU;
        MainMenuComponent mainMenuComponent;
        mainMenuComponent.run();
    }
}


