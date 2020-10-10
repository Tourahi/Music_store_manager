#include "MySql.h"
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


