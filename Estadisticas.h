#pragma once
#include <iostream>
#include <string>
#include "ArrayList.h"
#include "Pair.h"
#include "Area.h"
#include "Servicios.h"
#include "Usuario.h"

using std::ostream;
using std::string;

class Estadisticas {
private:
	ArrayList<Pair<string, int>> servicios;
	ArrayList<Pair<string, int>> usuarios;
	ArrayList<Pair<string, int>> areas;
	ArrayList<Pair<string, int>> ventanillas;

	int buscarPos(ArrayList<Pair<string, int>>& lista, const string& clave) {
		lista.go_to_start(); //lo terminaré mañana o el miercoles en la tarde
	}

	int buscarClave() {

	}

	void incrementar() {

	}

public:
	Estadisticas() {
		//Ya estan iniciadas las listas
	}

	~Estadisticas() {
		//ArrayList se destruye a si mismo
	}

	void registrarTiqueteServicio() {

	}

	void registrarTiqueteUsuario() {

	}

	void registrarTiqueteArea() {

	}

	void registrarTiqueteVentanilla() {

	}

	void clearStats() {
		servicios.clear();
		usuarios.clear();
		areas.clear();
		ventanillas.clear();
	}

	void printStats() { //no definitivo

	}
};

