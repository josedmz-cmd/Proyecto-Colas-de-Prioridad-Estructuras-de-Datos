#pragma once
#include <iostream>
#include <string>
#include "Heap_Priority_Queue.h"
#include "Tiquete.h"
#include "Ventanilla.h"

using std::string;
using std::cout;
using std::endl;

class Area {
private:
    string nombre;
    int ventanillasCount;
    string descripcion;
    string codigo;

    Heap_Priority_Queue<Tiquete>* cola;
    Ventanilla* ventanillas;

public:
    Area(string nombre, string codigo, string descripcion, int ventanillasCount) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->descripcion = descripcion;
        this->ventanillasCount = ventanillasCount;
        cola = new Heap_Priority_Queue<Tiquete>();
        ventanillas = new Ventanilla[ventanillasCount];
        for (int i = 0; i < ventanillasCount; i++) {
            ventanillas[i] = Ventanilla("V" + std::to_string(i + 1));
        }
    }

    ~Area() {
        delete cola;
        delete[] ventanillas;
    }

    void agregarTiquete(Tiquete t) {
        cola->insert(t, t.getPrioridadFinal());
    }

    void atenderSiguiente() {
        if (cola->is_empty()) {
            cout << "No hay tiquetes en cola." << endl;
            return;
        }

        for (int i = 0; i < ventanillasCount; i++) {
            if (!ventanillas[i].estaOcupada()) {
                Tiquete t = cola->removeMin();
                Tiquete* nuevo = new Tiquete(t);
                ventanillas[i].atenderTiquete(nuevo);
                cout << "Asignado " << t.getCodigo()
                    << " a " << ventanillas[i].getNombre() << endl;
                return;
            }
        }

        cout << "No hay ventanillas disponibles." << endl;
    }

    void liberarVentanilla(int index) {
        if (index < 0 || index >= ventanillasCount) {
            cout << "Indice invalido." << endl;
            return;
        }

        ventanillas[index].liberar();
    }

    void print() {
        cout << "AREA: " << nombre << " (" << codigo << ")" << endl;
        cout << "Descripcion: " << descripcion << endl;

        cout << "Tiquetes en cola: " << cola->getSize() << endl;

        cout << "\n--- Ventanillas ---" << endl;
        for (int i = 0; i < ventanillasCount; i++) {
            ventanillas[i].print();
        }

        cout << "========================\n" << endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Area& a) {
        os << "(Area: " << a.nombre
            << ", Codigo: " << a.codigo
            << ", En cola: " << a.cola->getSize() << ")";
        return os;
    }
};
