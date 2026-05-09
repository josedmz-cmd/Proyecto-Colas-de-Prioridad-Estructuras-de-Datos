/*
    Jared Andre Hemmings Chinchilla
    José Daniel Mora Zúñiga
    CLASE AREA
    
    DESCRIPCIÓN:
    La clase Area representa una sección o departamento dentro de un sistema
    de gestión de atención de usuarios.

    Su función principal es administrar:
    - Los tiquetes en espera.
    - Las ventanillas disponibles.
    - La atención de usuarios.
    - Las estadísticas de atención.

    Cada área posee una cola de prioridad donde los tiquetes son organizados
    según su prioridad final, permitiendo atender primero los casos más
    importantes.

    FUNCIONAMIENTO

    1. CREACIÓN DEL ÁREA
       - Al crear un objeto Area se deben proporcionar:
            * Nombre del área.
            * Código identificador.
            * Descripción.
            * Cantidad de ventanillas.
       - Además:
            * Se crea automáticamente una cola de prioridad.
            * Se generan las ventanillas del área.
            * Se inicializan las estadísticas.

    2. GESTIÓN DE TIQUETES
       - Los tiquetes se almacenan en una Heap Priority Queue.
       - Cada tiquete se inserta usando su prioridad final.
       - Esto permite que:
            * Los tiquetes más prioritarios sean atendidos primero.

    3. ATENCIÓN DE TIQUETES
       - El método atenderSiguiente():
            * Busca una ventanilla libre.
            * Extrae el tiquete de mayor prioridad.
            * Calcula el tiempo de espera.
            * Actualiza estadísticas.
            * Asigna el tiquete a la ventanilla.
       - Si:
            * No hay tiquetes -> muestra mensaje.
            * No hay ventanillas libres -> muestra mensaje.

    4. MANEJO DE VENTANILLAS
       - Se pueden:
            * Liberar ventanillas.
            * Consultar ventanillas.
            * Modificar la cantidad de ventanillas.

    5. ESTADÍSTICAS
       - El área mantiene:
            * Total de tiquetes atendidos.
            * Suma total de tiempos de espera.
            * Tiempo promedio de espera.

    6. REINICIO DEL SISTEMA
       - El método reiniciarEstadisticas():
            * Limpia la cola.
            * Reinicia estadísticas.
            * Libera todas las ventanillas.

    7. VISUALIZACIÓN
       - El método print() imprime toda la información del área.
       - El operador << permite imprimir el objeto usando cout.

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    agregarTiquete(Tiquete t)
        -> No devuelve nada (void).
        -> Inserta un tiquete en la cola de prioridad.

    atenderSiguiente()
        -> Devuelve un int.
        -> Retorna el índice de la ventanilla que atendió el tiquete.
        -> Retorna -1 si no se pudo atender.

    liberarVentanilla(int index)
        -> No devuelve nada (void).
        -> Libera la ventanilla indicada.

    getCodigo()
        -> Devuelve un string.
        -> Retorna el código del área.

    getDescripcion()
        -> Devuelve un string.
        -> Retorna la descripción del área.

    getNombre()
        -> Devuelve un string.
        -> Retorna el nombre del área.

    getNumVentanillas()
        -> Devuelve un int.
        -> Retorna la cantidad de ventanillas.

    getVentanilla(int i)
        -> Devuelve un Ventanilla*.
        -> Retorna un puntero a la ventanilla indicada.

    getTiempoPromedioEspera()
        -> Devuelve un double.
        -> Retorna el promedio de espera de los usuarios.

    getTotalTiquetesAtendidos()
        -> Devuelve un int.
        -> Retorna el total de tiquetes atendidos.

    reiniciarEstadisticas()
        -> No devuelve nada (void).
        -> Reinicia estadísticas, cola y ventanillas.

    modificarVentanillas(int nuevoNum)
        -> No devuelve nada (void).
        -> Cambia la cantidad de ventanillas del área.

    print()
        -> No devuelve nada (void).
        -> Imprime toda la información del área.

    operator<<
        -> Devuelve un ostream&.
        -> Permite imprimir el objeto usando cout.
*/

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
