#pragma once
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
    int tiempoEspera;
    int prioridadFinal;
    int prioridadUsuario;
    int prioridadServicio;

public:
    Tiquete() {
        codigo = "";
        codigoArea = "";
        consecutivo++;
        horaSolicitado = time(nullptr);
        horaAtendido = 0;
        tiempoEspera = 0;
        prioridadUsuario = 0;
        prioridadServicio = 0;
        prioridadFinal = 0;
    }
    Tiquete(string codigoArea, int prioridadUsuario, int prioridadServicio) {
        this->codigoArea = codigoArea;
        this->prioridadUsuario = prioridadUsuario;
        this->prioridadServicio = prioridadServicio;
        consecutivo++;
        this->codigo = codigoArea + "-" + std::to_string(consecutivo);
        horaSolicitado = time(nullptr);
        horaAtendido = 0;
        tiempoEspera = 0;
        prioridadFinal = prioridadUsuario + prioridadServicio;
    }

    ~Tiquete() {}

    void atender() {
        horaAtendido = time(nullptr);
        tiempoEspera = (int)difftime(horaAtendido, horaSolicitado);
    }

    int getPrioridadFinal() const {
        return prioridadFinal;
    }

    string getCodigo() const {
        return codigo;
    }

    string getCodigoArea() const {
        return codigoArea;
    }

    int getTiempoEspera() const {
        return tiempoEspera;
    }

    void printTime(time_t t) const {
        if (t == 0) {
            cout << "N/A";
            return;
        }
        tm info;
        localtime_s(&info, &t);
        cout << (info.tm_year + 1900) << "-"
            << (info.tm_mon + 1) << "-"
            << info.tm_mday << " "
            << info.tm_hour << ":"
            << info.tm_min << ":"
            << info.tm_sec;
    }

    void print() const {
        cout << "TIQUETE: " << codigo << endl;
        cout << "AREA: " << codigoArea << endl;
        cout << "PRIORIDAD FINAL: " << prioridadFinal << endl;
        cout << "SOLICITADO: ";
        printTime(horaSolicitado);
        cout << endl;
        cout << "ATENDIDO: ";
        printTime(horaAtendido);
        cout << endl;
        cout << "TIEMPO ESPERA: " << tiempoEspera << " s" << endl;
        cout << "------------------------" << endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Tiquete& t) {
        os << "(Codigo: " << t.codigo
            << ", Area: " << t.codigoArea
            << ", Prioridad: " << t.prioridadFinal << ")";
        return os;
    }
};

int Tiquete::consecutivo = 0;
