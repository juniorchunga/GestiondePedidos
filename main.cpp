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


    //Menú
    gestor gestorPrograma;


    int opcion;
    bool bucle = true;      // Si el bucle es "false" se para de repetir el menú
    while (bucle != false) {

        cout << "1. Generar pedidos" << endl;
        cout << "2. Gestión de pedidos" << endl;
        cout << "3. Mostrar pedidos" << endl;
        cout << "4. Clasificar pedidos" << endl;
        cout << "5. Mostrar pedidos erroneos" << endl;
        cout << "6. Mostrar lista pedidos" << endl;
        cout << "7. Reiniciar programa" << endl;
        cout << "8. Salir del sistema" << endl;

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

                //Se supone que se lee los pedidos del fichero
                cout << "Creando pedidos...\n" << endl;
                gestorPrograma.conteo();
                break;
            case 2:
                //Los pedidos se meten a la cola, dependiendo del cliente
                cout << "Metiendo los pedidos en la cola...\n" << endl;
                gestorPrograma.encolar();
                cout << endl;
                bucle = true;
                break;
            case 3:
                // Muestra los pedidos de la cola
                cout << "Mostrando pedidos en espera...\n" << endl;
                gestorPrograma.mostrarCola();
                bucle = true;
                break;
            case 4:
                // Clasifica los pedidos de las colas a la lista o pila
                cout << "Clasificando...\n" << endl;
                gestorPrograma.clasificar();
                bucle = true;
                break;
            case 5:
                //Muestra los pedidos erroneos
                cout << "Mostrando pedidos erroneos...\n" << endl;
                gestorPrograma.mostrarPila();
                bucle = true;
                break;
            case 6:
                //Reinicia el programa
                cout << "Mostrando pedidos...\n" << endl;
                gestorPrograma.mostrarLista();
                bucle = true;
                break;
            case 7:
                //Reinicia el programa
                cout << "Reiniciando...\n" << endl;
                gestorPrograma.reiniciar();
                bucle = true;
                break;
            case 8:
                //Salida del programa
                cout << "Saliendo del sistema...\n" << endl;
                cout << endl;

                cout << "Cerrando sesión\n" << endl;
                cout << endl;

                cout << "Off" << endl;
                bucle = false;
                break;
            default:
                cout << "Esta opción no está disponible\n" << endl;
        }
    }
    return 0;
}
