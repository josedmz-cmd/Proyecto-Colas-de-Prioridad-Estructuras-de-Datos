/*

Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

    CLASE MIN_HEAP
    La clase Min_Heap implementa una estructura de datos de montículo mínimo (heap binario)
    donde el elemento con el valor más pequeño se encuentra siempre en la raíz.

    FUNCIONAMIENTO

    1. ESTRUCTURA DEL HEAP
       - Se implementa como un arreglo dinámico (elements) donde:
            * El índice 0 contiene la raíz (elemento más pequeño).
            * Para un nodo en posición i:
                - Hijo izquierdo: 2*i + 1
                - Hijo derecho: 2*i + 2
                - Padre: (i - 1) / 2

       - Propiedad del heap mínimo:
            elements[parent(i)] <= elements[i] para todo i > 0

    2. INSERCIÓN (insert)
       - Se agrega el nuevo elemento al final del arreglo.
       - Se aplica "cascadeUp" para reordenar hacia arriba:
            * Si el elemento es menor que su padre, intercambian.
            * Se repite hasta que la propiedad del heap se restablece.

    3. ELIMINACIÓN DEL MÍNIMO (removeFirts)
       - Se intercambia la raíz con el último elemento.
       - Se reduce el tamaño.
       - Se aplica "cascadeDown" desde la raíz para reordenar hacia abajo:
            * Se compara con el hijo más pequeño.
            * Si el elemento es mayor que su hijo menor, intercambian.
            * Se repite hasta que la propiedad del heap se restablece.

    4. ELIMINACIÓN POR POSICIÓN (remove)
       - Elimina el elemento en una posición específica.
       - Útil para implementaciones avanzadas.

    5. CONSULTAS
       - first(): Retorna la raíz (elemento más pequeño) sin eliminar.
       - getSize(): Retorna la cantidad de elementos.
       - isEmpty(): Verifica si el heap está vacío.

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    Constructor
        Min_Heap(int max = 1024)
        -> Crea un heap vacío con capacidad máxima opcional.
        -> La capacidad por defecto es 1024.

    Destructor
        ~Min_Heap()
        -> Libera la memoria del arreglo dinámico.

    insert(E element)
        -> No devuelve nada (void).
        -> Inserta un nuevo elemento en el heap.
        -> Lanza runtime_error si el heap está lleno.
        -> Mantiene la propiedad de heap mínimo.

    first()
        -> Devuelve un elemento de tipo E.
        -> Retorna el elemento más pequeño (raíz) sin eliminarlo.
        -> Lanza runtime_error si el heap está vacío.

    removeFirts()
        -> Devuelve un elemento de tipo E.
        -> Elimina y retorna el elemento más pequeño (raíz).
        -> Lanza runtime_error si el heap está vacío.
        -> Reordena el heap para mantener la propiedad.

    remove(int pos)
        -> Devuelve un elemento de tipo E.
        -> Elimina y retorna el elemento en la posición especificada.
        -> Lanza runtime_error si el heap está vacío o índice inválido.
        -> Reordena el heap después de la eliminación.

    getSize()
        -> Devuelve un int.
        -> Retorna la cantidad de elementos actualmente en el heap.

    isEmpty()
        -> Devuelve un bool.
        -> Retorna true si el heap está vacío, false en caso contrario.

    clear()
        -> No devuelve nada (void).
        -> Elimina todos los elementos del heap.
        -> NOTA: Actualmente tiene un error (size == 0 en lugar de size = 0).

    print()
        -> No devuelve nada (void).
        -> Imprime el contenido del heap en formato [elem1, elem2, ...].

    MÉTODOS PRIVADOS AUXILIARES

    leftChild(int pos)
        -> Devuelve un int.
        -> Retorna el índice del hijo izquierdo (2*pos + 1).

    rightChild(int pos)
        -> Devuelve un int.
        -> Retorna el índice del hijo derecho (2*pos + 2).

    parent(int pos)
        -> Devuelve un int.
        -> Retorna el índice del padre ((pos - 1) / 2).

    swap(int pos1, int pos2)
        -> No devuelve nada (void).
        -> Intercambia los elementos en las posiciones dadas.

    cascadeUp(int pos)
        -> No devuelve nada (void).
        -> Reordena hacia arriba desde la posición dada.
        -> Se usa después de una inserción.

    isLeaf(int pos)
        -> Devuelve un bool.
        -> Retorna true si la posición es una hoja (sin hijos).

    minChild(int pos)
        -> Devuelve un int.
        -> Retorna el índice del hijo con menor valor.

    cascadeDown(int pos)
        -> No devuelve nada (void).
        -> Reordena hacia abajo desde la posición dada.
        -> Se usa después de una eliminación.
*/
#pragma once
#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class Min_Heap {
private:
	E* elements;
	int max;
	int size;

	int leftChild(int pos) {
		return 2 * pos + 1;
	}

	int rightChild(int pos) {
		return 2 * pos + 2;
	}

	int parent(int pos) {
		return (pos - 1) / 2;
	}

	void swap(int pos1, int pos2) {
		E temp = elements[pos1];
		elements[pos1] = elements[pos2];
		elements[pos2] = temp;
	}

	void cascadeUp(int pos) {
		while (pos > 0 and elements[pos] < elements[parent(pos)]) {
			swap(pos, parent(pos));
			pos = parent(pos);
		}
	}

	bool isLeaf(int pos) {
		return leftChild(pos) >= size;
	}

	int minChild(int pos) {
		if (rightChild(pos) < size and elements[rightChild(pos)] < elements[leftChild(pos)])
			return rightChild(pos);
		return leftChild(pos);
	}

	void cascadeDown(int pos) {
		while (!isLeaf(pos) and elements[minChild(pos)] < elements[pos]) {
			int newPos = minChild(pos);
			swap(pos, newPos);
			pos = newPos;
		}
	}

public:
	Min_Heap(int max = 1024) { //DEFAULT_MAX
		elements = new E[max];
		this->max = max;
		size = 0;
	}

	~Min_Heap() {
		delete[] elements;
	}

	void insert(E element) {
		if (size == max)
			throw runtime_error("Heap is full.");
		elements[size] = element;
		cascadeUp(size);
		size++;
	}

	E first() {
		if (size == 0)
			throw runtime_error("Heap is empty.");
		return elements[0];
	}

	E removeFirts() {
		return remove(0);
	}

	E remove(int pos) {
		if (size == 0)
			throw runtime_error("Heap is empty.");
		if (pos < 0 or pos >= size)
			throw runtime_error("Invalid index.");
		swap(pos, size - 1);
		size--;
		cascadeDown(pos);
		return elements[size];
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void clear() {
		size == 0;
	}

	void print() {
		cout << "[";
		for (int i = 0; i < size; i++) {
			cout << elements[i];
			if (i != size - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
