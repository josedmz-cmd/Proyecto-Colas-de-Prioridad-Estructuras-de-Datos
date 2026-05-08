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
        tiqueteActual = nullptr;
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

    string getNombre() const {
        return nombre;
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