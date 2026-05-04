// Proyecto-Colas-de-Prioridad-Estructuras-de-Datos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Heap_Priority_Queue.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;


void estadoColas() {
    ;
    ;
    ;
}

void MenuTiquete() { //Print del menu
    cout << "1. Agregar Tiquete" << endl;
    cout << "2. Regresar" << endl;
}

void MenuUsuario() { //Print del menu
    cout << "1. Agregar" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Regresar" << endl;
}

void MenuAreas() { //Print del menu
    cout << "1. Agregar" << endl;
    cout << "2. Modificar Ventanillas" << endl;
    cout << "3. Eliminar" << endl;
    cout << "4. Regresar" << endl;
}

void MenuServicio() { //Print del menu
    cout << "1. Agregar" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Reorganizar" << endl;
    cout << "4. Regresar" << endl;
}

void MenuAdministracion() { //Print del menu
    cout << "1. Tipo de usuario" << endl;
    cout << "2. Areas" << endl;
    cout << "3. Servicios" << endl;
    cout << "4. Limpiar colas y estadisticas" << endl;
    cout << "5. Regresar" << endl;
}

void Menu() { //Print del menu
    cout << "1. Tiquete" << endl;
    cout << "2. Atender Tiquete" << endl;
    cout << "3. Administracion" << endl;
    cout << "4. Estadisticas" << endl;
    cout << "5. Salir" << endl;
}

string leer_String(const string& mensaje) { //Leer el imput del usuario
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

int main() {
    Heap_Priority_Queue<Patient> colaPacientes(5);
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
