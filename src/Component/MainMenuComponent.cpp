#include "MainMenuComponent.h"
#include <iostream>
#include "../GameController.h"

MainMenuComponent::MainMenuComponent() {}

void MainMenuComponent::Run(GameController& GameController) {
  char input;

  std::cout << "-- Koneko Duel --" << std::endl << std::endl;
  std::cout << "S - Start\n";
  std::cout << "X - Exit\n";
  std::cin >> input;

  if (input == 'X' || input == 'x') {
    GameController.SetState(GameController::EXIT);
  }

  if (input == 'S' || input == 's') {
    GameController.SetState(GameController::PLAYER_CREATION);
  }
}
