#include "Matriz.hpp"

/***********************************************************************************************/
Matriz::Matriz(Dimension_tipo n, Dimension_tipo m) {
    try {
        establecerDim(n,m);
        crearMatriz();
        for (Dimension_tipo i = 0; i < n; ++i) {
            for (Dimension_tipo j = 0; j < m; ++j) {
                *(*(componentes + i) + j) = 0;
          }
        }
    }catch(std::bad_alloc &){
        throw "No pudo ser creado la matriz";
    }
}

/***********************************************************************************************/
Matriz::Matriz(const Matriz &A) : n(0), m(0), componentes(nullptr) {
  *this = A;
}
/***********************************************************************************************/
Matriz::~Matriz() {
    eliminarMatriz();
}

/***********************************************************************************************/
std::ostream & operator<<(std::ostream &out, const Matriz &A)
{
    for (Dimension_tipo i = 0; i < A.n; ++i) {
        for(Dimension_tipo j = 0; j < A.m; ++j){
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
    try {
        if(n != A.n || m != A.m){
            eliminarMatriz();
            n = A.n;
            m = A.m;
            crearMatriz();
        }
        for (Dimension_tipo i = 0; i < n; ++i) {
            for (Dimension_tipo j = 0; j < m; ++j) {
                *(*(componentes+i)+j) = *(*(A.componentes+i)+j);
            }
        }
    }catch(std::bad_alloc &){
        throw "No pudo ser creado la matriz";
    }
    return *this;
}

/***********************************************************************************************/
std::istream & operator>>(std::istream &in, Matriz &A){
    for (Dimension_tipo i = 0; i < A.n; ++i) {
        for (Dimension_tipo j = 0; j < A.m; ++j) {
            in >> *(*(A.componentes + i) + j);
        }
    }
    return in;
}

/***********************************************************************************************/
Matriz Matriz::operator*(const Matriz &A) const {
    if (m != A.n)
        throw "No es posible realizar la multiplicación";
    Matriz r(n, A.m);

    double s = 0;
    for (Dimension_tipo i = 0; i < n; ++i) {
        for (Dimension_tipo j = 0; j < A.m; ++j) {
            for (Dimension_tipo k = 0; k < m; ++k) {
                s += *(*(componentes + i)+ k) * *(*(A.componentes + k) + j);
            }
            *(*(r.componentes + i)+j) = s;
            s = 0;
      }
    }
    return r;
}
/***********************************************************************************************/
Matriz Matriz::inversa() const {     
    if(n != m || Determinante() == 0) throw "No se puede calcular la inversa";
    Matriz r(n, m);
    r = *this;
    Matriz I = identidad();

    Dimension_tipo filapivote;
    double pivote, aux;

    for (Dimension_tipo i = 0; i < n; ++i) {
        filapivote = i;

        while (*(*(componentes + filapivote) + i) == 0) {
            ++filapivote;
            if(filapivote >= n) throw "La matriz no es invertible";
        }

        for (Dimension_tipo j = 0; j < n; ++j) {
            aux = *(*(r.componentes + i) + j);
            *(*(r.componentes + i) + j) = *(*(r.componentes + filapivote) + j);
            *(*(r.componentes + filapivote) + j) = aux;

            aux = *(*(I.componentes + i) + j);
            *(*(I.componentes + i) + j) = *(*(I.componentes + filapivote) + j);
            *(*(I.componentes + filapivote) + j) = aux;
        }
        pivote = *(*(r.componentes + i) + i);

        for (Dimension_tipo j = 0; j < n; ++j) {
            *(*(r.componentes + i) + j) /= pivote;
            *(*(I.componentes + i) + j) /= pivote;
        }
        for (Dimension_tipo j = 0; j < n; ++j) {
            if (i == j)
                continue;
            aux = *(*(r.componentes + j) + i);
            for (Dimension_tipo k = 0; k < n; ++k) {
                *(*(r.componentes + j) + k) -= aux* *(*(r.componentes + i) + k);
                *(*(I.componentes + j) + k) -= aux* *(*(I.componentes + i) + k);
            }
        }
    }
    
    return I;
}
/***********************************************************************************************/
double Matriz::Determinante() const {
    if(n != m) throw "No se puede calcular su determinante";
    if(n == 1) return *(*(componentes));

    double det = 0;
    Matriz subMatriz(n - 1, n - 1);
    for (Dimension_tipo i = 0; i < n; ++i) {
        Dimension_tipo subMatriz_fila = 0;
        for (Dimension_tipo j = 1; j < n; ++j) {
            Dimension_tipo subMatriz_col = 0;
            for (Dimension_tipo k = 0; k < n; ++k) {
                if(k == i) continue;
                *(*(subMatriz.componentes + subMatriz_fila) + subMatriz_col) =
                    *(*(this->componentes + j) + k);
                ++subMatriz_col;
            }
            ++subMatriz_fila;
        }

        int signo = (i % 2 == 0) ? 1 : -1;
        double cofactor = subMatriz.Determinante();
        det += signo * *(*(componentes) + i)* cofactor;
    }
    
    return det;
}
/***********************************************************************************************/
Matriz Matriz::identidad() const{
    Matriz I(n, m);

    for (Dimension_tipo i = 0; i < n; ++i) *(*(I.componentes + i)+i) = 1;    
    return I;
}
/***********************************************************************************************/
void Matriz::establecerDim(Dimension_tipo n, Dimension_tipo m) {
    if (n < 1 || m < 1)
        throw "Error: fila/columna fuera de rango";
    this->n = n;
    this->m = m;
}
/***********************************************************************************************/
void Matriz::crearMatriz() {
    componentes = new double*[n];
    for (Dimension_tipo i = 0; i < this->n; ++i) {
        *(componentes+i) = new double[m];
    }
}
/***********************************************************************************************/
void Matriz::eliminarMatriz() {
    for (Dimension_tipo i = 0; i < this->n; ++i) {
        delete[] *(componentes + i);
    }
    delete[] componentes;
    componentes = nullptr;
}
/***********************************************************************************************/
Matriz Matriz::operator+(const Matriz&A) const {
    if (n != A.n || m != A.m)
        throw "No es posible realizar la suma";
    Matriz r(n,m);
    for(Dimension_tipo i=0; i < n; ++i) {
        for(Dimension_tipo j=0; j < m; ++j) {
            *(*(r.componentes + i) + j) = *(*(componentes + i) + j) + *(*(A.componentes + i) + j);
        }
    }
    return r;
}
/***********************************************************************************************/
Matriz Matriz::operator-(const Matriz&A) const {
    if (n != A.n || m != A.m)
        throw "No es posible realizar la resta";
    Matriz r(n,m);
    for(Dimension_tipo i=0; i < n; ++i) {
        for(Dimension_tipo j=0; j < m; ++j) {
            *(*(r.componentes + i) + j) = *(*(componentes + i) + j) - *(*(A.componentes + i) + j);
        }
    }
    return r;
}
/***********************************************************************************************/
Matriz Matriz::operator*(double escalar) const {
    Matriz r(n,m);
    for(Dimension_tipo i=0; i < n; ++i) {
        for(Dimension_tipo j=0; j < m; ++j) {
            *(*(r.componentes + i) + j) = escalar * *(*(componentes + i) + j);
        }
    }
    return r;
}
/***********************************************************************************************/
Matriz operator*(double escalar, const Matriz& A) {
    Matriz r(A.n,A.m);
    for(Dimension_tipo i=0; i < A.n; ++i) {
        for(Dimension_tipo j=0; j < A.m; ++j) {
            *(*(r.componentes + i) + j) = escalar * *(*(A.componentes + i) + j);
        }
    }
    return r;
}
/***********************************************************************************************/
Matriz Matriz::transpuesta() const{
    Matriz r(m,n);
    for(Dimension_tipo i=0; i < n; ++i) {
        for(Dimension_tipo j=0; j < m; ++j) {
            *(*(r.componentes + j) + i) = *(*(componentes + i) + j);
        }
    }
    return r;
}
/***********************************************************************************************/
void Matriz::resize(Dimension_tipo n, Dimension_tipo m) {
    if (this->n == n && this->m ==m) return; //Checa si las nuevas dimensiones son iguales y termina si lo son     
    Matriz r(n, m); // Crea nueva matriz con dimensiones nuevas
    this->n = (this->n > n) ? n : this->n;
    this->m = (this->m > m) ? m : this->m;

    for(Dimension_tipo i=0; i < this->n; ++i) {
        for(Dimension_tipo j=0; j < this->m; ++j) {             
            *(*(r.componentes + i) + j) = *(*(componentes + i) + j);
        }
    }
    *this = r;
}
/***********************************************************************************************/
Dimension_tipo Matriz::obtenerColumnas() { return m; }
/***********************************************************************************************/
Dimension_tipo Matriz::obtenerFilas() { return n; }
/***********************************************************************************************/
