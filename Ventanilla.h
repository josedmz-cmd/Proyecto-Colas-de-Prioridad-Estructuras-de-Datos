/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga
  
    CLASE VENTANILLA
    
    La clase Ventanilla representa un punto de atención dentro de un sistema
    de gestión de tiquetes.

    Su función principal es atender tiquetes, controlar si la ventanilla se
    encuentra ocupada o libre y llevar un registro de la cantidad total de
    usuarios atendidos.

    Cada objeto de tipo Ventanilla almacena información relacionada con:
    - Nombre de la ventanilla.
    - Estado actual (ocupada o libre).
    - Tiquete que está siendo atendido.
    - Cantidad total de tiquetes atendidos.

    FUNCIONAMIENTO
    
    1. CREACIÓN DE LA VENTANILLA
       - Al crear una ventanilla se inicializa:
            * El nombre.
            * El estado como libre.
            * Sin tiquete asignado.
            * El contador de atendidos en 0.

    2. ATENCIÓN DE TIQUETES
       - El método atenderTiquete(Tiquete* t):
            * Verifica si la ventanilla está ocupada.
                - Si está libre:
                    -> Asigna el tiquete recibido.
                    -> Cambia el estado a ocupada.
                    -> Incrementa el total de atendidos.
                    -> Marca el tiquete como atendido.
                - Si la ventanilla ya está ocupada:
                    -> Muestra un mensaje indicando que no puede atender otro tiquete.

    3. LIBERACIÓN DE LA VENTANILLA
       - El método liberar():
            * Elimina el tiquete actual.
            * Cambia el estado a libre.

    4. CONSULTAS DE INFORMACIÓN
       - Se pueden consultar:
            * El nombre de la ventanilla.
            * El estado actual.
            * El tiquete asignado.
            * La cantidad de tiquetes atendidos.

    5. VISUALIZACIÓN
       - El método print() imprime toda la información de la ventanilla.
       - El operador << permite mostrar el objeto directamente usando cout.

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    atenderTiquete(Tiquete* t)
        -> No devuelve nada (void).
        -> Asigna y atiende un tiquete si la ventanilla está libre.

    liberar()
        -> No devuelve nada (void).
        -> Libera la ventanilla y elimina el tiquete actual.

    estaOcupada()
        -> Devuelve un bool.
        -> Retorna true si la ventanilla está ocupada y false si está libre.

    getNombre()
        -> Devuelve un string.
        -> Retorna el nombre de la ventanilla.

    getTiqueteActual()
        -> Devuelve un Tiquete*.
        -> Retorna un puntero al tiquete actualmente asignado.

    getTotalAtendidos()
        -> Devuelve un int.
        -> Retorna la cantidad total de tiquetes atendidos.

    print()
        -> No devuelve nada (void).
        -> Imprime toda la información de la ventanilla.

    operator<<
        -> Devuelve un ostream&.
        -> Permite imprimir el objeto usando cout.
*/

#pragma once
#include <iostream>
#include <string>
#include "Tiquete.h"

using std::string;
using std::cout;
using std::endl;

class Ventanilla {
private:
    string nombre;
    bool ocupada;
    Tiquete* tiqueteActual;
    int totalAtendidos;

public:
    Ventanilla() {
        nombre = "";
        ocupada = false;
        tiqueteActual = nullptr;
        totalAtendidos = 0;
    }

    Ventanilla(string nombre) {
        this->nombre = nombre;
        ocupada = false;
        tiqueteActual = nullptr;
        totalAtendidos = 0;
    }

    ~Ventanilla() {}

    void atenderTiquete(Tiquete* t) {
        if (ocupada) {
            cout << "La ventanilla " << nombre << " está ocupada." << endl;
            return;
        }
        tiqueteActual = t;
        ocupada = true;
        totalAtendidos++;
        if (tiqueteActual != nullptr) {
            tiqueteActual->atender();
        }
    }

    void liberar() {
        if (tiqueteActual != nullptr) {
            delete tiqueteActual;
            tiqueteActual = nullptr;
        }
        ocupada = false;
    }

    bool estaOcupada() const {
        return ocupada;
    }

    string getNombre() const {
        return nombre;
    }

    Tiquete* getTiqueteActual() const {
        return tiqueteActual;
    }

    int getTotalAtendidos() const {
        return totalAtendidos;
    }

    void print() const {
        cout << "VENTANILLA: " << nombre << endl;
        cout << "ESTADO: " << (ocupada ? "OCUPADA" : "LIBRE") << endl;
        cout << "TOTAL ATENDIDOS: " << totalAtendidos << endl;
        if (ocupada && tiqueteActual != nullptr) {
            cout << "TIQUETE ACTUAL:" << endl;
            tiqueteActual->print();
        }
        else {
            cout << "SIN TIQUETE ASIGNADO" << endl;
        }
        cout << "------------------------" << endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ventanilla& v) {
        os << "(Ventanilla: " << v.nombre
            << ", Estado: " << (v.ocupada ? "Ocupada" : "Libre")
            << ", Atendidos: " << v.totalAtendidos;
        if (v.ocupada && v.tiqueteActual != nullptr) {
            os << ", Tiquete: " << v.tiqueteActual->getCodigo();
        }
        else {
            os << ", Tiquete: Ninguno";
        }
        os << ")";
        return os;
    }
};
