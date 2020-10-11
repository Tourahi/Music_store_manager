#include "MySql.h"
#include <fstream>
#include <iostream>

MySql::MySql(std::string HostName, std::string UserName , std::string PassWord)
:hostname(HostName) , username(UserName) , password(PassWord)
{
    this->driver = get_driver_instance();
}

void MySql::connect() {
    try {
        this->cnn = this->driver->connect(hostname,username,password);
        this->statement = this->cnn->createStatement();
    }catch (sql::SQLException &e) {
        std::cout << "# ERR: " << e.what() << std::endl;
        exit(1);
    }
}

void MySql::connectToDB(std::string dbName) {
    this->cnn->setSchema(dbName);
}

sql::ResultSet* MySql::executeStatement(std::string dbName,std::string Statement) {
   try{
        connectToDB(dbName);
        return this->statement->executeQuery(Statement);
    }catch (sql::SQLException &e) {
        std::cout << "# ERR: " << e.what() << std::endl;
        exit(1);
    }
}

sql::ResultSet* MySql::executeStatementsFromFile(std::string dbName,std::string file) {
    try {
        std::string statement = "";
        std::string line = "";
        std::ifstream File;
        File.open(file);
        while( std::getline(File , line) )
        {
            statement += line;
        }
        File.close();
        return this->executeStatement(dbName , statement);
    }catch(const std::ifstream::failure& e) {
        std::cout << "Error opening file " << file << " : " << e.what() << std::endl;
    }catch (sql::SQLException &e) {
        std::cout << "# ERR: " << e.what() << std::endl;
    }
}

std::vector<sql::ResultSet*> MySql::executeStatements(std::string dbName , std::vector<std::string> Statements) {
    std::vector<sql::ResultSet*> Results;
    for(int i = 0; i < Statements.size() ; i++) {
        Results.push_back(this->executeStatement(dbName,Statements[i]));
    }
    return Results;
}

void MySql::generateStatement() {
    delete statement;
    statement = this->cnn->createStatement();
}

MySql::~MySql() {
    delete this->statement;
    delete this->cnn;
}


