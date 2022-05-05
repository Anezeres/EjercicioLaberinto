// Evita doble declaración
#ifndef _AVATAR_H_
#define _AVATAR_H_
#include <stack>
#include <vector>
#include "Tablero.h"
using namespace std;

/*
Archivo: Avatar.h
Autor: Julian Alexander Alvarez Payares <alvarez.julian@correounivalle.edu.co>
Fecha de Creación: 03/05/2022
Ultima modificación: 04/05/2022
Licencia: GNU-GPL
GitHub: https://github.com/Anezeres 
*/


/*
CLASE: Avatar
INTENCIÓN: La intención de esta clase es generar objetos de tipo Avatar,
se le debe ingresar una posicion inicial x,y  y debe entregarle un tablero
RELACIONES: Tiene una relacion con Tablero.

*/

// clase
class Avatar{
  // Atributos (estado interno)
  private:
    int posicionX, posicionY;
    Tablero tableroAvatar;
    vector <vector <int> > caminosVisitados;
    stack < vector <int> > caminosPosibles;

  // Métodos
  public:
    Avatar(int, int, Tablero);
    ~Avatar();
    void encontrarCamino();
    void posicionesPosibles();
    void agregarCaminoPosible(int, int);
    void cambiarPosicion();
    bool analizarEstancamiento(int, int , int, int, bool, bool, bool, bool, bool, bool, bool, bool);
    void agregarCaminoVisitado();
    bool preguntarCeldaVisitada(int, int);
    bool preguntarCeldaPosible(int, int);
    int getPosicionX();
    int getPosicionY();
    void setPosicionX(int);
    void setPosicionY(int);
    void mostrarSolucion();

};

#endif