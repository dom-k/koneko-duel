//
// Created by dominik on 02.06.19.
//

#include "PlayerCreationComponent.h"

Player PlayerCreationComponent::createNewPlayer(Player player) {
    std::string playerName;

    std::cout << "What's your kitten's name? ";
    std::cin >> playerName;

    player.setName(playerName);

    return player;
}
