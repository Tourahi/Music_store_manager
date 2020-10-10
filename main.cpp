#include <iostream>
#include "MySql.h"

int main()
{
    MySql mysql("tcp://127.0.0.1:3306", "debian-sys-maint", "KI2blgv9Hyap8w8y");
    mysql.connect();
//    std::string statement = "select * from Animal";
    sql::ResultSet* res = mysql.executeStatemantsFromFile("Animals" ,
                        "/home/maro/Desktop/Cpp/Mysql/SqlTesting/SqlScripts/test.sql");
    while(res->next()) {
        std::cout << res->getString("id")
        << " : "
        << res->getString("nom") << std::endl;
    }

    return 0;
}
