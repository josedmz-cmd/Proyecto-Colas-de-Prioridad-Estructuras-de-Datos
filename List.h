/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

CLASE LIST (INTERFAZ)
    La clase List es una interfaz abstracta que define el contrato que deben
    cumplir todas las implementaciones de listas lineales con cursor.

    Esta clase establece los métodos que cualquier lista debe proporcionar,
    permitiendo así diferentes implementaciones sin cambiar el código que 
    las utiliza (polimorfismo).

    FUNCIONAMIENTO

    1. CONCEPTO DE LISTA CON CURSOR
       - La lista mantiene una "posición actual" o cursor.
       - Las operaciones de inserción, eliminación y acceso trabajan sobre
         la posición actual del cursor.
       - El cursor puede moverse a lo largo de la lista mediante métodos
         específicos (go_to_start, next, previous, etc.).

    2. EL CURSOR
       - El cursor es un índice o puntero interno a la lista.
       - Puede estar en tres estados posibles:
            * Al inicio (posición 0)
            * En medio de la lista (posición entre 1 y size-1)
            * Al final (posición igual a size - "después del último")

       - Cuando el cursor está en una posición válida:
            * get_Element() retorna el elemento actual
            * set_element() modifica el elemento actual
            * remove() elimina el elemento actual
            * insert() agrega un elemento antes de la posición actual

    3. OPERACIONES CON EL CURSOR
       - go_to_start(): Mueve el cursor al inicio (posición 0).
       - go_to_end(): Mueve el cursor al final (posición size).
       - go_to_pos(int): Mueve el cursor a una posición específica.
       - next(): Avanza el cursor una posición.
       - previous(): Retrocede el cursor una posición.
       - at_start(): Verifica si el cursor está al inicio.
       - at_end(): Verifica si el cursor está al final.
       - get_pos(): Retorna la posición actual del cursor.

    4. OPERACIONES DE INSERCIÓN
       - insert(E element): Inserta en la posición actual del cursor.
            * El nuevo elemento se coloca ANTES de la posición actual.
            * El cursor queda apuntando al nuevo elemento.
       - append(E element): Agrega al final de la lista.
            * No afecta la posición del cursor.

    5. OPERACIONES DE ELIMINACIÓN Y ACCESO
       - remove(): Elimina el elemento en la posición actual.
            * El cursor queda apuntando al elemento que seguía al eliminado.
       - get_Element(): Retorna el elemento en la posición actual.
       - set_element(E): Modifica el elemento en la posición actual.

    6. CONSULTAS Y LIMPIEZA
       - get_size(): Retorna la cantidad de elementos.
       - clear(): Elimina todos los elementos (resetea el cursor).
       - print(): Muestra el contenido de la lista.

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    Constructor
        List()
        -> Constructor por defecto.
        -> No realiza ninguna acción específica.

    Constructor de copia (eliminado)
        List(const List<E>& other) = delete
        -> No está disponible.
        -> Previene copias no deseadas de listas.

    Operador de asignación (eliminado)
        operator=(const List<E>&) = delete
        -> No está disponible.
        -> Previene asignaciones no deseadas.

    Destructor virtual
        ~List()
        -> Destructor virtual.
        -> Permite la destrucción correcta de objetos derivados.

    insert(E element)
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Inserta un elemento en la posición actual del cursor.

    append(E element)
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Agrega un elemento al final de la lista.

    set_element(E element)
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Modifica el elemento en la posición actual del cursor.

    get_Element()
        -> Devuelve un elemento de tipo E.
        -> Método virtual puro.
        -> Retorna el elemento en la posición actual del cursor.

    remove()
        -> Devuelve un elemento de tipo E.
        -> Método virtual puro.
        -> Elimina y retorna el elemento en la posición actual.

    clear()
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Elimina todos los elementos de la lista.

    go_to_start()
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Mueve el cursor al inicio de la lista.

    go_to_end()
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Mueve el cursor al final de la lista.

    go_to_pos(int pos)
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Mueve el cursor a la posición especificada.

    next()
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Avanza el cursor una posición.

    previous()
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Retrocede el cursor una posición.

    at_start()
        -> Devuelve un bool.
        -> Método virtual puro.
        -> Retorna true si el cursor está al inicio.

    at_end()
        -> Devuelve un bool.
        -> Método virtual puro.
        -> Retorna true si el cursor está al final.

    get_pos()
        -> Devuelve un int.
        -> Método virtual puro.
        -> Retorna la posición actual del cursor.

    get_size()
        -> Devuelve un int.
        -> Método virtual puro.
        -> Retorna la cantidad de elementos en la lista.

    print()
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Imprime el contenido de la lista.
*/
#pragma once
template <typename E>
class List {
public:
	List() {}
	List(const List<E>& other) = delete;
	void operator=(const List<E>& other) = delete;
	virtual ~List() {}
	virtual void insert(E element) = 0;
	virtual void append(E element) = 0;
	virtual void set_element(E element) = 0;
	virtual E get_Element() = 0;
	virtual E remove() = 0;
	virtual void clear() = 0;
	virtual void go_to_start() = 0;
	virtual void go_to_end() = 0;
	virtual void go_to_pos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool at_start() = 0;
	virtual bool at_end() = 0;
	virtual int get_pos() = 0;
	virtual int get_size() = 0;
	virtual void print() = 0;
};
