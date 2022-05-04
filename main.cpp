#include "Tablero.h"
#include <iostream>
#include "Avatar.h"
using namespace std;

int main() {
  Tablero tablero;
  tablero.cargarTablero();
  tablero.mostrarTablero();

  /* Posicionamiento del tablero (Y,X) */

  cout<<"Celda 0,0: "<<tablero.getCelda(0,0)<<endl;
  cout<<"Celda 0,1: "<<tablero.getCelda(1,0)<<endl;
  cout<<"Celda 0,2: "<<tablero.getCelda(2,0)<<endl;
  cout<<"Celda 0,3: "<<tablero.getCelda(3,0)<<endl;
  cout<<"Celda 0,4: "<<tablero.getCelda(4,0)<<endl;

  

  Avatar nuevoAvatar = Avatar(3,0, tablero);
  nuevoAvatar.encontrarCamino();

  
} 