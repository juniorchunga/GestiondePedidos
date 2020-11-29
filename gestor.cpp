//
// Created by Junior Chunga on 23/11/20.
//

#include "gestor.h"

gestor::gestor() {}

Pedido pedido1("Ordenador", "Calle Luna", "Junior", "REG", 4010402104, 4);
Pedido pedido2("Teclado", "Calle Barcelona", "Francisco", "NOREG", 552040205020, 9);
Pedido pedido3("Ordenador Dell", "Calle Preciados", "Alberto", "REG", 30502050250, 5);
Pedido pedido4("Monitor", "Calle Alcala", "Adriana", "NOREG", 402492045020, 8);
Pedido pedido5("Iphone 12", "Paseo de la Dirección", "Roberto", "NOREG", 50205020402, 6);
Pedido pedido6("Ipad", "Calle Recoletos 5", "Pedro Sanchez", "NOREG", 6038295020502, 7);
Pedido pedido7("Apple Watch Series 6", "Calle Nuestra Sr. Fátima", "Maria del Carmen", "REG", 502950205204502, 3);
Pedido pedido8("Televisión Smart TV LG", "Plaza de Castilla", "Mia", "NOREG", 23104929059203, 9);
Pedido pedido9("Macbook Pro 13'", "Calle Atocha 25", "Antonio Machado", "REG", 582949820450204, 4);
Pedido pedido10("Portatil Gaming MSI", "Ronda de Barcelona", "Cristina", "REG", 4920959205903, 3);
Pedido pedido11("Nintendo DS", "Paseo de la Dirección 11", "Olga", "NOREG", 402945020402, 7);
Pedido pedido12("PlayStation 5", "Calle Princesa 11", "Teresa", "REG", 492945029592, 2);
Pedido pedido13("Fifa 21", "Calle Lopez de Hoyos", "Pilar", "REG", 40289402048929, 4);
Pedido pedido14("Televisión Smart TV Samsung 4K", "Paseo de la Castellana 300", "Fernando", "REG", 10491049204020, 5);
Pedido pedido15("Reloj Despertador Thomson", "Calle Sancho Davila", "Jaime", "REG",40285920402103, 4);
Pedido pedido16("Monitor Xiaomi 27'", "Calle de Juan del Risco", "Pedro", "NOREG", 1049204022902, 6);
Pedido pedido17("HomePod Apple", "Calle de Palencia", "Rosa", "NOREG", 391049205920502, 6);
Pedido pedido18("Auricolares Inalambricos BOSE","Calle Raimundo Fernandez Villaverde", "Emilio","NOREG", 4929920450294020, 9);
Pedido pedido19("Altavoces BOSE", "Calle de Aravaca", "Luis", "NOREG", 45204592589294, 10);
Pedido pedido20("Repuesto pastilla térmica", "Av. Reyes Católicos", "Andrea", "REG", 492092040294, 4);
Pedido pedido21("Procesador Intel i7 10450U", "Calle de Santa Cruz de Marcenado", "Elena", "REG", 3019492040204, 1);


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
    pedido11.leer();
    pedido12.leer();
    pedido13.leer();
    pedido14.leer();
    pedido15.leer();
    pedido16.leer();
    pedido17.leer();
    pedido18.leer();
    pedido19.leer();
    pedido20.leer();
    pedido21.leer();
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
    tipo_cliente(&pedido6);
    tipo_cliente(&pedido7);
    tipo_cliente(&pedido8);
    tipo_cliente(&pedido9);
    tipo_cliente(&pedido10);
    tipo_cliente(&pedido11);
    tipo_cliente(&pedido12);
    tipo_cliente(&pedido13);
    tipo_cliente(&pedido14);
    tipo_cliente(&pedido15);
    tipo_cliente(&pedido16);
    tipo_cliente(&pedido17);
    tipo_cliente(&pedido18);
    tipo_cliente(&pedido19);
    tipo_cliente(&pedido20);
    tipo_cliente(&pedido21);
    cout << endl;

}

void gestor::clasificar() {
    Pedido* valor;
    int contador_registrados = 0;
    int contador_no_registrados = 0;
    //Cuando la cola no esté vacia
    while (!cola_reg.esVacia()) {
        valor = cola_reg.desencolar();
        if (valor->datoErroneo()) {
            pilaRegistrados.apilar(valor);
        } else listaRegistrados.insertarLista(valor);
        //contador_registrados += 1;
    }

    //Cuando la cola de registrados ya esté vacia y la de no registrados no
    while (!cola_Noreg.esVacia()) {
        valor = cola_Noreg.desencolar();
        if (valor->datoErroneo()) {
            pilaNoRegistrados.apilar(valor);
        } else listaNoRegistrados.insertarLista(valor);
        //contador_no_registrados += 1;
    }
    cout << endl;

    //Llamamos a la función apilar para que guarde en la pila final, con el orden de los registrados arriba y los no abajo
    apilar();


    //Llamamos a la función alistar para que ordene y cree la lista final
    alistar();

}

void gestor::apilar(){
    pilaErroneos = pilaNoRegistrados;
    pilaNoRegistrados.apilar(pilaRegistrados.desapilar());
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

    if(listaPedidos.vacia()) {
    } else {
        while(!listaPedidos.vacia()) {
            listaPedidos.quitarLista();
            if (listaPedidos.vacia()) cout << "Todos los aficionados han sido borrados de las colas\n" << endl;
        }
    }
}


void gestor::mostrarCola() {
    Cola aux = cola_reg;
    Cola aux2 = cola_Noreg;
    Pedido* pedido;
    if (aux.esVacia() && aux2.esVacia()) {
        cout << "No hay pedidos en espera\n";
    } else {
        cout << "Clientes Registrados\n";
        while (!aux.esVacia()) {
            pedido = aux.desencolar();
            pedido->leer();
        }
        cout << endl;
        cout << "Clientes No Registrados\n";
        while (!aux2.esVacia()){
            pedido = aux2.desencolar();
            pedido->leer();
        }
    }
    cout << endl;

}

void gestor::mostrarPila() {
    Pila aux = pilaErroneos;
    Pedido *pedido;
    if (aux.vacia()) {
        cout << "No hay pedidos erroneos\n";
    } else {
        while (!aux.vacia()) {
            pedido = aux.desapilar();
            pedido->leer();
        }
    }
}

void gestor::mostrarLista() {
    if (listaPedidos.vacia()){
        cout << "No hay pedidos en la lista\n" << endl;
    }
    cout << "Pedidos: \n";
    listaPedidos.mostrarLista();
}


gestor::~gestor() {}