// include clase
#include "Tablero.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

Tablero::Tablero(){
  tablero.resize(0);
}

Tablero::~Tablero(){

}

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

void Tablero::mostrarTablero(){
  for(int f=0; f < 10; f++){
    for(int c=0; c < 10; c++){
      cout << tablero[f][c] << " ";
    }
    cout << endl;
  }
}

int Tablero::getCelda(int posicionX, int posicionY){
  int celda = tablero[posicionX][posicionY];
  return celda;
  
}

