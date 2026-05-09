/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

    CLASE PAIR
    La clase Pair es una estructura genérica que permite almacenar un par de valores
    de dos tipos diferentes (K y V). Es útil para crear relaciones clave-valor
    como las utilizadas en diccionarios, mapas o estadísticas.

    Cada objeto de tipo Pair almacena:
    - Una clave (key) de tipo K.
    - Un valor (value) de tipo V.

    FUNCIONAMIENTO

    1. CREACIÓN DEL PAR
       - Se puede crear un Pair de tres formas:
            * Pair<K, V>()         → Constructor por defecto (key y valor sin inicializar).
            * Pair<K, V>(key)      → Solo clave, valor se inicializa por defecto.
            * Pair<K, V>(key, value) → Clave y valor especificados.

       - Ejemplos:
            Pair<int, string> p1(1, "Uno");        // key=1, value="Uno"
            Pair<string, int> p2("Edad", 25);      // key="Edad", value=25
            Pair<char, double> p3('A');            // key='A'

    2. OPERADORES DE COMPARACIÓN
       - Los operadores de comparación (==, !=, <, <=, >, >=) solo comparan la CLAVE (key).
       - El valor (value) NO se tiene en cuenta en las comparaciones.

       - Esto permite ordenar o comparar Pares basándose únicamente en su clave.

       - Ejemplo:
            Pair<int, string> a(5, "Cinco");
            Pair<int, string> b(10, "Diez");
            bool resultado = a < b;    // true porque 5 < 10 (compara solo clave)

    3. VISUALIZACIÓN
       - El operador << está sobrecargado para imprimir el Pair en formato (key, value).
       - Ejemplo de salida:
            (1, 10)
            ("Nombre", "Juan")
            (5, Hola)

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    Constructores
        -> Pair()
           → Crea un Pair vacío.

        -> Pair(K key)
           → Crea un Pair con clave especificada y valor por defecto.

        -> Pair(K key, V value)
           → Crea un Pair con clave y valor especificados.

    operator==(const Pair<K,V>& other)
        -> Devuelve un bool.
        -> Retorna true si this->key == other.key.
        -> NO compara el valor.

    operator!=(const Pair<K,V>& other)
        -> Devuelve un bool.
        -> Retorna true si this->key != other.key.
        -> NO compara el valor.

    operator<(const Pair<K,V>& other)
        -> Devuelve un bool.
        -> Retorna true si this->key < other.key.

    operator<=(const Pair<K,V>& other)
        -> Devuelve un bool.
        -> Retorna true si this->key <= other.key.

    operator>(const Pair<K,V>& other)
        -> Devuelve un bool.
        -> Retorna true si this->key > other.key.

    operator>=(const Pair<K,V>& other)
        -> Devuelve un bool.
        -> Retorna true si this->key >= other.key.

    operator<<(ostream& os, const Pair<K,V>& p)
        -> Devuelve ostream&.
        -> Permite imprimir el Pair con formato (clave, valor).
        -> Ejemplo: cout << p;  // Muestra: (5, "Hola")
*/
#pragma once

#include <iostream>

using std::ostream;

template <typename K, typename V>
class Pair {
public:
	K key;
	V value;

	Pair() {}

	Pair(K key) {
		this->key = key;
	}

	Pair(K key, V value) {
		this->key = key;
		this->value = value;
	}

	bool operator==(const Pair<K, V>& other) {
		return key == other.key;
	}

	bool operator!=(const Pair<K, V>& other) {
		return key != other.key;
	}

	bool operator<(const Pair<K, V>& other) {
		return key < other.key;
	}

	bool operator<=(const Pair<K, V>& other) {
		return key <= other.key;
	}

	bool operator>(const Pair<K, V>& other) {
		return key > other.key;
	}

	bool operator>=(const Pair<K, V>& other) {
		return key >= other.key;
	}

	friend ostream& operator<<(ostream& os, const Pair<K, V>& p) {
		os << "(" << p.key << ", " << p.value << ")";
		return os;
	}
};
