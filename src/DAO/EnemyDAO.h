#ifndef KONEKO_DUEL_ENEMYDAO_H
#define KONEKO_DUEL_ENEMYDAO_H

#include "../DatabaseAdapter.h"
#include "../Models/Enemy.h"

class EnemyDAO {
 private:
  DatabaseAdapter* database_adapter;

 public:
  EnemyDAO();
  void AddEnemy(Enemy& enemy);
  void DeleteEnemy(Enemy& enemy);
  Enemy GetRandomEnemy();
};

#endif  // KONEKO_DUEL_ENEMYDAO_H