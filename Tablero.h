// Evita doble declaración
#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <vector>
// Manejo de archivos
#include <fstream>
using namespace std;

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