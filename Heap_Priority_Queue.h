/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

    CLASE HEAP_PRIORITY_QUEUE
    La clase Heap_Priority_Queue implementa una cola de prioridad utilizando un
    Min_Heap (heap mínimo) que almacena pares de prioridad y elemento. 
    Esta clase hereda de la interfaz Priority_Queue<E>.

    Cada objeto de tipo Heap_Priority_Queue almacena:
    - Un Min_Heap de Pair<int, E> donde:
        * La clave (key) es la prioridad (int).
        * El valor (value) es el elemento de tipo E.

    FUNCIONAMIENTO

    1. ESTRUCTURA INTERNA
       - Se utiliza un Min_Heap que mantiene los elementos ordenados por prioridad.
       - El heap mínimo garantiza que el elemento con MENOR prioridad (número más bajo)
         sea el primero en salir.

       - Internamente se almacenan Pair<int, E>:
            Pair(prioridad, elemento)

    2. INSERCIÓN (insert)
       - Recibe un elemento y su prioridad.
       - Crea un Pair con (prioridad, elemento).
       - Inserta el Pair en el Min_Heap.

    3. OBTENER MÍNIMO (min)
       - Retorna el elemento con la MENOR prioridad (sin eliminarlo).
       - Lanza excepción si la cola está vacía.

    4. ELIMINAR MÍNIMO (removeMin)
       - Elimina y retorna el elemento con la MENOR prioridad.
       - Lanza excepción si la cola está vacía.

    5. CONSULTAS
       - getSize(): Retorna la cantidad de elementos en la cola.
       - is_empty(): Retorna true si la cola está vacía.

    6. LIMPIEZA
       - clear(): Elimina todos los elementos de la cola.

    7. VISUALIZACIÓN
       - print(): Muestra el contenido interno del heap.

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    Constructor
        Heap_Priority_Queue(int max = 1024)
        -> Crea una cola de prioridad vacía con capacidad máxima opcional.
        -> Por defecto, la capacidad máxima es 1024.

    Destructor
        ~Heap_Priority_Queue()
        -> Libera la memoria del Min_Heap interno.

    insert(E element, int priority)
        -> No devuelve nada (void).
        -> Inserta un elemento con su prioridad asociada.
        -> La prioridad se usa como clave en el heap.

    min()
        -> Devuelve un elemento de tipo E.
        -> Retorna el elemento con menor prioridad (sin eliminarlo).
        -> Lanza runtime_error si la cola está vacía.

    removeMin()
        -> Devuelve un elemento de tipo E.
        -> Elimina y retorna el elemento con menor prioridad.
        -> Lanza runtime_error si la cola está vacía.

    clear()
        -> No devuelve nada (void).
        -> Elimina todos los elementos de la cola.

    getSize()
        -> Devuelve un int.
        -> Retorna la cantidad de elementos actualmente en la cola.

    is_empty()
        -> Devuelve un bool.
        -> Retorna true si la cola está vacía, false en caso contrario.

    print()
        -> No devuelve nada (void).
        -> Imprime el contenido interno del heap (útil para depuración).
*/
#pragma once

#include <iostream>
#include <stdexcept>
#include "Priority_Queue.h"
#include "Min_Heap.h"
#include "Pair.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class Heap_Priority_Queue : public Priority_Queue<E> {
private:
	Min_Heap<Pair<int, E>>* pairs;

public:
	Heap_Priority_Queue(int max = 1024) {
		pairs = new Min_Heap<Pair<int, E>>(max);
	}

	~Heap_Priority_Queue() {
		delete pairs;
	}

	void insert(E element, int priority) {
		Pair<int, E> p(priority, element);
		pairs->insert(p);
	}

	E min() {
		Pair<int, E> p = pairs->first();
		return p.value;
	}

	E removeMin() {
		Pair<int, E> p = pairs->removeFirts();
		return p.value;
	}

	void clear() {
		pairs->clear();
	}

	int getSize() {
		return pairs->getSize();
	}

	bool is_empty() {
		return pairs->isEmpty();
	}

	void print() {
		pairs->print();
	}
};
