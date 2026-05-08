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

	int getTiqueteUsuario(const string& usuario) {
		return getValor(usuarios, usuario);
	}

	int getTiqueteArea(const string& area) {
		return getValor(areas, area);
	}

	int getTiqueteVentanilla(const string& ventanilla) {
		return getValor(ventanillas, ventanilla);
	}

	void clearStats() {
		servicios.clear();
		usuarios.clear();
		areas.clear();
		ventanillas.clear();
	}

	void printStats(Area** areasArray, int numAreas, Servicios** serviciosArray, int numServicios, Usuario** usuariosArray, int numUsuarios) { //Recibir arreglos globales
		cout << "Estadisticas:" << endl;
		cout << "Tiempo promedio por Area:" << endl;
		if (numAreas == 0) {
			cout << "No hay areas registradas.";
		}
		else {
			for (int i = 0; i < numAreas; i++) {
				if (areasArray[i] != nullptr) {
					//Hay que hacer un getter que devuelva el tiempo promedio de espera
					//Se necesita getter para codigo y descripcion
					//cout << " " << areasArray[i]->getCodigo() << " - " << areasArray[i]->getDescripcion() << endl;
				}
			}
		}
		cout << endl;
		cout << "Cantidad de tiquetes dispensados por Area" << endl;
		if (numAreas == 0) {
			cout << "No hay areas registradas.";
		} else {
			for (int i = 0; i < numAreas; i++) {
				if (areasArray[i] != nullptr) {
					//int dispensados = getTiqueteArea(areasArray{i}->getCodigo());
					//cout << " " << areasArray[i]->getCodigo() << " - " << areasArray[i]->getDescripcion() << ": " << dispensados << " tiquetes" << endl;
				}
			}
		}
		cout << endl;
		cout << "Cantidad de tiquetes dispensados por Ventanilla" << endl;
		if (numAreas == 0) {
			cout << "No hay areas registradas.";
		} else {
			bool hayVentanillas = false;
			for (int i = 0; i < numAreas; i++) {
				if (areasArray[i] != nullptr) {
					//cout << "Área " << areasArray[i]->getCodigo() << ":" << endl;
					hayVentanillas = true;
				}
			}
			if (!hayVentanillas) {
				cout << "   No hay ventanillas registradas." << endl;
			}
		}
		cout << endl;
		cout << "Cantidad de tiquetes solicitados por Servicio" << endl;
		if (numServicios == 0) {
			cout << "No hay servicios registrados." << endl;
		} else {
			for (int i = 0; i < numServicios; i++) {
				if (serviciosArray[i] != nullptr) {
					//int solicitados = getTiqueteServicio(serviciosArray[i]->getDescripcion());
					//cout << " " << serviciosArray[i]->getDescripcion() << ": " << solicitados << " tiquetes" << endl;
				}
			}
		}
		cout << endl;
		cout << "Cantidad de tiquetes emitidos por Usuario" << endl;
		if (numUsuarios == 0) {
			cout << "No hay tipos de usuario registrados." << endl;
		} else {
			for (int i = 0; i < numUsuarios; i++) {
				if (usuariosArray[i] != nullptr) {
					int emitidos = getTiqueteUsuario(usuariosArray[i]->getDescripcion());
					cout << "   " << usuariosArray[i]->getDescripcion()
						<< ": " << emitidos << " tiquetes" << endl;
				}
			}
		}
		cout << endl;
	}
};

