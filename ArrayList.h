/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

    CLASE ARRAYLIST
    La clase ArrayList implementa una lista lineal utilizando un arreglo dinámico
    con capacidad máxima fija. Mantiene un cursor (posición actual) que permite
    recorrer y manipular la lista de manera secuencial.

    Esta clase hereda de la interfaz List<E>.

    FUNCIONAMIENTO

    1. ESTRUCTURA INTERNA
       - Se implementa con un arreglo dinámico (elements) de capacidad fija.
       - Mantiene tres variables de estado:
            * elements: puntero al arreglo dinámico.
            * max: capacidad máxima del arreglo.
            * size: número actual de elementos.
            * pos: índice del cursor (posición actual).

    2. EL CURSOR (POSICIÓN ACTUAL)
       - El cursor es un índice que indica la posición actual en la lista.
       - Muchas operaciones actúan sobre la posición actual del cursor.
       - El cursor puede tener valor entre 0 y size (inclusive).
       - Cuando pos == size, el cursor está "después del último elemento".

    3. OPERACIONES CON EL CURSOR
       - go_to_start(): Mueve el cursor al inicio (posición 0).
       - go_to_end(): Mueve el cursor al final (posición size).
       - go_to_pos(int): Mueve el cursor a una posición específica.
       - next(): Avanza el cursor una posición (si no está al final).
       - previous(): Retrocede el cursor una posición (si no está al inicio).
       - at_start(): Retorna true si el cursor está al inicio.
       - at_end(): Retorna true si el cursor está al final.
       - get_pos(): Retorna la posición actual del cursor.

    4. OPERACIONES DE INSERCIÓN
       - insert(E element): Inserta en la posición actual del cursor.
            * Los elementos desde pos hasta size-1 se desplazan a la derecha.

       - append(E element): Agrega al final de la lista.
            * No afecta la posición del cursor.

    5. OPERACIONES DE ELIMINACIÓN
       - remove(): Elimina el elemento en la posición actual del cursor.
            * Los elementos después de pos se desplazan a la izquierda.
            * Retorna el elemento eliminado.

    6. OPERACIONES DE ACCESO
       - get_Element(): Retorna el elemento en la posición actual del cursor.
       - set_element(E): Modifica el elemento en la posición actual del cursor.

    7. CONSULTAS
       - get_size(): Retorna la cantidad de elementos.
       - clear(): Elimina todos los elementos (size=0, pos=0).

    8. VISUALIZACIÓN
       - print(): Muestra la lista indicando con un "*" la posición del cursor.
         Ejemplo: (10, 20*, 30, 40)  → cursor en el segundo elemento (índice 1)

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    Constructor
        ArrayList(int max = DEFAULT_MAX)
        -> Crea una lista vacía con capacidad máxima opcional.
        -> La capacidad por defecto es 1024 (DEFAULT_MAX).

    Destructor
        ~ArrayList()
        -> Libera la memoria del arreglo dinámico.

    insert(E element)
        -> No devuelve nada (void).
        -> Inserta un elemento en la posición actual del cursor.
        -> Lanza runtime_error si la lista está llena.

    append(E element)
        -> No devuelve nada (void).
        -> Agrega un elemento al final de la lista.
        -> Lanza runtime_error si la lista está llena.

    set_element(E element)
        -> No devuelve nada (void).
        -> Modifica el elemento en la posición actual del cursor.
        -> Lanza runtime_error si no hay elemento actual (pos == size).

    get_Element()
        -> Devuelve un elemento de tipo E.
        -> Retorna el elemento en la posición actual del cursor.
        -> Lanza runtime_error si no hay elemento actual (pos == size).

    remove()
        -> Devuelve un elemento de tipo E.
        -> Elimina y retorna el elemento en la posición actual del cursor.
        -> Lanza runtime_error si la lista está vacía o no hay elemento actual.

    clear()
        -> No devuelve nada (void).
        -> Elimina todos los elementos (resetea size y pos a 0).

    go_to_start()
        -> No devuelve nada (void).
        -> Mueve el cursor al inicio (pos = 0).

    go_to_end()
        -> No devuelve nada (void).
        -> Mueve el cursor al final (pos = size).

    go_to_pos(int pos)
        -> No devuelve nada (void).
        -> Mueve el cursor a la posición especificada.
        -> Lanza runtime_error si la posición está fuera de rango (0..size).

    next()
        -> No devuelve nada (void).
        -> Avanza el cursor una posición (si pos < size).

    previous()
        -> No devuelve nada (void).
        -> Retrocede el cursor una posición (si pos > 0).

    at_start()
        -> Devuelve un bool.
        -> Retorna true si el cursor está al inicio (pos == 0).

    at_end()
        -> Devuelve un bool.
        -> Retorna true si el cursor está al final (pos == size).

    get_pos()
        -> Devuelve un int.
        -> Retorna la posición actual del cursor.

    get_size()
        -> Devuelve un int.
        -> Retorna la cantidad de elementos en la lista.

    print()
        -> No devuelve nada (void).
        -> Imprime la lista con formato (elem1, elem2*, elem3).
        -> El "*" indica la posición actual del cursor.
*/

#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "List.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {
private:
	E* elements;
	int max;
	int size;
	int pos;

public:
	ArrayList(int max = DEFAULT_MAX) {
		elements = new E[max];
		this->max = max;
		size = pos = 0;
	}

	~ArrayList() {
		delete[] elements;
	}

	void insert(E element) {
		if (size == max)
			throw runtime_error("List is full");
		for (int i = size; i > pos; i--)
			elements[i] = elements[i - 1];
		elements[pos] = element;
		size++;
	}

	void append(E element) {
		if (size == max)
			throw runtime_error("List is full");
		elements[size] = element;
		size++;
	}

	void set_element(E element) {
		if (pos == size)
			throw runtime_error("No current element");
		elements[pos] = element;
	}

	E get_Element() {
		if (pos == size)
			throw runtime_error("No current element");
		return elements[pos];
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is empty");
		if (pos == size)
			throw runtime_error("No current element");
		E element = elements[pos];
		for (int i = pos; i < size; i++)
			elements[i] = elements[i + 1];
		size--;
		return element;
	}

	void clear() {
		pos = size = 0;
	}

	void go_to_start() {
		pos = 0;
	}

	void go_to_end() {
		pos = size;
	}

	void go_to_pos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of bounds");
		this->pos = pos;
	}

	void next() {
		if (pos < size)
			pos++;
	}

	void previous() {
		if (pos > 0)
			pos--;
	}

	bool at_start() {
		return pos == 0;
	}

	bool at_end() {
		return pos == size;
	}

	int get_pos() {
		return pos;
	}

	int get_size() {
		return size;
	}

	void print() {
		cout << "(";
		for (int i = 0; i < size; i++) {
			cout << elements[i];
			if (i == pos)
				cout << "*";
			if (i < size - 1)
				cout << ", ";
		}
		cout << ")" << endl;
	}
};