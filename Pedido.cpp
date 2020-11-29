//
// Created by Junior Chunga on 07/11/2020.
//

#include <cstdlib>
#include <iostream>
#include "Pedido.h"

using namespace std;


Pedido::Pedido(string descripcion, string direccion, string nombre, string tipo_cliente, long num_tarjeta, int tiempo) {
    this->descripcion = descripcion;
    this->nombre = nombre;
    this->direccion = direccion;
    this->tipo_cliente = tipo_cliente;
    this->num_tarjeta = num_tarjeta;
    this->tiempo = tiempo;
}


void Pedido::leer() {
    cout << "Pedido: " << descripcion << ", Dirección: " << direccion << ", Nombre: " << nombre
         << ", tiempo de duración: " << tiempo << endl;

}

bool Pedido::tipoCliente() {
    if (tipo_cliente == "REG") {
        return true;
    } else {
        return false;
    }
}

bool Pedido::datoErroneo() {
    if (descripcion == "" || nombre == "" || direccion == "" || tipo_cliente == "" || num_tarjeta == NULL ||
        tiempo == NULL) {
        cout << "Hay algún dato erroneo" << endl;
        return true;
    }
}

int Pedido::getTiempo() {
    return tiempo;
}