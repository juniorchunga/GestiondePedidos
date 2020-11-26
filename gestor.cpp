//
// Created by Junior Chunga on 23/11/20.
//

#include "gestor.h"

gestor::gestor() {}

Pedido pedido1("Ordenador", "Calle Luna", "Junior", "REG", 4010402104, 4);
Pedido pedido2("Teclado", "Calle Barcelona", "Francisco", "NOREG", 552040205020, 9);
Pedido pedido3("Ordenador Dell", "Calle Preciados", "Alberto", "REG", 30502050250, 5);
Pedido pedido4("Monitor", "Calle Alcala", "Adriana", "NOREG", 402492045020, 8);
Pedido pedido5("Iphone 12", "Calle Bravo Murillo", "Roberto", "NOREG", 50205020402, 6);
Pedido pedido6("Ipad", "Calle Recoletos 5", "Pedro Sanchez", "NOREG", 6038295020502, 7);
Pedido pedido7("Apple Watch Series 6", "Calle Nuestra Sr. Fátima", "Maria del Carmen", "REG", 502950205204502, 3);
Pedido pedido8("Televisión Smart TV LG", "Plaza de Castilla", "Mia", "NOREG", 23104929059203, 9);
Pedido pedido9("Macbook Pro 13'", "Calle Atocha 25", "Antonio Machado", "REG", 582949820450204, 4);
Pedido pedido10("Portatil Gaming MSI", "Ronda de Barcelona", "Cristina", "REG", 4920959205903, 3);


int gestor::conteo() {
    this->contador = 0;
    pedido1.leer();
    pedido2.leer();
    pedido3.leer();
    pedido4.leer();
    pedido5.leer();
    pedido6.leer();
    pedido7.leer();
    pedido8.leer();
    pedido9.leer();
    pedido10.leer();
    cout << endl;
    return contador;
}


void gestor::encolar() {

    //Meter en la cola
    tipo_cliente(&pedido1);
    tipo_cliente(&pedido2);
    tipo_cliente(&pedido3);
    tipo_cliente(&pedido4);
    tipo_cliente(&pedido5);

}

void gestor::clasificar() {
    Pedido* valor;
    int contador_registrados = 0;
    int contador_no_registrados = 0;
    //Cuando la cola no esté vacia
    while (!cola_reg.esVacia()) {
        valor = cola_reg.desencolar();
        if (valor->datoErroneo()) {
            pilaErroneos.apilar(valor);
        } else listaRegistrados.insertarLista(valor);
        //contador_registrados += 1;
    }

    //Cuando la cola de registrados ya esté vacia y la de no registrados no
    while (!cola_Noreg.esVacia() && cola_reg.esVacia()) {
        valor = cola_Noreg.desencolar();
        if (valor->datoErroneo()) {
            pilaErroneos.apilar(valor);
        } else listaNoRegistrados.insertarLista(valor);
        //contador_no_registrados += 1;
    }

    //Llamamos a la función alistar para que ordene y cree la lista final
    alistar();

}

void gestor::alistar() {
    //Ordenamos las listas
    listaRegistrados.ordenar();
    listaNoRegistrados.ordenar();

    //Juntamos las listas ordenadas en una sola
    listaPedidos = listaRegistrados;
    listaPedidos.juntarListas(listaNoRegistrados);

}

void gestor::tipo_cliente(Pedido *pedido) {
    if (pedido->tipoCliente()) {
        cola_reg.encolar(pedido);
    } else cola_Noreg.encolar(pedido);
}


void gestor::reiniciar() {      // Reinicia el programa
    if (pilaErroneos.vacia()) {
    } else {
        while (!pilaErroneos.vacia()) {
            pilaErroneos.desapilar();

            if (pilaErroneos.vacia()) cout << "Todos los aficionados han sido borrados de las pilas\n" << endl;
        }
    }

    if (cola_reg.esVacia()) {
    } else {
        while (!cola_reg.esVacia()) {
            cola_reg.desencolar();

            if (cola_reg.esVacia()) cout << "Todos los aficionados han sido borrados de las colas\n" << endl;
        }
    }

    if (cola_Noreg.esVacia()) {
    } else {
        while (!cola_Noreg.esVacia()) {
            cola_Noreg.desencolar();

            if (cola_Noreg.esVacia()) cout << "Todos los aficionados han sido borrados de las colas\n" << endl;
        }
    }

    /*
    if(listaPedidos.vacia()) {
    } else {
        while(!listaPedidos.vacia()) {
            listaPedidos.quitarLista();

            if (listaPedidos.vacia()) cout << "Todos los aficionados han sido borrados de las colas" << endl;
        }
    }
     */
}


void gestor::mostrarCola() {
    Cola aux = cola_reg;
    Pedido* pedido;
    if (aux.esVacia()) {
        cout << "No hay pedidos en espera\n";
    } else {
        while (!aux.esVacia()) {
            pedido = aux.desencolar();
            pedido->leer();
        }
    }

}

void gestor::mostrarPila() {
    Pila aux = pilaErroneos;
    Pedido *pedido;
    if (aux.vacia()) {
        cout << "No hay pedidos erroneos\n";
    } else {
        while (!aux.vacia()) {
            //pedido = aux.desapilar();
            pedido->leer();
        }
    }
}

void gestor::mostrarLista() {

    cout << "Pedidos: \n";
    listaPedidos.mostrarLista();
}


gestor::~gestor() {}