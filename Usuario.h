/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

CLASE USUARIO
    
    DESCRIPCIÓN:
    La clase Usuario representa un tipo de usuario dentro de un sistema de
    atención o gestión de tiquetes.

    Cada usuario posee:
    - Una descripción o categoría.
    - Un nivel de prioridad.

    Esta prioridad puede utilizarse para determinar el orden en que los
    usuarios serán atendidos dentro del sistema.
    La clase también permite comparar usuarios según su prioridad y mostrar
    su información de forma sencilla.

    FUNCIONAMIENTO

    1. CREACIÓN DEL USUARIO
       - Al crear un objeto Usuario se deben proporcionar: 
            * Descripción del usuario.
            * Prioridad del usuario.
       - Ejemplo: 
            Usuario("Adulto Mayor", 5);

    2. PRIORIDAD
       - La prioridad representa el nivel de importancia del usuario.
       - Entre mayor sea el valor, mayor será la prioridad de atención.

    3. GESTIÓN DE DATOS
       - La clase permite:
            * Consultar información mediante getters.
            * Modificar información mediante setters.

    4. COMPARACIÓN ENTRE USUARIOS
       - Los operadores relacionales permiten comparar usuarios usando
         la prioridad.
            <   -> menor prioridad
            >   -> mayor prioridad
            <=  -> menor o igual prioridad
            >=  -> mayor o igual prioridad
       - Los operadores == y != comparan la descripción del usuario.

    5. VISUALIZACIÓN
       - El operador << permite imprimir directamente un objeto Usuario
         utilizando cout.
       - Ejemplo de salida:
            Adulto Mayor (Prioridad: 5)

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    getDescripcion()
        -> Devuelve un string.
        -> Retorna la descripción del usuario.

    getPrioridad()
        -> Devuelve un int.
        -> Retorna la prioridad del usuario.

    setDescripcion(string d)
        -> No devuelve nada (void).
        -> Modifica la descripción del usuario.

    setPrioridad(int p)
        -> No devuelve nada (void).
        -> Modifica la prioridad del usuario.

    operator<(const Usuario& otro)
        -> Devuelve un bool.
        -> Retorna true si la prioridad es menor que la de otro usuario.

    operator>(const Usuario& otro)
        -> Devuelve un bool.
        -> Retorna true si la prioridad es mayor que la de otro usuario.

    operator<=(const Usuario& otro)
        -> Devuelve un bool.
        -> Retorna true si la prioridad es menor o igual.

    operator>=(const Usuario& otro)
        -> Devuelve un bool.
        -> Retorna true si la prioridad es mayor o igual.

    operator==(const Usuario& otro)
        -> Devuelve un bool.
        -> Retorna true si ambos usuarios tienen la misma descripción.

    operator!=(const Usuario& otro)
        -> Devuelve un bool.
        -> Retorna true si los usuarios tienen descripciones diferentes.

    operator<<
        -> Devuelve un ostream&.
        -> Permite imprimir el objeto usando cout.
*/

#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Usuario {
private:
	string descripcion;
	int prioridad;

public:
	Usuario(string descripcion, int prioridad) {
		this->descripcion = descripcion;
		this->prioridad = prioridad;
	}

	~Usuario() {}

	string getDescripcion() const {
		return descripcion; //Evitar cambios en la descripcion
	}

	int getPrioridad() const {
		return prioridad; //Evitar cambios en la prioridad
	}

	void setDescripcion(string d) {
		descripcion = d;
	}

	void setPrioridad(int p) {
		prioridad = p;
	}

	bool operator<(const Usuario& otro) const {
		return prioridad < otro.prioridad;
	}

	bool operator>(const Usuario& otro) const {
		return prioridad > otro.prioridad;
	}

	bool operator<=(const Usuario& otro) const {
		return prioridad <= otro.prioridad;
	}

	bool operator>=(const Usuario& otro) const {
		return prioridad >= otro.prioridad;
	}

	bool operator==(const Usuario& otro) const {
		return descripcion == otro.descripcion;
	}

	bool operator!=(const Usuario& otro) const {
		return descripcion != otro.descripcion;
	}

	friend ostream& operator<<(ostream& os, const Usuario& u) {
		os << u.descripcion << " (Prioridad: " << u.prioridad << ")";
		return os;
	}
};

