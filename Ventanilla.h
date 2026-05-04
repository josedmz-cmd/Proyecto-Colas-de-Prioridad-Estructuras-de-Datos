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

public:
    Ventanilla() {
        nombre = "";
        ocupada = false;
        tiqueteActual = nullptr;
    }

    Ventanilla(string nombre) {
        this->nombre = nombre;
        ocupada = false;
        tiqueteActual = nullptr;
    }

    ~Ventanilla() {}

    void atenderTiquete(Tiquete* t) {
        if (ocupada) {
            cout << "La ventanilla " << nombre << " está ocupada." << endl;
            return;
        }
        tiqueteActual = t;
        ocupada = true;
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

    void print() const {
        cout << "VENTANILLA: " << nombre << endl;
        cout << "ESTADO: " << (ocupada ? "OCUPADA" : "LIBRE") << endl;
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
            << ", Estado: " << (v.ocupada ? "Ocupada" : "Libre");
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
