#ifndef KONEKO_DUEL_DATABASEADAPTER_H
#define KONEKO_DUEL_DATABASEADAPTER_H

#include <iostream>
#include <sqlite3.h>

class DatabaseAdapter {
    private:
        std::string db_file;
        sqlite3* db;
        sqlite3_stmt* stmt;
        const char* data;
        char* err_msg = 0;
        // TODO: Change ** to &
        static int callback(void* data, int argc, char** argv, char** az_col_name);

    public:
        DatabaseAdapter(const char* db_file);
        void exec(const char* sql_query);
        ~DatabaseAdapter();
};

#endif // KONEKO_DUEL_DATABASEADAPTER_H