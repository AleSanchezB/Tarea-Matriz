#include "Matriz.hpp"

/***********************************************************************************************/
Matriz::Matriz(Dimension n, Dimension m) {
    try {
        establecerDim(n,m);
        crearMatriz();
        for (Dimension i = 0; i < n; ++i) {
            for (Dimension j = 0; j < m; ++j) {
                *(*(componentes + i) + j) = 0;
          }
        }
    }catch(std::bad_alloc &){
        throw "No pudo ser creado la matriz";
    }
}

/***********************************************************************************************/
Matriz::Matriz(const Matriz &A, Dimension n, Dimension m) : n(n), m(m), componentes(nullptr) {
//    *this = A;
    
}

/***********************************************************************************************/
Matriz::~Matriz() {
    eliminarMatriz();
}

/***********************************************************************************************/
std::ostream & operator<<(std::ostream &out, const Matriz &A)
{
    for (Dimension i = 0; i < A.n; ++i) {
        for(Dimension j = 0; j < A.m; ++j){
          out <<
          "[" << *(*(A.componentes + i) + j) << "]";
        }
        out << std::endl;
    }
    return out;
}

/***********************************************************************************************/
Matriz& Matriz::operator=(const Matriz &A)
{
    if(this == &A) return *this;
    try{
        if(n != A.n || m != A.m){
            n = A.n;
            m = A.m;
            eliminarMatriz();
            crearMatriz();
        }
        for (Dimension i = 0; i < n; ++i) {
            for(Dimension j = 0; j < m; ++j){
                *(*(componentes+i)+j) = *(*(A.componentes+i)+j);
            }
        }
    }catch(std::bad_alloc &){
        throw "No pudo ser creado un vector";
    }
    return *this;
}

/***********************************************************************************************/
std::istream & operator>>(std::istream &in, Matriz &A)
{
    for (Dimension i = 0; i < A.n; ++i) {
        for (Dimension j = 0; j < A.m; ++j) {
            in >> *(*(A.componentes + i) + j);
        }
    }
    return in;
}

/***********************************************************************************************/
Matriz Matriz::operator*(const Matriz &A) const {
    if (m != A.n)
        throw "No es posible realizar la multiplicación";
    Matriz r(A, n, A.m);

    for (Dimension i = 0; i < n; ++i) {
        for (Dimension j = 0; j < m; ++j) {
            
        }
    }
    return r;
}
/***********************************************************************************************/
void Matriz::establecerDim(Dimension n, Dimension m) {
    if (n < 1 || m < 1)
        throw "Error: fila/columna fuera de rango";
    this->n = n;
    this->m = m;
}
/***********************************************************************************************/
void Matriz::crearMatriz() {
    componentes = new double*[n];
    for (Dimension i = 0; i < this->n; ++i) {
        *(componentes+i) = new double[m];
    }
}
/***********************************************************************************************/

void Matriz::eliminarMatriz() {
    for (Dimension i = 0; i < this->n; ++i) {
        delete[] *(componentes + i);
    }
    delete componentes;
    componentes = nullptr;
}
/***********************************************************************************************/