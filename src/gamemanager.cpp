#include "gamemanager.h"
#include <iostream>
#include "randomgenerator.h"

GameManager::GameManager()
{
  enemyController = EnemyController();
}

void GameManager::run()
{
  Player player{getNewPlayer()};
  char input;

  printTitle();
  printIntro();

  while (true)
  {
    player.printStatusBar();

    std::cout << "You are wandering around. Press any button.\n";
    std::cin >> input;

    if (input == EXIT_BUTTON)
      break;

    startDuel(player);
  }

  std::cout << "You close your eyes and fall asleep peacefully.\n";
  std::cout << "The end.\n\n";
}

Player GameManager::getNewPlayer()
{
  std::string name = getPlayerName();
  Player player = Player(name);

  return player;
}

void GameManager::printTitle()
{
  std::cout << "---------------------\n";
  std::cout << "K O N E K O - D U E L\n";
  std::cout << "---------------------\n\n";
}

void GameManager::printIntro()
{
  std::cout << "As you open your eyes, you find yourself lost in a dark place.\n";
  std::cout << "Your legs are shaking. You need to find a way out.\n\n";
}

std::string GameManager::getPlayerName()
{
  std::string playerName;
  std::cout << "What's your name?\n";
  std::cin >> playerName;

  return playerName;
}

bool GameManager::enemyAppears()
{
  return RandomGenerator::GetInstance()->getRandomNumber(0, 1) == 1;
}

void GameManager::startDuel(Player &player)
{
  int playerLevel{player.getLevel()};
  Enemy enemy = spawnNewEnemy(playerLevel);
  int enemyBaseAttack{enemy.getBaseAttack()};

  std::cout << "Hey, watch out " << player.getName() << "! "
    << "An enemy is blocking the path:\n";
    enemy.printStatusBar();

  if (enemyAttacksFirst())
  {
    std::cout << enemy.getName() << " quickly attacks!\n";
    enemy.printStatusBar();
    std::cout << '\n';

    int enemyActualAttack = RandomGenerator::GetInstance()->getRandomNumber(0, enemyBaseAttack);
    if (enemyActualAttack != 0)
    {
      std::cout << "Ouch! You lose " << enemyActualAttack << " HP!\n";
      player.decreaseHealthPoints(enemyActualAttack);
    }
    else
    {
      std::cout << "Hah! " << enemy.getName() << "  missed the attack!\n";
    }

    std::cout << '\n';
  }

  while (1)
  {
    player.printStatusBar();
    std::cout << "What are you going to do?\n";
    printControlOptions();

    char input;
    std::cin >> input;

    if (input == EXIT_BUTTON)
      break;

    if (input == ATTACK_BUTTON)
    {
      int playerBaseAttack{player.getBaseAttack()};
      int playerActualAttack{RandomGenerator::GetInstance()->getRandomNumber(0, playerBaseAttack)};

      if (playerActualAttack != 0)
      {
        std::cout << "You attack the enemy with " << playerActualAttack << " ATK!\n";
        enemy.decreaseHealthPoints(playerActualAttack);

        if (enemy.getHealthPoints() <= 0)
        {
          int droppedGoldFromEnemy = enemy.dropGold();
          std::cout << "Enemy dies and drops " << droppedGoldFromEnemy << " G!\n";
          player.addGold(droppedGoldFromEnemy);
          break;
        }
      }
      else
      {
        std::cout << "Oh no, that's a miss.\n";
      }
    }

    if (enemy.getHealthPoints() > 0)
    {
      printEnemyStatus(enemy);
      std::cout << "Enemy's turn. Enemy attacks ...";
      int enemyActualAttack = RandomGenerator::GetInstance()->getRandomNumber(0, enemyBaseAttack);

      if (enemyActualAttack != 0)
      {
        std::cout << "Ouch! You lose " << enemyActualAttack << " HP!\n\n";
        player.decreaseHealthPoints(enemyActualAttack);
      }
      else
      {
        std::cout << "Hah! The enemy missed the attack!\n\n";
      }
    }

    std::cout << '\n';

    if (input == FLEE_BUTTON)
      std::cout << "You are trying to flee but the developer didn't implement fleeing yet. :/\n";
  }
}

bool GameManager::enemyAttacksFirst()
{
  return RandomGenerator::GetInstance()->getRandomNumber(0, 1) == 1;
}

Enemy GameManager::spawnNewEnemy(int level)
{
  Enemy enemy = enemyController.getRandomlyGeneratedEnemy();
  return enemy;
}

void GameManager::printEnemyStatus(Enemy enemy)
{
  std::cout << "Enemy '" << enemy.getName() << "': { ";
  std::cout << "HP: " << enemy.getHealthPoints() << " | ";
  std::cout << "ATK: " << enemy.getBaseAttack() << " | ";
  std::cout << "LVL: " << enemy.getLevel() << " }\n";
}

void GameManager::printControlOptions()
{
  std::cout << "a – Attack | f – Flee | x – Exit\n";
}
