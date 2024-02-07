/**
 * \file Matriz.hpp
 * \brief Implementaci&oacute;n de una Matriz algebraica
 * \author Joaqu&iacute;n Rafael Sotelo Islas
 * \author Braulio Alessandro S&aacute;nchez Berm&uacute;dez
 * \date 06/02/2024
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

    std::cout << v << "^-1 = " << v.inversa() << std::endl;

    std::cout << v << " * " << 2.5 << " = " << resultante << std::endl;

    return 0;
}
 * \endcode
 *
 \verbatim Salida:
     Introduzca las 4 componentes de la primera Matriz...
     1
     2
     3
     4
     Introduzca las 4 componentes de la segunda Matriz...
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

     [1][2]
     [3][4]
     *
     [5][6]
     [7][8]
     =
     [19][22]
     [43][50]

     [1][2]
     [3][4]
     ^-1
     =
     [-2][1]
     [1.5][-0.5]

     [1][2]
     [3][4]
     *
     2.5
     =
     [2.5][5]
     [7.5][10]

  \endverbatim
 *
 */
typedef unsigned int Dimension_tipo;

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
     * Versi&oacute;n 1: Constructor de una Matriz de dimensi&oacute;n 1 por
     omisi&oacute;n.
     *
     * Versi&oacute;n 2: Constructor de una Matriz de la dimensi&oacute;n indicada
     por \b n y m. Operador de conversi&oacute;n expl&iacute;cita de \b int a \b
     Matriz.
     *
     * \param n La dimensi&oacute;n de las filas de la Matriz a construir.
     *
     * \param m La dimensi&oacute;n de las columnas de la Matriz a construir.
     *
     * \pre La dimensi&oacute;n y m deben ser un n&uacute;meros positivos.
     *
     * \exception const <b>char *</b> La Matriz no puede ser creado o la dimens&oacute;n no es positiva.
     *
     */
    explicit Matriz(Dimension_tipo n = 1, Dimension_tipo m = 1);

    /** \brief Constructor de copias.
     *
     * \param A La Matriz a copiar.
     *
     * \exception const <b>char *</b> La Matriz copia no puede ser creado.
     */
    Matriz(const Matriz &A);

    /** \brief Destructor.
     *
     * Libera la memoria del arreglo bidimensional reservado por el constructor.
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

    /** \brief Operador para sumar dos matrices.
     *
     * \param A Sumando derecho.
     * \return La matriz resultante de la suma.
     *
     * \pre Las matrices a sumar deben ser de la misma dimensi&oacute;n.
     *
     * \exception const <b>char *</b> Las matrices a sumar no son de la misma dimensi&oacute;n o la matriz resultante no puede ser creado.
     */
    Matriz operator+(const Matriz& A) const;

    /** \brief Operador para restar dos matrices.
     *
     * \param A Restando derecho.
     * \return La matriz resultante de la resta.
     *
     * \pre Las matrices a sumar deben ser de la misma dimensi&oacute;n.
     *
     * \exception const <b>char *</b> Las matrices a restar no son de la misma dimensi&oacute;n o la matriz resultante no puede ser creado.
     */
    Matriz operator-(const Matriz &A) const;

    /** \brief Operador para multiplicar dos matrices.
     *
     * \param A El factor derecho.
     * \return La matriz resultado de la multiplicaci&oacute;n.
     *
     * \pre Sea la matriz A de nxm y la matriz B debe ser de dimensi&oacute;n mxa.
     *
     * \exception const <b>char *</b> Las matrices a multiplicar, la cantidad columnas de la matriz izquierda es diferente a la cantidad de filas de la derecha.
     */
    Matriz operator*(const Matriz &A) const;

    /** \brief Operador de multiplicaci&oacute;n de escalar por Matriz.
     *
     * \param escalar El n&uacute;mero por el que se multiplica un Matriz.
     * \return La Matriz resultante de la multiplicaci&oacute;n por escalar.
     *
     * \exception const <b> char * </b> La Matriz resultante no puede ser creado.
     *
     */
    Matriz operator*(double escalar) const;

    /** \brief Devuelve la matriz transpuesta.
     *
     * \param escalar El n&uacute;mero por el que se multiplica un Matriz.
     * \return La Matriz resultante de la multiplicaci&oacute;n por escalar.
     *
     * \exception const <b> char * </b> La Matriz resultante no puede ser creado.
     *
     */
    Matriz transpuesta() const;

    /** \brief Devuelve la matriz inversa.
     *
     * \return La Matriz resultante de la operaci&oacute;n inversa.
     *
     * \pre La matriz debe ser cuadrada (nxn).
     *
     * \exception const <b> char * </b> La Matriz no es invertible.
     *
     */   
    Matriz inversa() const;

    /** \brief Redimensiona la matriz.
     *
     * \param n El n&uacute;mero de filas
     * \param m El n&uacute;mero de columnas
     *
     * \exception const <b> char * </b> Si n o m no es un n&uacute;mero positivo.
     *
     */ 
    void resize(Dimension_tipo n, Dimension_tipo m);

    /** \brief Calcula el determinante de la matriz.
     *
     * \return El valor del determinante.
     *
     * \pre La matriz debe ser cuadrada (nxn).
     *
     * \exception const <b> char * </b> No puede calcular su determinante.
     *
     */
    double Determinante() const;

     /** \brief Devuelve el n&uacute;mero de filas.
     *
     * \return El valor de la dimension.
     *
     */
    Dimension_tipo obtenerFilas();

    /** \brief Devuelve el n&uacute;mero de columnas.
     *
     * \return El valor de la dimension.
     *
     */
    Dimension_tipo obtenerColumnas();
private:
    Dimension_tipo n;
    Dimension_tipo m;
    double **componentes;

    void establecerDim(Dimension_tipo, Dimension_tipo);
    void eliminarMatriz();
    void crearMatriz();     
    Matriz identidad() const;
};
#endif
