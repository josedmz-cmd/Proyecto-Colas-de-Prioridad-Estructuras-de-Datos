/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

    CLASE TIQUETE
    La clase Tiquete representa un sistema de gestión de tickets para atención de usuarios en distintas áreas de servicio.

    Cada objeto de tipo Tiquete almacena información relacionada con:
    - Código único del tiquete.
    - Área de atención.
    - Prioridad asignada.
    - Hora en que fue solicitado.
    - Hora en que fue atendido.
    - Tiempo total de espera.

    FUNCIONAMIENTO
    
    1. CREACIÓN DEL TIQUETE
       - Al crear un tiquete se genera automáticamente:
            * Un consecutivo único.
            * El código del tiquete.
            * La hora de solicitud usando time(nullptr).
            * La prioridad final.

       - El código se forma así:
            AREA-CONSECUTIVO

         Ejemplo:
            CAJ-101

    2. PRIORIDAD
       - La prioridad final se obtiene sumando:
            prioridadUsuario + prioridadServicio
       - Esto permite ordenar los tiquetes según importancia.

    3. ATENCIÓN DEL TIQUETE
       - Cuando el método atender() es llamado:
            * Se registra la hora actual como hora de atención.
            * Se calcula el tiempo de espera en segundos usando difftime().

    4. VISUALIZACIÓN
       - El método print() muestra toda la información del tiquete.
       - El operador << permite imprimir el objeto directamente con cout.

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    atender()
        -> No devuelve nada (void).
        -> Registra la hora de atención y calcula el tiempo de espera.

    getPrioridadFinal()
        -> Devuelve un int.
        -> Retorna la prioridad total del tiquete.

    getCodigo()
        -> Devuelve un string.
        -> Retorna el código único del tiquete.

    getCodigoArea()
        -> Devuelve un string.
        -> Retorna el código del área del servicio.

    getTiempoEspera()
        -> Devuelve un int.
        -> Retorna el tiempo de espera.

    getHoraSolicitud()
        -> Devuelve un time_t.
        -> Retorna la hora en que el tiquete fue solicitado.

    getHoraAtendido()
        -> Devuelve un time_t.
        -> Retorna la hora en que el tiquete fue atendido.

    setHoraAtendido(time_t hora)
        -> No devuelve nada (void).
        -> Modifica manualmente la hora de atención.

    printTime(time_t t)
        -> No devuelve nada (void).
        -> Muestra una fecha y hora en formato legible.

    print()
        -> No devuelve nada (void).
        -> Imprime toda la información del tiquete.

    operator<<
        -> Devuelve un ostream&.
        -> Permite imprimir el objeto usando cout.
*/

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
        prioridadFinal = prioridadUsuario * 10 + prioridadServicio;
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

    time_t getHoraSolicitud() const {
        return horaSolicitado;
    }

    time_t getHoraAtendido() const {
        return horaAtendido;
    }

    void setHoraAtendido(time_t hora) {
        horaAtendido = hora;
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

int Tiquete::consecutivo = 100;
