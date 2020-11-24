//
// Created by Junior Chunga on 23/11/20.
//

#include "Lista.h"
#include <iostream>

using namespace std;

Lista::Lista() {}

Lista::~Lista() {
    NodoLista* aux;
    while (ultimo){
        aux=ultimo;
        ultimo=ultimo ->siguiente;
        delete aux;
    }
}

void Lista::insertarLista(Pedido *valor) {
    NodoLista* aux;
    if(vacia()){
        primero = new NodoLista(valor, NULL);
        ultimo = primero;
    }
    else {
        aux = new NodoLista(valor, NULL);
        ultimo -> siguiente = aux;
        ultimo = aux;
    }
    cout << "Se ha insertado en la Lista" << endl;
}

void Lista::quitarLista() {

    cout << "Se ha quitado de la lista" << endl;

}

void Lista::deCola_a_Lista(Cola cola) {
    //Función de la salida del Pedido de Cola a la Lista

}

bool Lista::vacia() {
    //Comprobar si la lista está vacia
    return cabeza == NULL;
}

void Lista::insertarLista_Registrados(Pedido *valor) {
    //Viendo si es registrado, colocarlo al principio de la lista
    if (valor->tipoCliente()){
        insertarLista(valor);
    }
}

void Lista::insertarLista_NoRegistrados(Pedido *valor) {
    //Viendo si no es registrado, colocar en x posición de la lista
    if (valor->tipoCliente() == false){
        insertarLista(valor);
    }
}

void Lista::ordenar() {
    NodoLista* p = primero;
    NodoLista* j;
    while(p != NULL) {
        j = p->siguiente;
        while(j != NULL) {
            if(p->valor->getHora() > j->valor->getHora()) {
                Pedido* aux = j->valor;
                j->valor = p->valor;
                p->valor = aux;
            }
            j = j->siguiente;
        }
        p = p->siguiente;
    }
}

void Lista::juntarListas(Lista lista) {
    NodoLista* p = lista.primero;
    while(p != NULL) {
        this->insertarLista(p->valor);
        p = p->siguiente;
    }
}