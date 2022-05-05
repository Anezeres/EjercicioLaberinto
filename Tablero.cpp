// include clase
#include "Tablero.h"
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

/*
Archivo: Tablero.cpp
Autor: Julian Alexander Alvarez Payares <alvarez.julian@correounivalle.edu.co>
Fecha de Creación: 03/05/2022
Ultima modificación: 04/05/2022
Licencia: GNU-GPL
GitHub: https://github.com/Anezeres 
*/

/*Constructor de la clase Tablero*/

Tablero::Tablero(){
  tablero.resize(0);
}

/*Destructor de la clase Tablero*/

Tablero::~Tablero(){

}

/* Este metodo es el encargado de mirar el archivo tablero.txt y convertir su contenido de string a enteros */

void Tablero::cargarTablero(){
  ifstream abrirPlano("tablero.txt");
  string linea;
  int aux;
  string split;
  
  // Recorrer los elementos del archivo planos
  
  while(getline(abrirPlano, linea)){
    vector <int> auxVector;
    for(int j=0; j < 19; j = j+2){
      split = linea.substr(j, 1);
      auxVector.push_back(stoi(split));
    }
    
    tablero.push_back(auxVector); 
  }
}

/* Con este metodo se mostrará en pantalla el tablero del mapa */

void Tablero::mostrarTablero(){
  for(int f=0; f < 10; f++){
    for(int c=0; c < 10; c++){
      cout << tablero[f][c] << " ";
    }
    cout << endl;
  }
}

/* Con este metodo se podrá acceder a la informacion de una celda en especifico, devolverá 0 o 1*/

int Tablero::getCelda(int posicionX, int posicionY){
  int celda = tablero[posicionX][posicionY];
  return celda;
  
}

