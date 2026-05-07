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
		lista.go_to_start();
		for (int i = 0; i < lista.get_size(); i++) {
			Pair<string, int> actual = lista.get_Element();
			if (actual.key == clave)
				return i;
			lista.next();
		}
		return -1;
	}

	int getValor(ArrayList<Pair<string, int>>& lista, const string& clave) {
		int pos = buscarPos(lista, clave);
		if (pos != -1) {
			lista.go_to_pos(pos);
			Pair<string, int> par = lista.get_Element();
			return par.value;
		}
		return 0;
	}

	void incrementar(ArrayList<Pair<string, int>>& lista, const string& clave) {
		int pos = buscarPos(lista, clave);
		if (pos != -1) {
			lista.go_to_pos(pos);
			Pair<string, int> par = lista.get_Element();
			par.value = par.value + 1;
			lista.set_element(par);
		}
		else {
			Pair<string, int> nuevo(clave, 1);
			lista.append(nuevo);
		}
	}

public:
	Estadisticas() {
		//Ya estan iniciadas las listas
	}

	~Estadisticas() {
		//ArrayList se destruye a si mismo
	}

	void registrarTiqueteServicio(const string& descServicio) {
		incrementar(servicios, descServicio);
	}

	void registrarTiqueteUsuario(const string& descUsuario) {
		incrementar(usuarios, descUsuario);
	}

	void registrarTiqueteArea(const string& codArea) {
		incrementar(areas, codArea);
	}

	void registrarTiqueteVentanilla(const string& nomVentanilla) {
		incrementar(ventanillas, nomVentanilla);
	}

	void getTiqueteServicio(const string& servicio) {
		getValor(servicios, servicio);
	}

	void getTiqueteUsuario(const string& usuario) {
		getValor(usuarios, usuario);
	}

	void getTiqueteArea(const string& area) {
		getValor(areas, area);
	}

	void getTiqueteVentanilla(const string& ventanilla) {
		getValor(ventanillas, ventanilla);
	}

	void clearStats() {
		servicios.clear();
		usuarios.clear();
		areas.clear();
		ventanillas.clear();
	}

	void printStats() { //no definitivo
		//Se va terminar en otra ocasión
	}
};

