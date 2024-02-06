/**
 * \file Matriz.hpp
 * \brief Implementaci&oacute;n de un Matriz algebraico
 * \author Irene Rodr&iacute;guez Castillo
 * \date 30/01/2024
 */

#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

/** \class Matriz
 *
 * Permite utilizar <b> Matrices algebraicas </b> y ofrece un conjunto de
operaciones b&aacute;sicas: suma, resta, multiplicaci&oacute;n de una
 * Matriz por un escalar, multiplicaci&oacute;n de matrices, inversa de una
Matriz, determinante de una Matriz.
 *
 *
 *
 * \code Ejemplo.cpp
#include <iostream>
#include "Matriz.hpp"

int main()
{
    Matriz v(2,2), w(2,2), resultate;

    std::cout << "Introduzca las 2 componentes de la primera Matriz..." <<
std::endl; cin >> v; std::cout << "Introduzca las 2 componentes de la segunda
Matriz..." << std::endl; cin >> w;

    resultante = v + w;

    std::cout << v << " + " << w << " = " << resultante << std::endl;

    resultante = v - w;

    std::cout << v << " - " << w << " = " << resultante << std::endl;

    std::cout << v << " * " << w << " = " << (v * w) << std::endl;

    resultante = v * 2.5;

    std::cout << v << " * " << 2.5 << " = " << resultante << std::endl;

    resultante = 2.5 * w;

    std::cout << 2.5 << " * " << w << " = " << resultante << std::endl;

    std::cout << v << "^-1 = " << v.inversa() << std::endl;

    std::cout << w << "^-1 = " << w.inversa() << std::endl;

    return 0;
}
 * \endcode
 *
 \verbatim Salida:
     Introduzca las 2 componentes de la primera Matriz...
     1
     2
     3
     4
     Introduzca las 2 componentes de la segunda Matriz...
     5
     6
     7
     8
     [1][2]
     [3][4]
     +
     [5][6]
     [7][8]
     =
     [6][8]
     [10][12]
     [1][2]
     [3][4]
     -
     [5][6]
     [7][8]
     =
     [-4][-4]
     [-4][-4]

faltaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
     (1, 2) * (3, 4) = 11
     (1, 2) * 2.5 = (2.5, 5)
     2.5 * (3, 4) = (7.5, 10)
     |(1, 2)| = 2.23607
     |(3, 4)| = 5
  \endverbatim
 *
 */
typedef unsigned int Dimension;

class Matriz {
    /** \brief Operador de inserci&oacute;n. Permite imprimir una matriz mediante un flujo de salida.
     *
     * \param out El flujo de salida.
     * \param A La matriz a imprimir.
     * \return El flujo de salida. Permite la aplicaci&oacute;n en cascada del operador.
     *
     */
    friend std::ostream &operator<<(std::ostream &os, const Matriz &A);
    /** \brief Operador de extracci&oacute;n. Permite capturar un vector mediante un flujo de entrada.
     *
     * \param in El flujo de entrada.
     * \param A La matriz a capturar.
     * \return El flujo de entrada. Permite la aplicaci&oacute;n en cascada del operador.
     *
     */
    friend std::istream &operator>>(std::istream &is, Matriz &A);
    /** \brief Operador de multiplicaci&oacute;n de escalar por Matriz.
     *
     * \param escalar El n&uacute;mero por el que se multiplica un Matriz.
     * \param A La Matriz a multiplicar.
     * \return La Matriz resultante de la multiplicaci&oacute;n por escalar.
     *
     * \exception const <b> char * </b> La Matriz resultante no puede ser creado.
     *
     */
    friend Matriz operator*(double escalar, const Matriz &A);
    
public:
    /** \brief Constructor.
     *
     * Versi&oacute;n 1: Constructor de una Matriz de dimensi&oacute;n 1 por omisi&oacute;n.
     *
     * Versi&oacute;n 2: Constructor de una Matriz de la dimensi&oacute;n indicada por \b dim. Operador de conversi&oacute;n expl&iacute;cita de \b int a \b Matriz.
     *
     * \param dim La dimensi&oacute;n de la Matriz a construir.
     *
     * \pre La dimensi&oacute;n debe ser un n&uacute;mero positivo.
     *
     * \exception const <b>char *</b> La Matriz no puede ser creado o la dimens&oacute;n no es positiva.
     *
     */
    explicit Matriz(Dimension n = 1, Dimension m = 1);

    /** \brief Constructor de copias.
     *
     * \param A La Matriz a copiar.
     *
     * \exception const <b>char *</b> La Matriz copia no puede ser creado.
     */
    Matriz(const Matriz &A);
    
    /** \brief Destructor.
     *
     */
    ~Matriz();
    
    /** \brief Operador de asignaci&oacute;n. Copia un matriz en otro matriz.
     *
     * \param A La matriz a copiar.
     * \return La matriz copia. Permite la aplicaci&oacute;n en cascada del operador.
     *
     * \exception const <b>char *</b> La matriz copia no puede ser creado.
     */
    Matriz& operator=(const Matriz& A);

    // Operadores para suma, resta, producto, producto por escalar
    Matriz operator+(const Matriz& A) const;
    Matriz operator-(const Matriz& A) const;
    Matriz operator*(const Matriz& A) const;
    Matriz operator*(double escalar) const;

    // Métodos para calcular la transpuesta e inversa
    Matriz transpuesta() const;
    Matriz inversa();

    // Método de redimensionamiento
    void resize(Dimension n, Dimension m);

    double Determinante();

    Dimension obtenerFilas();
    Dimension obtenerColumnas();
private:
    Dimension n;
    Dimension m;
    double **componentes;

    void establecerDim(Dimension, Dimension);
    void eliminarMatriz();
    void crearMatriz();     
    Matriz identidad();
};
#endif
