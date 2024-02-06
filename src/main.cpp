#include <iostream>

#include "Matriz.hpp"

int main() {
    try{
        Matriz a(2, 2);
        Matriz b(2, 2);
        
        std::cin >> a;
        std::cout << a << std::endl;
        a.resize(1,1);
        std::cout << a << std::endl;
    } catch (const char* e) {
        std::cout << e;
    }
    return 0;
}
