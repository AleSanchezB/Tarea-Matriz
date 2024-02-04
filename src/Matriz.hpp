#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

typedef unsigned int Dimension;
class Matriz {
public:
    // Constructor
    explicit Matriz(Dimension n = 1, Dimension m = 1);

    // Destructor
    ~Matriz();

    // Constructor de copias
    Matriz(const Matriz&, Dimension, Dimension);

    // Operador de asignación
    Matriz& operator=(const Matriz& A);

    // Operadores para suma, resta, producto, producto por escalar
    Matriz operator+(const Matriz& A) const;
    Matriz operator-(const Matriz& A) const;
    Matriz operator*(const Matriz& A) const;
    Matriz operator*(double escalar) const;
    friend Matriz operator*(int escalar, const Matriz& A);

    // Métodos para calcular la transpuesta e inversa
    Matriz transpuesta() const;
    Matriz inversa() const;

    // Método de redimensionamiento
    void resize(Dimension n, Dimension m);

    // Operadores para entrada y salida
    friend std::ostream& operator<<(std::ostream& os, const Matriz& A);
    friend std::istream& operator>>(std::istream& is, Matriz& A);

private:
    Dimension n;
    Dimension m;
    double **componentes;

    void establecerDim(Dimension, Dimension);
    void eliminarMatriz();
    void crearMatriz();
};
#endif
