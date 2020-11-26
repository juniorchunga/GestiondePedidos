//
// Created by Junior Chunga on 07/11/2020.
//

#include <iostream>
#include <string>

#include "Cola.h"
//#include "time.h"


using namespace std;


Cola::Cola() {
    frente = NULL;
    ultimo = NULL;
}

Cola::~Cola() {}


void Cola::encolar(Pedido* v )
/*
 * Inserta un elemento a la cola
 */
{
    NodoCola *nuevo;
    nuevo = new NodoCola(v, NULL);
    if (frente){
        ultimo->siguiente = nuevo;
    }else {
        frente = nuevo;
    }
    ultimo = nuevo;
    cout << "Insertado" << endl;
}

Pedido* Cola::desencolar()
/*
 * Elimina el primer elemento de la cola
 */
{
    NodoCola* aux;
    Pedido* aux2;
    aux = frente;
    if(!frente){
        cout<<"Vacia, no es posible desencolar"<<endl;
    } else {
        frente = aux -> siguiente;
        aux2 = aux ->valor;
        //delete(aux);
        if (!frente) ultimo=NULL;
    }
    return aux2;
}

void Cola::verCola(Cola())
/*
 * Muestra el primero de la cola
 */
{}

Pedido* Cola::primero() {
    Pedido* x;
    if(!frente){
        cout<<"Error, Cola Vacia, no es posible ver primero"<<endl;
    } else {
        x=frente->valor;
    }
    return x;
}

void Cola::clasificar(Pedido *v, Cola cola1, Cola cola2) {
    if (v->tipoCliente()){
        cout << "El pedido es de un cliente registrado" << endl;
        cola1.encolar(v);
    }
    else {
        cout << "El pedido es de un cliente no registrado" << endl;
        cola2.encolar(v);
    }

}


bool Cola::esVacia() {
    return ((frente == NULL) && (ultimo == NULL));
}