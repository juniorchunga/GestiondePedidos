//
// Created by Junior Chunga on 10/12/20.
//

#ifndef PRACTICA1_ARBOL_H
#define PRACTICA1_ARBOL_H

#include "NodoArbol.h"

class Arbol {

public:
    Arbol();
    bool esVacio(NodoArbol *nodo); //devuelve si el arbol es vacío o no
    void insertarN(NodoArbol *&ab, Pedido *ped); //inserta un dato en nuestro arbol, pasamos un puntero por referencia, ya que el & modifica el contenido de nuestro arbol
    void mostrarA(NodoArbol *ab,int cont);//imprime por pantalla los datos de nuestro arbol
    void inorden(NodoArbol *n);//imprime el arbol en inorden
    void postorden(NodoArbol *n);//imprime el arbol en postorden
    void preorden(NodoArbol *n);//imprime el arbol en preorden
    void insertarNodoBB(NodoArbol *&ab, Pedido *ped);//insertar datos(nodos) en un arbol binario de busqueda
    int altura(NodoArbol *n); //devuelve la altura del arbol
    int hojas(NodoArbol *n); //devuelve el numero de hojas del arbol
    int nnodos(NodoArbol *n); //devuelve el numero de nodos del arbos
    int nnodos_internos(NodoArbol *n); //devuelve los nodos internos del arbol, descontando para ello las hojas
    bool lleno(NodoArbol *n);//nos devuelve si un arbol está lleno o no

private:
    NodoArbol raiz = NULL;

};


#endif //PRACTICA1_ARBOL_H
