//
// Created by Junior Chunga on 07/11/2020.
//

#include <cstdlib>
#include <iostream>
#include "Pedido.h"

using namespace std;


Pedido::Pedido(string descripcion, string nombre, string direccion, string tipo_cliente, long num_tarjeta, int tiempo) {
    this -> descripcion = descripcion;
    this -> nombre = nombre;
    this -> direccion = direccion;
    this -> tipo_cliente = tipo_cliente;
    this -> num_tarjeta = num_tarjeta;
    this -> tiempo = tiempo;
}


/*
int Pedido::tiempoAleatorio(int tiempo) {
    tiempo = 0;
    tiempo = rand()%10+ 1;
    return tiempo;
}
*/

void Pedido::leer() const {
    cout << "Descripción: " << descripcion << ", Nombre: " << nombre << ", tiempo: " << tiempo << endl;

}

bool Pedido::tipoCliente() {
    if(tipo_cliente == "REG"){
        return true;
    }
    else{
        return false;
    }
}

bool Pedido::datoErroneo() {
    if (descripcion == "" || nombre == "" || direccion == "" || tipo_cliente == "" ||num_tarjeta == NULL || tiempo == NULL){
        cout << "Hay algún dato erroneo" << endl;
        return true;
    }
}

int Pedido::getTiempo() {
    return tiempo;
}