// Evita doble declaración
#ifndef _AVATAR_H_
#define _AVATAR_H_
#include <stack>
#include <vector>
#include "Tablero.h"
using namespace std;

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
    void cambiarPosicion();
    void agregarCaminoVisitado();
    void agregarCaminoPosible();
    int getPosicionX();
    int getPosicionY();


};

#endif