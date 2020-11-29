//
// Created by Junior Chunga on 23/11/20.
//

#include "Lista.h"
#include <iostream>

using namespace std;

Lista::Lista() {}

Lista::~Lista() {
    NodoLista *aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

void Lista::insertarLista(Pedido *valor) {
    NodoLista *aux;
    if (vacia()) {
        primero = new NodoLista(valor, NULL);
        ultimo = primero;
    } else {
        aux = new NodoLista(valor, NULL);
        ultimo->siguiente = aux;
        ultimo = aux;
    }
}

void Lista::quitarLista() {
    NodoLista *aux;

    aux = primero;
    primero = aux->siguiente;
    delete aux;

    cout << "Se ha quitado de la lista" << endl;

}


bool Lista::vacia() {
    //Comprobar si la lista está vacia
    return primero == NULL;
}


void Lista::ordenar() {
    NodoLista *p = primero;
    NodoLista *j;
    while (p != NULL) {
        j = p->siguiente;
        while (j != NULL) {
            if (p->valor->getTiempo() > j->valor->getTiempo()) {
                Pedido *aux = j->valor;
                j->valor = p->valor;
                p->valor = aux;
            }
            j = j->siguiente;
        }
        p = p->siguiente;
    }
}


void Lista::juntarListas(Lista lista) {
    NodoLista *p = lista.primero;
    if (p != ultimo) {
        while (p->siguiente != NULL) {
            this->insertarLista(p->valor);
            p = p->siguiente;
        }
    } else this->insertarLista(p->valor);
}


void Lista::mostrarLista() {
    NodoLista* aux;
    aux = primero;
    while(aux) {
        (aux->valor)->leer();
        aux = aux->siguiente;
    }
    cout << endl;
}
