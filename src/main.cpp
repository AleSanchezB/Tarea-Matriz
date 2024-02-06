#include <iostream>

#include "Matriz.hpp"

int main() {
    Matriz a(2, 3);
    //Matriz b(2, 2);

    std::cin >> a;
   // std::cin >> b;
    //std::cout<<a;
    a.resize(2,3);

    std::cout<<a;
    return 0;
}
