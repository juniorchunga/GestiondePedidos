//
// Created by Junior Chunga on 10/12/20.
//

#include "Arbol.h"
#include <iostream>

using namespace std;

Arbol::Arbol() {
    this->raiz = NULL;
}

//////////////////////ALTURA ARBOL///////////////////////////////////////
int Arbol::altura(NodoArbol *n){
    if(n==NULL){ //si nuestro nodo es null, entonces devolvemos 0 de altura
        return 0;
    }
    else{ // si el nodo contiene un dato, entonces
        int hijo_izquierdo = altura(n->izquierda); //guardamos la altura de los hijos izquierdos
        int hijo_derecho = altura(n->derecha); //guardamos la altura de los hijos derechos
        if(hijo_izquierdo>hijo_derecho){ //comparamos la altura de los hijos izquierdos con la altura de los hijos derechos y nos quedamos con el máximo
            return 1+hijo_izquierdo;
        }
        else{
            return 1+hijo_derecho;
        }
    }
}
////////////////////////Nº HOJAS DEL ARBOL/////////////////////////////////////
int Arbol::hojas(NodoArbol *n){ //pasamos un puntero a nodo
    if(n==NULL){ //si el nodo es null devolvemos 0
        return 0;
    }
    else{ //si es distinto de null entonces
        if((n->izquierda==NULL)&&(n->derecha==NULL)){ //si el hijo derecho y el hijo izquierdo, es decir, ambos son nulos entonces devolvemos 1, pues se trata de una hoja
            return 1;
        }
        else{ //si no son nulos, entonces, volvemos a llamar a la funcion hasta que llegamos a sus hojas
            return (hojas(n->izquierda)+hojas(n->derecha));
        }
    }
}
///////////////////////Nº NODOS DEL ARBOL//////////////////////////////////////
int Arbol::nnodos(NodoArbol *n){
    if(n==NULL){ //si el nodo es null entonces devolvemos 0, ya que no habría ningún nodo
        return 0;
    }
    else{ //si no, entonces sumamos 1 (para contar el nodo actual) y profundizamos por las ramas del árbol(llamando de forma recursiva a nuestra funcion) hasta que llegamos al final
        return (1+nnodos(n->izquierda)+nnodos(n->derecha));
    }
}
//////////////////Nº NODOS INTERNOS DEL ARBOL///////////////////////////////////////////////
int Arbol::nnodos_internos(NodoArbol *n){
    if(n==NULL){ //si nuestro nodo es null, es decir, que no hay dato, entonces devolvemos 0
        return 0;
    }
    else{ //restamos el numero de nodos al numero de hojas, ya que queremos aquellos nodos que no sean hojas
        return nnodos(n)-hojas(n);
    }
}
////////////////////ARBOL LLENO///////////////////////////
bool Arbol::lleno(NodoArbol *n){
    int resultado=1; //declaramos una variable de tipo entero que la inicializamos a 1 porque vamos a multiplicar sobre ella
    for(int i=0;i<(altura(n)-1);i++){ //restamos 1 a la altura de nuestro arbol
        resultado = 2*resultado; //operamos para sacar el resultado
    }
    if(nnodos(n) == resultado){ //si el numero de nodos es igual a nuestro resultado que proviene de hacer 2^(altura-1) entonces se trata de un arbol lleno
        return true; //y devolvemos true
    }
    else{ //si no, entonces devolvemos false
        return false;
    }
}
///////////////////INORDEN//////////////////////
void Arbol::inorden(NodoArbol *n){ //pasamos un nodo
    if(n!=NULL){ //si nuestro nodo es distino de null, es decir, tenemos un dato, entonces
        inorden(n->izquierda); //volvemos a llamar a la funcion de forma recursiva pero en este caso para el hijo izquierdo
        cout<<n->pedido<<"     "; //imprimimos el dato
        inorden(n->derecha);//hacemos lo mismo pero para el hijo derecho
    }
}
/////////////////////POSTORDEN///////////////////////////////
void Arbol::postorden(NodoArbol *n){ //pasamos un nodo
    if(n!=NULL){ //si nuestro nodo es distino de null, es decir, tenemos un dato, entonces
        inorden(n->izquierda); //volvemos a llamar a la funcion de forma recursiva pero en este caso para el hijo izquierdo
        inorden(n->derecha);//hacemos lo mismo pero para el hijo derecho
        cout<<n->pedido<<"     "; //imprimimos el dato
    }
}
////////////////////PREORDEN////////////////////////////////////
void Arbol::preorden(NodoArbol *n){ //pasamos un nodo
    if(n!=NULL){ //si nuestro nodo es distino de null, es decir, tenemos un dato, entonces
        cout<<n->pedido<<"     "; //imprimimos el dato
        inorden(n->izquierda); //volvemos a llamar a la funcion de forma recursiva pero en este caso para el hijo izquierdo
        inorden(n->derecha);//hacemos lo mismo pero para el hijo derecho

    }
}
/////////////////////INSERTAR NODO EN ARBOL BINARIO DE BUSQUEDA//////////////////////////////////
void Arbol::insertarNodoBB(NodoArbol *&ab, Pedido *v){
    if(ab==NULL){  //si el nodo que le pasamos es null, quiere decir, que se trata de un arbol vacío
        NodoArbol *nuevo = new NodoArbol(v); //creamos un nodo auxiliar en el que guardamos el dato que hemos pasado
        ab = nuevo;
    }
    else{ //si el nodo que le pasamos, ya tiene datos, entonces
        Pedido *valorRaiz = ab->pedido; //creamos una variable de tipo char porque nuestro dato es de tipo char. En esta variable guardamos el dato que contiene el nodo ab
        if(v < valorRaiz){ //comparamos el dato que vamos a meter en nuestro arbol con el dato que ya está guardado en la variable anterior y, si es menor que el que tenemos entonces
            insertarNodoBB(ab->izquierda,v);//buscamos insertar nuestro dato por la izquierda
        }
        else{ //si no, si nuestro dato es mayor que el que tenemos en la raiz, entonces
            insertarNodoBB(ab->derecha,v); //buscamos introducirlo por la derecha
        }
    }
}
///////////////ARBOL VACIO///////////////////////////
/*
bool Arbol::esVacio(NodoArbol *nodo){
    if(raiz == NULL){
        return true;
    } else return false;
}
*/
////////////////////INSERTAR NODO EN ARBOL BINARIO///////////////////////////
void Arbol::insertarN(NodoArbol *&ab,Pedido *v){ //pasamos un puntero a nodo arbol por referencia, ya que vamos a estar modificando el contenido de nuestro arbol
    if(ab==NULL){ //si el nodo es null, entonces
        NodoArbol *nuevo = new NodoArbol(v); //creamos un nuevo nodo en el que introducimos el dato
        ab = nuevo; //lo guardamos en nuestro nodo original
    }
    else{
        if(ab->derecha==NULL){ //si el hijo derecho está vacio, entonces vamos a introducir nuestro dato ahí
            insertarN(ab->derecha,v);
        }
        else{ //si ya tenemos dato en el hijo derecho, entonces introducimos nuestro dato por la izquierda
            insertarN(ab->izquierda,v);
        }
    }
}
//////////////////////IMPRIMIR ARBOL//////////////////////////////////
void Arbol::mostrarA(NodoArbol *ab,int cont){
    if(ab == NULL){
        return;
    }
    else{
        mostrarA(ab->derecha,cont+1);
        for(int i=0;i<cont;i++){
            cout<<"         ";
        }
        cout<<ab->pedido<<endl;
        mostrarA(ab->izquierda,cont+1);
    }

}