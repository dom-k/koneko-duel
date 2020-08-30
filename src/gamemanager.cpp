#include <iostream>
#include "randomgenerator.h"

GameManager::GameManager()
{
  m_gameIsRunning = true;
  enemyController = EnemyController();
}

void GameManager::run()
{
  Player player{getNewPlayer()};
  char input;

  printTitle();
  printControlOptions();

  while (m_gameIsRunning)
  {
    player.printStatusBar();

    std::cout << "You are wandering around the world. Press any button.\n";
    std::cin >> input;

    if (input == EXIT_BUTTON)
      break;

    startDuelLoop(player);
  }
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

void GameManager::startDuelLoop(Player &player)
{
  int playerLevel{player.getLevel()};
  Enemy enemy = spawnNewEnemy(playerLevel);
  int enemyBaseAttack{enemy.getBaseAttack()};
  bool playerDied{false};

  std::cout << "Hey, watch out " << player.getName() << "! "
    << "An enemy is blocking the path:\n";

  handleFirstAttacks(player, enemy);

  bool playersTurn = RandomGenerator::GetInstance()->getRandomNumber(0, 1) == 1;
  while (enemy.getHealthPoints() > 0 && !playerDied)
  {
    if (playersTurn)
    {
      char input;
      std::cout << "What would you like to do?\n";
      std::cin >> input;

      if (input == 'a')
      {
        std::cout << "You attack.\n";
        int playerActualAttack{player.getActualAttack()};
        if (playerActualAttack != 0)
        {
          std::cout << "You hit the enemy with " << playerActualAttack
            << " ATK!\n";
          enemy.decreaseHealthPoints(playerActualAttack);
        }
        else
        {
          std::cout << "Oh no! That's a miss.\n";
        }
      } else {
        std::cout << "You are doing nothing.\n";
      }
    }
    else
    {
      int enemyActualAttack{enemy.getActualAttack()};
      if (enemyActualAttack != 0)
      {
        std::cout << "Ouch! You lose " << enemyActualAttack << " HP!\n";
        player.decreaseHealthPoints(enemyActualAttack);
      }
      else
      {
        std::cout << "Hah! The enemy missed the attack!\n";
      }
    }

    enemy.printStatusBar();
    player.printStatusBar();

    if (player.getHealthPoints() <= 0)
    {
      playerDied = true;
    }
  }

  if (enemy.getHealthPoints() > 0)
  {
    std::cout << "Enemy is defeated.";
    enemy.printDefeatSummary();
  }

  if (playerDied)
  {
    std::cout << "You died.\n";
    m_gameIsRunning = false;
  }
}

void GameManager::handleFirstAttacks(Player &player, Enemy &enemy)
{
  if (enemyAttacksFirst())
  {
    std::cout << "Enemy attacks first.\n";
    int enemyActualAttack{enemy.getActualAttack()};
    if (enemyActualAttack != 0)
    {
      std::cout << "Ouch! You lose " << enemyActualAttack << " HP!\n";
      player.decreaseHealthPoints(enemyActualAttack);
    }
    else
    {
      std::cout << "Hah! The enemy missed the attack!\n";
    }
  }
  else
  {
    std::cout << "You attack first.\n";
    int playerActualAttack{player.getActualAttack()};
    if (playerActualAttack != 0)
    {
      std::cout << "You hit the enemy with " << playerActualAttack
        << " ATK!\n";
      enemy.decreaseHealthPoints(playerActualAttack);
    }
    else
    {
      std::cout << "Oh no! That's a miss.\n";
    }
  }
}

void GameManager::startDuel(Player &player)
{
  char input;
  int playerLevel{player.getLevel()};
  bool duelling{true};
  bool playersTurn{true};
  Enemy enemy = spawnNewEnemy(playerLevel);
  int enemyBaseAttack{enemy.getBaseAttack()};

  std::cout << "Hey, watch out " << player.getName() << "! "
    << "An enemy is blocking the path:\n";

  if (enemyAttacksFirst())
  {
    std::cout << "Enemy quickly attacks!\n";
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
      std::cout << "Hah! The enemy missed the attack!\n";
    }

    std::cout << '\n';
  }

  while (duelling)
  {
    // Player's turn.
    player.printStatusBar();
    std::cout << "What's your next step?\n";
    printControlOptions();
    std::cin >> input;

    if (input == EXIT_BUTTON)
      duelling = false;

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
          std::cout << "Enemy dies and drops " << droppedGoldFromEnemy << " G!";
          player.addGold(droppedGoldFromEnemy);
          duelling = false;
        }
      }
      else
      {
        std::cout << "Oh no, that's a miss.\n";
      }
    }

    if (enemy.getHealthPoints() > 0)
    {
      enemy.printStatusBar();
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
  // TODO: Should be based on agility. Add agility attributes to player & enemy.
  return RandomGenerator::GetInstance()->getRandomNumber(0, 1) == 1;
}

Enemy GameManager::spawnNewEnemy(int level)
{
  Enemy enemy = enemyController.getRandomlyGeneratedEnemy();
  return enemy;
}

void GameManager::printControlOptions()
{
  std::cout << "a – Attack | f – Flee | x – Exit\n";
}
