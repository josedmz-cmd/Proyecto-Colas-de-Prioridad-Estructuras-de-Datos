/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

    CLASE SERVICIOS
    
    DESCRIPCIÓN:
    La clase Servicios representa un servicio disponible dentro de un sistema
    de atención al cliente o gestión de tiquetes.

    Cada servicio contiene información necesaria para identificar:  
    - La descripción del servicio.
    - Su nivel de prioridad.
    - El código del área al que pertenece.

    Esta clase permite almacenar, modificar, comparar e imprimir información
    relacionada con distintos servicios ofrecidos por el sistema.

    FUNCIONAMIENTO

    1. CREACIÓN DEL SERVICIO
       - Al crear un objeto de tipo Servicios se deben proporcionar: 
            * Descripción del servicio.
            * Prioridad del servicio.
            * Código del área.
       - Ejemplo:
            Servicios("Pago de facturas", 2, "PAG");

    2. GESTIÓN DE DATOS
       - La clase permite:
            * Consultar información mediante getters.
            * Modificar información mediante setters.

    3. PRIORIDAD
       - La prioridad representa la importancia del servicio.
       - Puede utilizarse para ordenar o priorizar la atención.

    4. COMPARACIÓN DE SERVICIOS
       - Se pueden comparar dos objetos Servicios usando:
            ==  -> iguales
            !=  -> diferentes
       - La comparación se realiza utilizando la descripción del servicio.

    5. VISUALIZACIÓN
       - El operador << permite imprimir fácilmente un servicio usando cout.
       - Ejemplo de salida:
            Pago de facturas (Prioridad: 2, Área: PAG)

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    getDescripcion()
        -> Devuelve un string.
        -> Retorna la descripción del servicio.

    getPrioridad()
        -> Devuelve un int.
        -> Retorna la prioridad asignada al servicio.

    getCodigo()
        -> Devuelve un string.
        -> Retorna el código del área del servicio.

    setDescripcion(const string& desc)
        -> No devuelve nada (void).
        -> Modifica la descripción del servicio.

    setPrioridad(int prio)
        -> No devuelve nada (void).
        -> Modifica la prioridad del servicio.

    setCodigo(const string& cod)
        -> No devuelve nada (void).
        -> Modifica el código del área.

    operator==(const Servicios& otro)
        -> Devuelve un bool.
        -> Retorna true si ambos servicios tienen la misma descripción.

    operator!=(const Servicios& otro)
        -> Devuelve un bool.
        -> Retorna true si ambos servicios tienen descripciones diferentes.

    operator<<
        -> Devuelve un ostream&.
        -> Permite imprimir el objeto usando cout.
*/

#pragma once
#include <iostream>;
#include <string>;

using std::string;
using std::ostream;

class Servicios {
private:
	string descripcion;
	int prioridad;
	string codArea;

public:
	Servicios(string descripcion, int prioridad, string codArea) {
		this->descripcion = descripcion;
		this->prioridad = prioridad;
		this->codArea = codArea;
	}

	~Servicios() {

	}

	string getDescripcion() const {
		return descripcion;
	}
	
	int getPrioridad() const {
		return prioridad;
	}

	string getCodigo() const {
		return codArea;
	}

	void setDescripcion(const string& desc) {
		descripcion = desc;
	}

	void setPrioridad(int prio) {
		prioridad = prio;
	}

	void setCodigo(const string& cod) {
		codArea = cod;
	}

	bool operator==(const Servicios& otro) const {
		return descripcion == otro.descripcion;
	}

	bool operator!=(const Servicios& otro) const {
		return descripcion != otro.descripcion;
	}

	friend ostream& operator<<(ostream& os, const Servicios& s) {
		os << s.descripcion << " (Prioridad: " << s.prioridad
			<< ", Área: " << s.codArea << ")";
		return os;
	}
};

