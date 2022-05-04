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

Avatar::~Avatar(){

}

void Avatar::encontrarCamino(){
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
  
  /* Derecha */
  derecha = posicionY + 1;
  
  if(izquierda <= 10){
    direcciones.push_back(tableroAvatar.getCelda(posicionX,derecha));
  }else{
    direcciones.push_back(0);
  }
  
  cout<<"------Direcciones Posiciones-----"<<arriba<<endl;
  cout<<"posicion X: "<<posicionX<<endl;
  cout<<"posicion Y: "<<posicionY<<endl;
  cout<<"Arriba: "<<arriba<<endl;
  cout<<"Derecha: "<<derecha<<endl;
  cout<<"Abajo:"<<abajo<<endl;
  cout<<"Izquierda: "<<izquierda<<endl<<endl;
  
  cout<<"------Direcciones 1 y 0 -----"<<arriba<<endl;
  cout<<"Dirrecion Arriba  ^ : "<<direcciones[0]<<endl;
  cout<<"Dirrecion Derecha > : "<<direcciones[3]<<endl;
  cout<<"Dirrecion Abajo v : "<<direcciones[1]<<endl;
  cout<<"Dirrecion Izquierda < : "<<direcciones[2]<<endl; 

  //TODO, YA SEPARÉ CADA UNA DE LA POSICIONES POSIBLES SI ES 1 O 0, AHORA LO QUE HAY QUE HACER
  /*AHORA ES AGREGAR AQUELLAS POSICIONES A UN STACK DE LAS POSICIONES POSIBLES Y QUE
  CUANDO YA LA HALLA VISITADO PUES NO VUELVA A PISARLA.

  OSEA QUE TENGA ALMENOS 1 OPCION, MAXIMO 4, Y QUE META CADA OPCION Y LAS PONGA EN UN STACK,
  QUE AGARRE UNA DE ELLAS Y LA SAQUE DEL STACK Y LA META EN UN VECTOR DE POSICIONES VISITADAS,
  SI SE ENCUENTRA EN UNA POSICION SIN SALIDA, VOLVERÁ AL ULTIMO VALOR DE STACK SIN VISITAR E IRÁ DE    ESA FORMA VISITADON CADA UNA DE LAS POSIBILIDADES.
    

  */
  

/*   if( == 1){
    cout<<"Arriba está disponible"<<endl;
    
  }else if( == 1){
    cout<<"Abajo está disponible"<<endl;
    
  }else if( == 1){
    cout<<"La Izquierda está disponible"<<endl;
    
  }else if( == 1){
    cout<<"La Derecha está disponible"<<endl;
    
  } */




  

}


void Avatar::cambiarPosicion(){

}

void Avatar::agregarCaminoVisitado(){

}

int Avatar::getPosicionX(){
  return posicionX;
}

int Avatar::getPosicionY(){
  return posicionY;
  
}