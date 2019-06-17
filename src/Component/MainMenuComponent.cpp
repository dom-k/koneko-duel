#include "MainMenuComponent.h"
#include <iostream>
#include "../GameController.h"

MainMenuComponent::MainMenuComponent() {}

void MainMenuComponent::Run(GameController& GameController) {
  char input;

  std::cout << "-– Koneko Duel ––\n\n";
  std::cout << "S - Start\n";
  std::cout << "X - Exit\n\n";
  std::cin >> input;
  std::cout << "\n";

  if (input == 'X' || input == 'x') {
    GameController.SetState(EXIT);
  }

  if (input == 'S' || input == 's') {
    GameController.SetState(PLAYER_CREATION);
  }
}
