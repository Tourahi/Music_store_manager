#include <iostream>
#include "MySql.h"

int main()
{
    MySql mysql("tcp://127.0.0.1:3306", "debian-sys-maint", "KI2blgv9Hyap8w8y");
    mysql.connect();
    std::string statement = "select * from Animal";
    sql::ResultSet* res = mysql.executeStatement("Animals" , statement);
    while(res->next()) {
        std::cout << res->getString("id")
        << " : "
        << res->getString("nom") << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    delete res;
    res = mysql.executeStatement("keepitfresh" , "SELECT * FROM categories");
    while(res->next()) {
        std::cout << res->getString("id")
        << " : "
        << res->getString("name") << std::endl;
    }
    // Multiple statements
    std::string stat1 =  "select * from menus";
    std::string stat2 =  "select * from roles";
    std::string stat3 =  "select * from users";
    std::vector<std::string> stats = {stat1 , stat2 ,stat3};
    std::vector<sql::ResultSet*> Res = mysql.executeStatements("keepitfresh" , stats);

    std::cout << "---------------------" << std::endl;
    std::cout << Res.size() << std::endl;
    delete res;
    res = Res[0];
    while(res->next()) {
        std::cout << res->getString("id")
        << " : "
        << res->getString("name") << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    delete res;
    res = Res[1];
    while(res->next()) {
        std::cout << res->getString("id")
        << " : "
        << res->getString("name") << std::endl;
    }
    delete res;
    res = Res[2];
    std::cout << "---------------------" << std::endl;
    while(res->next()) {
        std::cout << res->getString("id")
        << " : "
        << res->getString("name") << std::endl;
    }

    return EXIT_SUCCESS;
}
