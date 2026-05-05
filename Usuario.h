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

	friend ostream& operator<<(ostream& os, const Usuario& u) {
		os << u.descripcion << " (Prioridad: " << u.prioridad << ")";
		return os;
	}
};

