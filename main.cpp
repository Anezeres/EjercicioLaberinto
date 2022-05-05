#include "Tablero.h"
#include <iostream>
#include "Avatar.h"
using namespace std;

/*
Archivo: main.cpp
Autor: Julian Alexander Alvarez Payares <alvarez.julian@correounivalle.edu.co>
Fecha de Creación: 03/05/2022
Ultima modificación: 04/05/2022
Licencia: GNU-GPL
GitHub: https://github.com/Anezeres 
*/

/*
HISTORIA: 
Crear una clase Tablero que representa un laberinto y una clase Avatar que representará
un jugador que deberá encontrar la salida.
*/


int main() {

  /* Se crea una instancia de tablero y se carga */
  Tablero tablero;
  tablero.cargarTablero();

  cout<<"\t\t ------TABLERO------"<<endl<<endl;

  /* Se muestra el tablero */
  
  tablero.mostrarTablero();

  /* Se crea una instancia de Avatar en la posicion 3,0 y se le ingresa el tablero creado anteriormente*/

  Avatar nuevoAvatar = Avatar(3,0, tablero);

  /* Se encuentra el Camino */
  
  nuevoAvatar.encontrarCamino();
  
} 