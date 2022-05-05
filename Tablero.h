// Evita doble declaración
#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <vector>
#include <stack>
// Manejo de archivos
#include <fstream>
using namespace std;

/*
Archivo: Tablero.h
Autor: Julian Alexander Alvarez Payares <alvarez.julian@correounivalle.edu.co>
Fecha de Creación: 03/05/2022
Ultima modificación: 04/05/2022
Licencia: GNU-GPL
GitHub: https://github.com/Anezeres 
*/

/*
CLASE: Tablero
INTENCIÓN: La intención de esta clase es generar un tablero de 1's y 0's que usará la clase avatar para avanzar


RELACIONES: No tiene relaciones, sin embargo será usada por la clase Avatar.
*/

// clase
class Tablero{
  // Atributos (estado interno)
  private:
    vector <vector <int> > tablero; 

  // Métodos
  public:
    Tablero();
    ~Tablero();
    void cargarTablero();
    void mostrarTablero();
    int getCelda(int, int);
};

#endif