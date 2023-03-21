//
// Created by Manuel on 3/19/2023.
//

#include "Nodo.h"

Nodo::Nodo(int habitacion, string nombre) {
    this->habitacion = habitacion;
    this->nombre = nombre;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}
Nodo::Nodo(int habitacion, string nombre, Nodo* siguiente, Nodo* anterior) {
    this->habitacion = habitacion; // this-> es para referirse a la variable de la clase
    this->nombre = nombre;
    this->siguiente = siguiente; // puntero siguiente
    this->anterior = anterior; // puntero anterior
}
int Nodo::gethabitacion() { // get es para obtener el valor de la variable en este caso la habitacion
    return habitacion;
}
void Nodo::sethabitacion(int habitacion) { // set es para asignarle un valor a la variable en este caso la habitacion
    this->habitacion = habitacion;
}
Nodo* Nodo::getSiguiente() { // get es para obtener el valor de la variable en este caso el puntero siguiente
    return siguiente;
}
void Nodo::setSiguiente(Nodo* siguiente) { // set es para asignarle un valor a la variable en este caso el puntero siguiente
    this->siguiente = siguiente;
}
Nodo* Nodo::getAnterior() {
    return anterior;
}
void Nodo::setAnterior(Nodo* anterior) {
    this->anterior = anterior;
}

