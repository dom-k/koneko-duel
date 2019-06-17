#include "DatabaseAdapter.h"
#include <iostream>
#include <typeinfo>

// TODO: Singleton
DatabaseAdapter::DatabaseAdapter() {
  if (sqlite3_open(this->db_file, &this->db) != SQLITE_OK) {
    std::cout << "Can't open database: " << sqlite3_errmsg(this->db)
              << std::endl;
    return;
  }
}

DatabaseAdapter::~DatabaseAdapter() { sqlite3_close(this->db); }

/**
 * Fill db_result class variable with database result.
 */
int DatabaseAdapter::Callback(int argc, char** argv, char** az_col_name) {
  for (int i = 0; i < argc; i++) {
    KeyValueStore key_value_store = KeyValueStore(
        std::string(az_col_name[i]), std::string(argv[i] ? argv[i] : ""));

    this->db_result.push_back(key_value_store);
  }
  return 0;
}

int DatabaseAdapter::C_callback(void* data, int argc, char** argv,
                                char** az_col_name) {
  DatabaseAdapter* database_adapter = static_cast<DatabaseAdapter*>(data);
  return database_adapter->Callback(argc, argv, az_col_name);
}

std::vector<KeyValueStore> DatabaseAdapter::Exec(const char* sql_query) {
  if (sqlite3_exec(db, sql_query, this->C_callback, this, &this->err_msg) ==
      SQLITE_OK) {
    // std::cout << "Operation done succesfully" << std::endl;
  } else {
    std::cerr << "SQL error: " << this->err_msg << std::endl;
    sqlite3_free(this->err_msg);
  }

  // TODO: Check if db_result is O.K.
  return this->db_result;
}