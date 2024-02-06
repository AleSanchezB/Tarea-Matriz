#include <iostream>

#include "Matriz.hpp"

int main() {
    Matriz a(3, 2);
    //Matriz b(2, 2);

    std::cin >> a;
   // std::cin >> b;
    a.resize(1,2);

    std::cout<<a;
    return 0;
}
