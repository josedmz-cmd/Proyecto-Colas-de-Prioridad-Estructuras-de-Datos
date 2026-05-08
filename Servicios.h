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

