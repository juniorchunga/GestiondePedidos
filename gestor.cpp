//
// Created by Junior Chunga on 23/11/20.
//

#include "gestor.h"

gestor::gestor() {}

Pedido* gestor::inicio() {
    this-> contador = 0;
    //Se supone en leer un fichero, por ahora solo crear pedidos
    Pedido pedido1("Ordenador", "Calle Luna", "Junior","REG",4010402104 , 4);
    Pedido pedido2("Teclado", "Calle Barcelona", "Francisco", "NOREG", 552040205020, 9);
    Pedido pedido3("Ordenador Dell", "Calle Preciados", "Alberto", "REG", 30502050250, 5);
    Pedido pedido4("Monitor", "Calle Alcala", "Adriana", "NOREG", 402492045020,8);
    Pedido pedido5("Iphone 12", "Calle Bravo Murillo", "Roberto", "NOREG", 50205020402, 6);


    return &pedido1;
}


void gestor::encolar() {
    //Meter en la cola
    Pedido* pedido;
    if (pedido->tipoCliente()){
        cola_reg.encolar(pedido);
    } else cola_Noreg.encolar(pedido);

}

void gestor::clasificar() {
    Pedido* valor;
    int contador_registrados = 0;
    int contador_no_registrados = 0;
    //Cuando la cola no esté vacia
    while(!cola_reg.esVacia() && contador_registrados !=4) {
        valor = cola_reg.desencolar();
        if (valor->datoErroneo()) {
            pilaErroneos.apilar(valor);
        } else listaPedidos.insertarLista(valor);
        contador_registrados +=1;
    }

    //Cuando la cola de registrados ya esté vacia y la de no registrados no
    while (!cola_Noreg.esVacia() && cola_reg.esVacia() && contador_no_registrados !=1) {
        valor = cola_Noreg.desencolar();
        if (valor->datoErroneo()) {
            pilaErroneos.apilar(valor);
        } else listaPedidos.insertarLista(valor);
        contador_no_registrados +=1;
    }

}



gestor::~gestor() {}