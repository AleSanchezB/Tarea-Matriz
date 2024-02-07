#include <iostream>

#include "Matriz.hpp"

int main() {
    try{
        Matriz a(3, 3);
        Matriz b(2, 2);
        
        std::cin >> a;
        std::cin >> b;
        std::cout << a << std::endl;
        a.resize(6,7);
        std::cout << a.transpuesta() << std::endl;
    } catch (const char* e) {
        std::cout << e;
    }
    return 0;
}
