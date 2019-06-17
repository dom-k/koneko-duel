#include <iostream>
#include "GameController.h"
#include "Component/DuelComponent.h"
#include "Component/MainMenuComponent.h"
#include "Component/PlayerCreationComponent.h"
#include "Player.h"

GameController::GameController() {
  GameController::state = MAIN_MENU;
  this->player = new Player();
}

void GameController::SetState(int state) { this->state = state; }

int GameController::GetState() { return this->state; }

int GameController::GetScore() { return this->score; }

void GameController::Run() {
  
  MainMenuComponent main_menu_component = MainMenuComponent();
  PlayerCreationComponent player_creation_component = PlayerCreationComponent();
  DuelComponent duel_component = DuelComponent();

  this->player->ResetPlayer();

  while (this->state != EXIT) {
    switch (this->state) {
      case MAIN_MENU:
        main_menu_component.Run(*this);
        break;
      case PLAYER_CREATION:
        player_creation_component.Run(*player);
        this->SetState(DUEL);
        break;
      case DUEL:
        duel_component.Run(*this);
        this->SetState(EXIT);
        break;
      case WORLD_MAP:
        std::cout << "Worldmap is coming soon." << std::endl;
        this->SetState(EXIT);
        break;
      case EXIT:
        break;
      default:
        main_menu_component.Run(*this);
    }
  }
}
