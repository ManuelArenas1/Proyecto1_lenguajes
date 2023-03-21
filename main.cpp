#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Invitado {
    string nombre;
    int habitacion{};
    Invitado* previo{};
    Invitado* siguiente{};
};
Invitado* cabeza = nullptr;
Invitado* cola = nullptr;

void cargarInvitadoDeArchivo(const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error al abrir el archivo \"" << fileName << "\"" << endl;
        return;
    }
    string nombre;
    int habitacion;
    while (inFile >> nombre >> habitacion) {
        auto* invitado = new Invitado();
        invitado->nombre = nombre;
        invitado->habitacion = habitacion;
        invitado->previo = cola;
        invitado->siguiente = nullptr;
        if (cola == nullptr) {
            cabeza = cola = invitado;
        } else {
            cola->siguiente = invitado;
            cola = invitado;
        }
    }
    inFile.close();
}

void guardarInvEnLista(const string& fileName) {
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Error al hacer el archivo \"" << fileName << "\"" << endl;
        return;
    }
    for (Invitado* invitado = cabeza; invitado != nullptr; invitado = invitado->siguiente) {
        outFile << invitado->nombre << " " << invitado->habitacion << endl;
    }
    outFile.close();
}

void insertarInv() {
    string nombre;
    int habitacion;
    cout << "Ingrese el nombre del invitado: ";
    cin >> nombre;
    cout << "Ingrese el numero de habitacion deseada: ";
    cin >> habitacion;
    auto* invitado = new Invitado();
    invitado->nombre = nombre;
    invitado->habitacion = habitacion;
    invitado->previo = cola;
    invitado->siguiente = nullptr;
    if (cola == nullptr) {
        cabeza = cola = invitado;
    } else {
        cola->siguiente = invitado;
        cola = invitado;
    }
    guardarInvEnLista("hotel.txt");
    cout << "Invitado añadido." << endl;
}

Invitado* BuscarInvitadoNombre(const string& nombre) {
    for (Invitado* invitado = cabeza; invitado != nullptr; invitado = invitado->siguiente) {
        if (invitado->nombre == nombre) {
            return invitado;
        }
    }
    return nullptr;
}

Invitado* BuscarInvHabitacion(int habitacion) {
    for (Invitado* invitado = cabeza; invitado != nullptr; invitado = invitado->siguiente) {
        if (invitado->habitacion == habitacion) {
            return invitado;
        }
    }
    return nullptr;
}

void buscarInv() {
    cout << "Ingresa el nombre o el numero de habitacion: ";
    string input;
    cin >> input;
    Invitado* invitado;
    if (isdigit(input[0])) {
        int habitacion = stoi(input);
        invitado = BuscarInvHabitacion(habitacion);
    } else {
        invitado = BuscarInvitadoNombre(input);
    }
    if (invitado == nullptr) {
        cout << "Invitado no encontrado." << endl;
    } else {
        cout << "Invitado encontrado: " << invitado->nombre << ", habitacion: " << invitado->habitacion << endl;
    }
}

void ordenDeHabitacion() {
    vector<Invitado*> invitados;
    for (Invitado *invitado = cabeza; invitado != nullptr; invitado = invitado->siguiente)
        invitados.push_back(invitado);

    sort(invitados.begin(), invitados.end(),[](Invitado* a,Invitado* b){return a->nombre <b->nombre;});

    cout << "Lista ordenada de habitacion mayor a menor:" << endl;
    for (Invitado* invitado : invitados) {
        cout << invitado->nombre << " habitacion: " << invitado->habitacion << endl;
    }
}
void vecinos(){
    int h;
    int g;
    int i;
    cout<<"Ingrese el numero de habitacion: "<< endl;
    cin>>h;
    g=h-1;
    i=h+1;
    Invitado* actual = cola;
    while(actual != NULL){
        if(actual->habitacion == g){
            cout<<"El vecino de la habitacion "<<h<<" es: "<<actual->nombre<<endl;
        }else if(actual->habitacion == i){
            cout<<"El vecino de la habitacion "<<h<<" es: "<<actual->nombre<<endl;
        }
    }
    actual = actual->siguiente;
}

#include <iostream>

using namespace std;

void cargarInvitadoDeArchivo(const string& fileName);
void guardarInvEnLista(const string& fileName);
void insertarInv();
void buscarInv();
void ordenDeHabitacion();
void vecinos();

int main() {
    string fileName = "hotel.txt";
    int valor;

    do {
        cout << "-----------------------------" << endl;
        cout << "1. Cargar invitados de la lista" << endl;
        cout << "2. Guardar los invitados en la lista" << endl;
        cout << "3. Crear nuevo invitado" << endl;
        cout << "4. Buscar un invitado" << endl;
        cout << "5. Imprimir invitados en orden de habitacion" << endl;
        cout << "6. Imprimir vecinos de una habitacion" << endl;
        cout << "7. Cerrar" << endl;
        cout << "-----------------------------" << endl;
        cout << "Ingrese el valor de la opcion que desee hacer (1-7): ";
        cin >> valor;
        cout << endl;

        switch (valor) {
            case 1:
                cargarInvitadoDeArchivo(fileName);
                break;
            case 2:
                guardarInvEnLista(fileName);
                break;
            case 3:
                insertarInv();
                break;
            case 4:
                buscarInv();
                break;
            case 5:
                ordenDeHabitacion();
                break;
            case 6:
                vecinos();
                break;
            case 7:
                cout << "Cerrando el programa" << endl;
                break;
            default:
                cout << "Numero invalido. Por favor escoger un numero del 1 al 7" << endl;
                break;
        }

        cout << endl;

    } while (valor != 7);

    return 0;
}