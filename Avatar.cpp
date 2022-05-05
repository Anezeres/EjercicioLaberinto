// include clase
#include "Avatar.h"
#include "Tablero.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<algorithm>

using namespace std;


/*
Archivo: Avatar.cpp
Autor: Julian Alexander Alvarez Payares <alvarez.julian@correounivalle.edu.co>
Fecha de Creación: 03/05/2022
Ultima modificación: 04/05/2022
Licencia: GNU-GPL
GitHub: https://github.com/Anezeres 
*/


/* Constructor de la clase, debe recibir una posicion Inicial x, y. Y un respectivo tablero */

Avatar::Avatar(int posicionX, int posicionY, Tablero tablero){

  if((posicionX >= 0 and posicionX < 10) and  (posicionY >= 0 and posicionX < 10) ){
    this->posicionX = posicionX;
    this->posicionY = posicionY;
  }else{
    cout<<"Lo siento, la posicion indicada no es posible."<<endl;
  }

  this->tableroAvatar = tablero;
  caminosVisitados.resize(0);
  caminosPosibles.empty();
 
}

/* Destructor de la clase tablero */

Avatar::~Avatar(){}

/* Este metodo tiene el Objetivo de mostrar un mensaje al usuario de que 
el avatar ya se encuentra buscando el camino y ejecuta el metodo de posicionesPosibles*/

void Avatar::encontrarCamino(){
  cout<<endl<<endl<<"--------Se va a encontrar el camino----"<<endl;
  cout<<"\t Posicion X: "<< getPosicionX()<<endl;
  cout<<"\t Posicion Y: "<< getPosicionY()<<endl<<endl;
  posicionesPosibles();
}

/* Este metodo es el encargado de visualizar las celdas cercanas y determinar si se puede mover o no 
    Ver codigo entero para entender el procedimiento
*/

void Avatar::posicionesPosibles(){

  /* Se crean 4 viables a las 4 direcciones que puede tomar el avatar  y se crea un array de direcciones
    donde se insertaran los valores correspondientes de 0 y 1 con el metodo getCelda que se encuentra en 
    tablero*/

  int arriba, abajo, izquierda, derecha;
  vector <int> direcciones;

  /* Arriba */
  arriba = posicionX - 1;

  if(arriba >= 0){
    direcciones.push_back(tableroAvatar.getCelda(arriba,posicionY));
  }else{
    direcciones.push_back(0);
  }

   /* Derecha */
  derecha = posicionY + 1;
  
  if(izquierda <= 10){
    direcciones.push_back(tableroAvatar.getCelda(posicionX,derecha));
  }else{
    direcciones.push_back(0);
  }
  
  /* Abajo */
  abajo = posicionX + 1;
  
  if(abajo <= 9){
    direcciones.push_back(tableroAvatar.getCelda(abajo,posicionY));
  }else{
    direcciones.push_back(0);
  }
  
  /* Izquierda */
  izquierda = posicionY - 1;
  
  if(izquierda >= 0){
    direcciones.push_back(tableroAvatar.getCelda(posicionX,izquierda));
  }else{
    direcciones.push_back(0);
  }

  
  /* Una vez creadas las 4 variables, se determina si la casilla ha sido visitada o no ejecutando el metodo
    preguntarCeldaVisitada*/

  bool izquierdaVisitado = preguntarCeldaVisitada(posicionX,izquierda);
  bool abajoVisitado = preguntarCeldaVisitada(abajo,posicionY);
  bool derechaVisitado = preguntarCeldaVisitada(posicionX,derecha);
  bool arribaVisitado = preguntarCeldaVisitada(arriba,posicionY);


  /* Si la direccion encontrada en una direccion especifica es igual a 1 y ademas no ha sido visitada aun
    se ejecutará el metodo agregarCaminoPosible enviandole la posicion x,y*/
  
  if(direcciones[3] == 1 and not izquierdaVisitado){
    agregarCaminoPosible(posicionX,izquierda);
  }
  
  if(direcciones[2] == 1 and not abajoVisitado){
    agregarCaminoPosible(abajo,posicionY);
  }
  
  if(direcciones[1] == 1 and not derechaVisitado){
    agregarCaminoPosible(posicionX,derecha);
  }
  
  if(direcciones[0] == 1 and not arribaVisitado){
    agregarCaminoPosible(arriba,posicionY);
  }


  /* Por medio del metodo preguntarCeldaPosible se determina si una casilla ya se encuentra registrada
    en el vector de caminoPosible, si ya se encuentra registrado entonces no se podrá mover a dicha casilla */
  

  bool izquierdaPosible = preguntarCeldaPosible(posicionX,izquierda);
  bool abajoPosible = preguntarCeldaPosible(abajo,posicionY);
  bool derechaPosible = preguntarCeldaPosible(posicionX,derecha);
  bool arribaPosible = preguntarCeldaPosible(arriba,posicionY);

  /* se agregan los valores de 0 y 1 a unas variables para mayor comodidad */

  int celdaArriba = direcciones[0];
  int celdaDerecha = direcciones[1];
  int celdaAbajo = direcciones[2];
  int celdaIzquierda = direcciones[3];

  bool resultado1;

  /* SE COLOCA ESTE CODIGO AQUÍ Y NO EN UN METODO PUESTO QUE GENERA UN ERROR A LA HORA DE LEER EL MAPA*/
  /* Este fragmento de codigo se encarga de preguntarle al avatar si se encuentra en un estado sin salida
    Solo funciona para este mapa, en caso se añadir mas mapas de deben agregar los casos correspondientes. */

  if((celdaArriba == 0 and celdaDerecha == 0) and abajoVisitado == true and celdaIzquierda == 0){
    resultado1 = true;
  }else if(celdaArriba == 0 and celdaDerecha == 0 and abajoPosible == true and izquierdaPosible == true){
    resultado1 = true;
  }else if(arribaVisitado == true and celdaDerecha == 0 and celdaAbajo == 0 and izquierdaPosible == true){
    resultado1 = true;
  }else if(arribaPosible == true and derechaVisitado == true and celdaAbajo == 0 and celdaIzquierda == 0){
    resultado1 = true;
  }else if(celdaArriba == 0 and derechaPosible == true and abajoVisitado == true and celdaIzquierda == 0){
    resultado1 = true;
  }else if(arribaVisitado == true and celdaDerecha == 0 and celdaAbajo == 0 and celdaIzquierda == 0){
    resultado1 = true;
  }else if(izquierdaPosible == true and arribaVisitado == true and celdaAbajo == 0 and celdaDerecha == 0){
    resultado1 = true;
  }else if(celdaArriba == 0 and derechaVisitado == true and celdaAbajo == 0 and celdaIzquierda == 0){
    resultado1 = true;
  }else if(celdaArriba == 0 and celdaDerecha == 0 and abajoVisitado == true and celdaIzquierda == 0){
    resultado1 = true;
  }else if(celdaArriba == 0 and celdaDerecha == 0 and celdaAbajo == 0 and izquierdaPosible == true){
    resultado1 = true;
  }else{
    resultado1 = false;
  }

  /* En caso de que el Avatar si se encuentre en un estado sin salida, deberá sacar el ultimo vector de la pila de caminos posibles y deberá tomar el vector que no lo ingrese en un estado sin salida */


  if(resultado1){
    agregarCaminoVisitado();
    caminosPosibles.pop();
    cambiarPosicion();
    mostrarSolucion();
  }

  /* Si el avatar se encuentra en una posicion 9,9 significará que ha ganado y que ha encontrado el camino  */
  

  if(posicionX == 9 and posicionY == 9){
    cout<<"Has encontrado el camino."<<endl;
  }else if((posicionX > 0 and posicionX < 9) or (posicionY > 0 and posicionY < 9)){
    cambiarPosicion();
  }


  /*Fin del metodo posicionesPosibles()*/
}

/* Con este metodo se agrega al atributo caminos posibles de la clase avatar aquellos valores que cumplan con la
  condicion de tener 1 en su celda */

void Avatar::agregarCaminoPosible(int x, int y){
  vector <int> nuevoCaminoPosible;

  nuevoCaminoPosible.push_back(x);
  nuevoCaminoPosible.push_back(y);

  caminosPosibles.push(nuevoCaminoPosible);

}

/* Con este metodo se cambia la posicion del Avatar a los valores que tenga en el ultimo vector ingresado */

void Avatar::cambiarPosicion(){
  int nuevoX = caminosPosibles.top()[0];
  int nuevoY = caminosPosibles.top()[1];

  agregarCaminoVisitado();
  
  setPosicionX(nuevoX);
  setPosicionY(nuevoY);


  posicionesPosibles();

}

/* Si el Avatar cambió se posicion, la anterior posicion se guardará en un vector de vectores llamado CaminosVisitados */

void Avatar::agregarCaminoVisitado(){
  
  vector <int> nuevaPosicionVisitada;

  nuevaPosicionVisitada.push_back(posicionX);
  nuevaPosicionVisitada.push_back(posicionY);

  caminosVisitados.push_back(nuevaPosicionVisitada);

}

/* Si el avatar ya estuvo en una celda, no podrá volver a pisarla y por medio de este metodo que devuelve true o false se determina dicha condicion */

bool Avatar::preguntarCeldaVisitada(int x, int y){
  vector <int> posicionPreguntada;

  posicionPreguntada.push_back(x);
  posicionPreguntada.push_back(y);

  bool resultado = find(caminosVisitados.begin(), caminosVisitados.end(), posicionPreguntada) != caminosVisitados.end();

  return resultado;
}

/* Si el Avatar se encuentra en una posicion encerrada, no podrá moverse a una posicion posible, puesto que esto
dañaria el orden de mirar todas las casillas, esa es la razon de este metodo, devolverá true o false. */

bool Avatar::preguntarCeldaPosible(int x, int y){

  bool resultado;
  int i = 0;
  stack <vector <int>> aux = caminosPosibles;

  while(i < aux.size()){
    
    if(aux.top()[0] == x and aux.top()[1] == y){
      resultado = true;
    }else{
      resultado = false;
    }
    aux.pop();
    i++;
  }
  
  return resultado;
}

/* Con este metodo se mostrará por pantalla el orden que usó el avatar para recorrer el camino */


void Avatar::mostrarSolucion(){

    int i = 0;
  stack <vector <int>> aux = caminosPosibles;
  int longitudPila = aux.size();

  cout<<"Tamaño de la pila: "<<aux.size()<<endl;

/*   while(i < longitudPila){
    cout<<"X: "<< aux.top()[1] +1<<" , Y:";
    cout<< aux.top()[0] + 1<<endl;
    aux.pop();
    i++;
  } */


  while(i < longitudPila){
    cout<<"X: "<< aux
      .top()[0]<<" , Y:";
    cout<< aux.top()[1]<<endl;
    aux.pop();
    i++;
  }
  
}

/* Getter and Setters de algunos atributos */


int Avatar::getPosicionX(){
  return posicionX;
}

int Avatar::getPosicionY(){
  return posicionY;
}

void Avatar::setPosicionX(int nuevaX){
  this->posicionX = nuevaX;
}

void Avatar::setPosicionY(int nuevaY){
  this->posicionY = nuevaY;
}
