//
// Created by Junior Chunga on 07/11/2020.
//

#include "Pila.h"

using namespace std;

Pila::Pila() {
    ultimo = NULL;
}

Pila::~Pila() {
    NodoPila *aux;
    while (ultimo) {
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}

void Pila::apilar(Pedido *valor) {
    NodoPila *nuevo;
    nuevo = new NodoPila(valor, ultimo);
    ultimo = nuevo;
}

Pedido* Pila::desapilar() {
    Pedido* pedido;
    NodoPila *nodo;
    if (ultimo) {
        nodo = ultimo;
        ultimo = nodo->siguiente;
        pedido = nodo->valor;
        delete nodo;
    }
    return pedido;
}

bool Pila::vacia() {
    if (!ultimo) {
        return true;
    } else return false;
}