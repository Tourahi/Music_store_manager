#ifndef MYSQL_H_INCLUDED
#define MYSQL_H_INCLUDED

#include <mysql_connection.h>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include <vector>


class MySql {
    sql::Driver     *driver;
    sql::Connection *cnn;
    sql::Statement  *statement;
    sql::ResultSet  *res;
    const sql::SQLString hostname;
    const sql::SQLString username;
    const sql::SQLString password;
public:
    MySql(std::string HostName, std::string UserName , std::string PassWord);
    void connect();
    void executeStatement(std::string Statement);
    void executeStatements(std::vector<std::string> Statement);
};

#endif // MYSQL_H_INCLUDED
