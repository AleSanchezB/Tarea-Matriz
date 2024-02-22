#include <iostream>

#include "Matriz.hpp"

int main() {
    try{
        Matriz a(2, 2);
        Matriz b(2, 2);
        
        std::cin >> a;
        std::cin >> b;
        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << a.Determinante() << std::endl;
        std::cout << b.Determinante() << std::endl;

        std::cout << a.transpuesta() << std::endl;
        std::cout << b.transpuesta() << std::endl;

        std::cout << a * 2.5 << std::endl;
        std::cout << 2.5 * a << std::endl;

        std::cout << b * 2.5 << std::endl;
        std::cout << 2.5 * b << std::endl;
        
        std::cout << a.inversa() << std::endl;
        std::cout << b.inversa() << std::endl;

        std::cout << a.obtenerColumnas() << std::endl;
        std::cout << b.obtenerColumnas() << std::endl;

        std::cout << a.obtenerFilas() << std::endl;
        std::cout << b.obtenerFilas() << std::endl;

        std::cout << a * b << std::endl;
        std::cout << b * a << std::endl;

        a.resize(4, 4);
        a.resize(4, 4);

        std::cout << a.transpuesta() << std::endl;
        std::cout << b.transpuesta() << std::endl;
        
    } catch (const char* e) {
        std::cout << e;
    }
    return 0;
}
