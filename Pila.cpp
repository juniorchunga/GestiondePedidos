//
// Created by Junior Chunga on 07/11/2020.
//

#include "Pila.h"
using namespace std;

Pila::Pila() {
    ultimo=NULL;
}
Pila::~Pila() {
    NodoPila* aux;
    while (ultimo){
        aux=ultimo;
        ultimo=ultimo->siguiente;
        delete aux;
    }
}

void Pila::apilar(Pedido *valor) {
    NodoPila* nuevo;
    nuevo=new NodoPila(valor, ultimo);
    ultimo=nuevo;
    cout << "Apilado" << endl;
}

void Pila::desapilar() {
    NodoPila* nodo;
    if(ultimo){
        nodo=ultimo;
        ultimo=nodo ->siguiente;
        delete nodo;
    }
    else cout << "pila vacia" << endl;
}

void Pila::verPila() {
    NodoPila* aux = ultimo;
    if(!aux){
        cout << "Pila vacia" << endl;
    }
    else {
        cout <<"Datos de la pila: "<< endl;
        while (aux){
            cout<<aux->valor<<",";
            aux = aux->siguiente;
        }
    }
    cout << endl;
}


void Pila::dePilaACola(Cola cola){
    Pedido* ped;

    ped = cola.desencolar();
    if(ped->datoErroneo()){
        apilar(ped);
    } else{
        apilar(ped);
    }

}

bool Pila::vacia() {
    if(!ultimo ){
        return true;
    } else return false;
}