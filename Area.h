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
    int totalTiquetesAtendidos;
    int sumaTiemposEspera;

    Heap_Priority_Queue<Tiquete>* cola;
    Ventanilla* ventanillas;

public:
    Area(string nombre, string codigo, string descripcion, int ventanillasCount) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->descripcion = descripcion;
        this->ventanillasCount = ventanillasCount;
        totalTiquetesAtendidos = 0;
        sumaTiemposEspera = 0;
        cola = new Heap_Priority_Queue<Tiquete>();
        ventanillas = new Ventanilla[ventanillasCount];
        for (int i = 0; i < ventanillasCount; i++) {
            ventanillas[i] = Ventanilla(nombre + std::to_string(i + 1));
        }
    }

    ~Area() {
        delete cola;
        delete[] ventanillas;
    }

    void agregarTiquete(Tiquete t) {
        cola->insert(t, t.getPrioridadFinal());
    }

    int atenderSiguiente() {
        if (cola->is_empty()) {
            cout << "No hay tiquetes en cola." << endl;
            return -1;
        }

        for (int i = 0; i < ventanillasCount; i++) {
            if (!ventanillas[i].estaOcupada()) {
                Tiquete t = cola->removeMin();
                time_t ahora = time(nullptr);
                int tiempoEspera = (int)difftime(ahora, t.getHoraSolicitud());
                totalTiquetesAtendidos++;
                sumaTiemposEspera += tiempoEspera;
                Tiquete* nuevo = new Tiquete(t);
                ventanillas[i].atenderTiquete(nuevo);
                cout << "Asignado " << t.getCodigo()
                    << " a " << ventanillas[i].getNombre() << endl;
                return i;
            }
        }

        cout << "No hay ventanillas disponibles." << endl;
        return -1;
    }

    void liberarVentanilla(int index) {
        if (index < 0 || index >= ventanillasCount) {
            cout << "Indice invalido." << endl;
            return;
        }
        if (!ventanillas[index].estaOcupada()) {
            cout << "La ventanilla " << ventanillas[index].getNombre() << " ya esta libre." << endl;
            return;
        }
        ventanillas[index].liberar();
        cout << "Ventanilla " << ventanillas[index].getNombre() << " liberada." << endl;
    }

    string getCodigo() const {
        return codigo;
    }

    string getDescripcion() const {
        return descripcion;
    }

    string getNombre() const {
        return nombre;
    }

    int getNumVentanillas() const {
        return ventanillasCount;
    }

    Ventanilla* getVentanilla(int i) {
        if (i >= 0 && i < ventanillasCount) {
            return &ventanillas[i];
        }
        return nullptr;
    }

    double getTiempoPromedioEspera() const {
        if (totalTiquetesAtendidos == 0) {
            return 0.0;
        }
        return (double)sumaTiemposEspera / totalTiquetesAtendidos;
    }

    int getTotalTiquetesAtendidos() const {
        return totalTiquetesAtendidos;
    }

    void reiniciarEstadisticas() {
        totalTiquetesAtendidos = 0;
        sumaTiemposEspera = 0;
        while (!cola->is_empty()) {
            cola->removeMin();
        }
        for (int i = 0; i < ventanillasCount; i++) {
            if (ventanillas[i].estaOcupada()) {
                ventanillas[i].liberar();
            }
        }
    }

    void modificarVentanillas(int nuevoNum) {
        if (nuevoNum < 1) {
            cout << "El numero de ventanillas debe ser al menos 1." << endl;
            return;
        }
        if (nuevoNum == ventanillasCount) {
            cout << "El numero de ventanillas ya es " << nuevoNum << "." << endl;
            return;
        }
        Ventanilla* nuevasVentanillas = new Ventanilla[nuevoNum];
        int minCount = (nuevoNum < ventanillasCount) ? nuevoNum : ventanillasCount;
        for (int i = 0; i < minCount; i++) {
            nuevasVentanillas[i] = ventanillas[i];
        }
        for (int i = ventanillasCount; i < nuevoNum; i++) {
            nuevasVentanillas[i] = Ventanilla(codigo + std::to_string(i + 1));
        }
        delete[] ventanillas;
        ventanillas = nuevasVentanillas;
        ventanillasCount = nuevoNum;
        cout << "Ventanillas modificadas. Ahora hay " << ventanillasCount << " ventanillas." << endl;
    }

    void print() {
        cout << "AREA: " << nombre << " (" << codigo << ")" << endl;
        cout << "Descripcion: " << descripcion << endl;

        cout << "Tiquetes en cola: " << cola->getSize() << endl;
        cout << "Tiquetes atendidos (historial): " << totalTiquetesAtendidos << endl;
        cout << "Tiempo promedio espera: " << getTiempoPromedioEspera() << " segundos" << endl;

        cout << "\n--- Ventanillas ---" << endl;
        for (int i = 0; i < ventanillasCount; i++) {
            ventanillas[i].print();
        }

        cout << "========================\n" << endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Area& a) {
        os << "(Area: " << a.nombre
            << ", Codigo: " << a.codigo
            << ", En cola: " << a.cola->getSize() << ")" 
            << ", Promedio espera: " << a.getTiempoPromedioEspera() << "s)";
        return os;
    }
};