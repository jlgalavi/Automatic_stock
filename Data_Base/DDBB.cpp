#include <iostream>
#include <pqxx/pqxx>

int main() {
    try {
        pqxx::connection c("dbname=DataBase user=postgres password=Gerfederer44 hostaddr=127.0.0.1 port=5432");
        if (c.is_open()) {
            std::cout << "Opened database successfully: " << c.dbname() << std::endl;
        } else {
            std::cout << "Can't open database" << std::endl;
            return 1;
        }
        c.disconnect();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}