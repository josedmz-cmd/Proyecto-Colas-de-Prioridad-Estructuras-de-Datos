#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

class Tiquete {
private:
    string codigo;
    string codigoArea;
    static int consecutivo;
    time_t horaSolicitado;
    time_t horaAtendido;
    int prioridadFinal;
    int prioridadUsuario;
    int prioridadServicio;

public:
    Tiquete(string codigoArea, int prioridadUsuario, int prioridadServicio, time_t horaSolicitado) {
        this->codigoArea = codigoArea;
        this->prioridadUsuario = prioridadUsuario;
        this->prioridadServicio = prioridadServicio;
        this->horaSolicitado = horaSolicitado;
        this->horaAtendido = 0;
        consecutivo++;
        this->codigo = codigoArea + "-" + std::to_string(consecutivo);
        this->prioridadFinal = prioridadUsuario + prioridadServicio;
    }

    ~Tiquete() {}

    string getCodigo() {
        return codigo;
    }

    string getCodigoArea() {
        return codigoArea;
    }

    int getPrioridadFinal() {
        return prioridadFinal;
    }

    int getPrioridadUsuario() {
        return prioridadUsuario;
    }

    int getPrioridadServicio() {
        return prioridadServicio;
    }

    time_t getHoraSolicitado() {
        return horaSolicitado;
    }

    time_t getHoraAtendido() {
        return horaAtendido;
    }

    void atender() {
        horaAtendido = time(nullptr);
    }

    double getTiempoEspera() {
        if (horaAtendido == 0)
            return difftime(time(nullptr), horaSolicitado);
        return difftime(horaAtendido, horaSolicitado);
    }

    void print() {
        cout << "Tiquete: " << codigo << endl;
        cout << "Area: " << codigoArea << endl;
        cout << "Prioridad final: " << prioridadFinal << endl;
        cout << "Hora solicitado: " << ctime(&horaSolicitado);        
        if (horaAtendido != 0)
            cout << "Hora atendido: " << ctime(&horaAtendido);
        cout << "------------------------" << endl;
    }
};

int Tiquete::consecutivo = 0;
