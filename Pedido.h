//
// Created by Junior Chunga on 07/11/2020.
//

#ifndef PRACTICA1_PEDIDO_H
#define PRACTICA1_PEDIDO_H
#include <string>
using namespace std;

class Pedido {
public:
    Pedido(string descripcion, string nombre, string direccion, string tipo_cliente, long num_tarjeta, int tiempo);

    bool tipoCliente();
    void leer() const;
    bool datoErroneo();


private:
    string descripcion;
    string nombre;
    string direccion;
    string tipo_cliente;
    long num_tarjeta;
    int tiempo;

};




#endif //PRACTICA1_PEDIDO_H
