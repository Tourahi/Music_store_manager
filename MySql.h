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
    MySql(std::string HostName, std::string UserName , std::string PassWord); // Create a driver instance
    void connect(); // Create a connection &&  Create a statement
    sql::ResultSet* executeStatement(std::string dbName,std::string Statement); // Execute one statement
    std::vector<sql::ResultSet*> executeStatements(std::string dbName,std::vector<std::string> Statement); // Execute a vector of statements
    sql::ResultSet* executeStatemantsFromFile(std::string dbName,std::string fileName); // Execute statements from a given file
    void connectToDB(std::string dbName);
    ~MySql();
};

#endif // MYSQL_H_INCLUDED
