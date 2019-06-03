//
// Created by dominik on 02.06.19.
//

#include <iostream>
#include "MainMenuComponent.h"

MainMenuComponent::MainMenuComponent() {
}

void MainMenuComponent::run() {
    char input;
    int err = 0;

    do {
        std::cout << "-- Koneko Duel -- \n\n";
        std::cout << "S - Start\n";
        std::cout << "E - Exit\n";

        std::cin >> input;

        if (input == 'E' || input == 'e' || input == 'S' || input == 's') {
            err = 1;
        }

    } while (err == 0);
}
