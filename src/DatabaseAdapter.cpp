#include "DatabaseAdapter.h"

DatabaseAdapter::DatabaseAdapter() {
  if (sqlite3_open(this->db_file, &this->db) != SQLITE_OK) {
    std::cout << "Can't open database: " << sqlite3_errmsg(this->db)
              << std::endl;
    return;
  }
}

DatabaseAdapter::~DatabaseAdapter() { sqlite3_close(this->db); }

int DatabaseAdapter::Callback(void* data, int argc, char** argv,
                              char** az_col_name) {
  for (int i = 0; i < argc; i++) {
    std::cout << az_col_name[i] << " = " << (argv[i] ? argv[i] : "NULL")
              << std::endl;
  }

  std::cout << std::endl;
  return 0;
}

void DatabaseAdapter::Exec(const char* sql_query) {
  if (sqlite3_exec(db, sql_query, this->Callback, (void*)data,
                   &this->err_msg) == SQLITE_OK) {
    std::cout << "Operation done succesfully" << std::endl;
  } else {
    std::cerr << "SQL error: " << this->err_msg << std::endl;
    sqlite3_free(this->err_msg);
    return;
  }
}