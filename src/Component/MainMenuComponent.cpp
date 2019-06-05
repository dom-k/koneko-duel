//
// Created by dominik on 02.06.19.
//

#include <iostream>
#include "MainMenuComponent.h"
#include "../GameController.h"

MainMenuComponent::MainMenuComponent() {
}

void MainMenuComponent::run(GameController* gameController) {
    char input;
    
    std::cout << "-- Koneko Duel --" << std::endl << std::endl;
    std::cout << "S - Start\n";
    std::cout << "X - Exit\n";
    std::cin >> input;

    if (input == 'X' || input == 'x') {
        gameController->setState(GameController::EXIT);
    }

    if (input == 'S' || input == 's') {
        gameController->setState(GameController::PLAYER_CREATION);
    }
}
