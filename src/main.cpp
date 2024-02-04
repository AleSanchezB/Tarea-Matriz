#include <iostream>

#include "Matriz.hpp"

int main() {
    Matriz a(2, 3);
    Matriz b(2, 2);

    std::cin >> b;
    std::cout << b << std::endl << a;
    return 0;
}
