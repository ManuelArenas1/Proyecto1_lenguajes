//
// Created by Manuel on 3/19/2023.
//

#ifndef UNTITLED1_NODO_H
#define UNTITLED1_NODO_H
#include <string>
using namespace std;
class Nodo {
protected:
    int habitacion;
    string nombre;
    Nodo *siguiente; //puntero siguiente
    Nodo *anterior; //puntero anterior
public:
    Nodo(int habitacion, string nombre);

    Nodo(int habitacion, string nombre, Nodo *siguiente, Nodo *anterior);

    int gethabitacion();

    void sethabitacion(int habitacion);

    Nodo *getSiguiente();

    void setSiguiente(Nodo *siguiente);

    Nodo *getAnterior();

    void setAnterior(Nodo *anterior);


};


#endif //UNTITLED1_NODO_H
