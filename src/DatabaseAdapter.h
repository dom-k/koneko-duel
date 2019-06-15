#ifndef KONEKO_DUEL_DATABASEADAPTER_H
#define KONEKO_DUEL_DATABASEADAPTER_H

#include <sqlite3.h>
#include <vector>

class DatabaseAdapter {
 private:
  const char *db_file = "../assets/koneko-duel.sqlite3";
  sqlite3 *db;
  sqlite3_stmt *stmt;
  const char *data;
  char *err_msg = 0;
  static int C_callback(void *data, int argc, char **argv, char **az_col_name);
  int Callback(int argc, char **argv, char **az_col_name);
  std::vector<char **> databaseResult;

 public:
  DatabaseAdapter();
  void Exec(const char *sql_query);
  ~DatabaseAdapter();
};
#endif  // KONEKO_DUEL_DATABASEADAPTER_H