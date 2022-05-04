// include clase
#include "Avatar.h"
#include "Tablero.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

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

Avatar::~Avatar(){}

void Avatar::encontrarCamino(){
  cout<<"--------Se va a encontrar el camino----"<<endl;
  cout<<"Posicion X: "<< getPosicionX()<<endl;
  cout<<"Posicion Y: "<< getPosicionY()<<endl;

  posicionesPosibles();

}



void Avatar::posicionesPosibles(){

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
  
 
  
  cout<<"------Direcciones Posiciones-----"<<endl;
  cout<<"posicion X: "<<posicionX<<endl;
  cout<<"posicion Y: "<<posicionY<<endl;
  cout<<"Arriba: "<<arriba<<endl;
  cout<<"Derecha: "<<derecha<<endl;
  cout<<"Abajo:"<<abajo<<endl;
  cout<<"Izquierda: "<<izquierda<<endl<<endl;
  
  cout<<"------Direcciones 1 y 0 -----"<<endl;
  cout<<"Dirrecion Arriba  ^ : "<<direcciones[0]<<endl;
  cout<<"Dirrecion Derecha > : "<<direcciones[1]<<endl;
  cout<<"Dirrecion Abajo v : "<<direcciones[2]<<endl;
  cout<<"Dirrecion Izquierda < : "<<direcciones[3]<<endl; 




  if(direcciones[3] == 1){
    agregarCaminoPosible(posicionX,izquierda);
  }
  
  if(direcciones[2] == 1){
    agregarCaminoPosible(abajo,posicionY);
  }
  
  if(direcciones[1] == 1){
    agregarCaminoPosible(posicionX,derecha);
  }
  
  if(direcciones[0] == 1){
    agregarCaminoPosible(arriba,posicionY);
  }

  /* De momento */
  int i = 0;
  stack <vector <int>> aux = caminosPosibles;

  cout<<"Tamaño de la pila: "<<aux.size()<<endl;

  while(i <= aux.size()){
    cout<<"X: "<< aux.top()[0]<<" , Y:";
    cout<< aux.top()[1]<<endl;
    aux.pop();
    i++;
  }

  /* Hay un problema, no sé porqué carajos me imprime solo algunos y no todos
los elementos del stack, igual me sigue mostrando una longitud correcta,
Yo seguiré así, no me preocuparé por eso */



  /* Fin */

  cout<<endl<<"----Se va a cambiar la posicion------"<<endl<<endl;

  if(posicionX > 0 and posicionX < 9){
    cambiarPosicion();
  }

}

void Avatar::agregarCaminoPosible(int x, int y){
  vector <int> nuevoCaminoPosible;

  nuevoCaminoPosible.push_back(x);
  nuevoCaminoPosible.push_back(y);

  caminosPosibles.push(nuevoCaminoPosible);

}


void Avatar::cambiarPosicion(){
  int nuevoX = caminosPosibles.top()[0];
  int nuevoY = caminosPosibles.top()[1];

  setPosicionX(nuevoX);
  setPosicionY(nuevoY);

  agregarCaminoVisitado();

  posicionesPosibles();

}

void Avatar::agregarCaminoVisitado(){
  vector <int> nuevaPosicionVisitada;

  nuevaPosicionVisitada.push_back(posicionX);
  nuevaPosicionVisitada.push_back(posicionY);

  

}

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




  //TODO, YA SEPARÉ CADA UNA DE LA POSICIONES POSIBLES SI ES 1 O 0, AHORA LO QUE HAY QUE HACER
  /*AHORA ES AGREGAR AQUELLAS POSICIONES A UN STACK DE LAS POSICIONES POSIBLES Y QUE
  CUANDO YA LA HALLA VISITADO PUES NO VUELVA A PISARLA.

  OSEA QUE TENGA ALMENOS 1 OPCION, MAXIMO 4, Y QUE META CADA OPCION Y LAS PONGA EN UN STACK,
  QUE AGARRE UNA DE ELLAS Y LA SAQUE DEL STACK Y LA META EN UN VECTOR DE POSICIONES VISITADAS,
  SI SE ENCUENTRA EN UNA POSICION SIN SALIDA, VOLVERÁ AL ULTIMO VALOR DE STACK SIN VISITAR E IRÁ DE    ESA FORMA VISITADON CADA UNA DE LAS POSIBILIDADES.
    

  */