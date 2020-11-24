// Programa principal en el que se selecciona la opción

#include <iostream>
#include <fstream>
#include <string>
#include "Pedido.h"
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "gestor.h"

using namespace std;



int main() {

/*
    ifstream fe;
    string texto;
    fe.open("pedidos.txt");

    if (fe.fail()){
        cout << "El archivo falla" << endl;
    }
    while (!fe.eof() && fe.good()){
        fe >> texto;
        cout << texto << endl;

    }

    fe.close();

    */

/*
    string dato, str;
    int t;

    int posicion, cuantos= 0;
    while(!fe.eof()){
        getline(fe, str);
        if (!str.empty()){
            for(int i =1; i < 6; i++){
                posicion = str.find("//");
                dato = str.substr(0, posicion);

                switch (i) {
                    case 1: cout << "Descripción: " << dato << endl;
                        break;
                    case 2:
                        cout << "Nombre: "<< dato << endl;
                        break;
                    case 3:
                        cout << "Dirección: "<< dato << endl;
                        break;
                    case 4:
                        cout << "Tipo de Cliente: "<< dato << endl;
                        break;
                    case 5:
                        cout << "Número de tarjeta: "<< dato << endl;
                        break;
                    case 6:
                        cout << "Tiempo: " << endl;
                        break;
                    default:
                        break;
                }
                str.erase(0, posicion+2);
            }
            dato = str.substr(0,1);
            t=atoi(dato.c_str());
            cout << "Tiempo: " << t << endl;
        }
        fe.close();
    }
*/

    //Creación Colas, Pilas y Listas necesarias
    Cola colaRegistrados;
    Cola colaNoRegistrados;
    Pila pilaErroneos;
    Lista ListaPedidos;


    //Creación Pedidos
    Pedido ped1("Ordenador", "Juan Luis", "Calle Luna 7", "REG", 492059205032, 5);
    Pedido ped2("Maquina", "Jose Alberto", "Calle Perez 7", "NOREG", 492059205020, 10);
    Pedido ped3("Mac", "Junior", "Calle Alberto Alcocer 32", "REG", 59204020402, 3);
    Pedido ped4("Intel", "Cristina", "Plaza Castilla", "", 5020520402, 2);

    //Clasifico e introduzco los pedidos en sus correspondientes colas
    colaRegistrados.clasificar(&ped1, colaRegistrados, colaNoRegistrados);
    colaRegistrados.clasificar(&ped2, colaRegistrados, colaNoRegistrados);
    colaRegistrados.clasificar(&ped3, colaRegistrados, colaNoRegistrados);



    pilaErroneos.dePilaACola(colaRegistrados);     //Pasamos de cola a pila

    ListaPedidos.insertarLista(&ped1); // Prueba Lista


    //Menú
    gestor gestorPrograma;


    int opcion;
    bool bucle = true;      // Si el bucle es "false" se para de repetir el menú
    while (bucle != false) {

        cout << "1. Generar pedidos" << endl;
        cout << "2. Gestión de pedidos" << endl;
        cout << "3. Salir del sistema" << endl;

        cout << endl;

        cout << "Indique la opción deseada: " << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                //Parte de leer el fichero
                /*char cadena[8];
                ifstream fichero("Users/juniorchunga/Desktop/FicheroC++.txt");

                while (!fichero.eof()) {
                    fichero >> cadena;
                    cout << cadena << endl;
                }
                fichero.close();

                bucle = true;
                 */
                cout << "Creando pedidos..." << endl;
                gestorPrograma.inicio();
                break;
            case 2:
                cout << "Metiendo los pedidos en la cola..." << endl;
                gestorPrograma.encolar();
                cout << endl;
                cout << "Pasando los pedidos de la cola de espera a realización..." << endl;
                gestorPrograma.clasificar();
                bucle = true;
                break;
            case 3:
                bucle = false;
                cout << "Saliendo del sistema..." <<endl;
                cout << endl;
                cout << endl;
                cout << "Cerrando sesión" << endl;
                cout << endl;
                cout << endl;
                cout << "Off" << endl;
                break;
            default:
                cout << "Esta opción no está disponible" << endl;
        }
    }
    */
    return 0;

}