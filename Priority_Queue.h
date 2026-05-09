/*
Jared Andre Hemmings Chinchilla
José Daniel Mora Zúñiga

    CLASE PRIORITY_QUEUE (INTERFAZ)
    La clase Priority_Queue es una interfaz abstracta que define el contrato
    que deben cumplir todas las implementaciones de colas de prioridad.
    Establece los métodos que cualquier cola de prioridad debe
    proporcionar, permitiendo así diferentes implementaciones 
    sin cambiar el código que las utiliza (polimorfismo).

    FUNCIONAMIENTO

    1. CONCEPTO DE COLA DE PRIORIDAD
       - Una cola de prioridad es una estructura de datos donde cada elemento
         tiene asociada una prioridad.
       - Los elementos se extraen en orden de prioridad (el de menor prioridad
         numérica primero).
       - En este sistema, MENOR número = MAYOR prioridad.

    2. OPERACIONES FUNDAMENTALES
       - insert(): Agrega un elemento con su prioridad.
       - min(): Observa el elemento más prioritario sin eliminarlo.
       - removeMin(): Extrae y elimina el elemento más prioritario.
       - clear(): Elimina todos los elementos.
       - getSize(): Obtiene la cantidad de elementos.
       - is_empty(): Verifica si la cola está vacía.
       - print(): Muestra el contenido de la cola.

    3. DISEÑO DE INTERFAZ (Clase Abstracta)
       - Todos los métodos son virtuales puros (= 0).
       - Esto significa que no se puede instanciar directamente.
       - Las clases hijas deben implementar todos los métodos.

       - Ejemplo de herencia:
            class Heap_Priority_Queue : public Priority_Queue<E> { ... };

    4. PREVENCIÓN DE COPIAS
       - El constructor de copia está eliminado (delete).
       - El operador de asignación está eliminado (delete).
       - Esto evita copias accidentales que podrían causar problemas
         con la gestión de memoria en las implementaciones concretas.

    MÉTODOS PRINCIPALES Y LO QUE DEVUELVEN

    Constructor
        Priority_Queue()
        -> Constructor por defecto.
        -> No realiza ninguna acción específica.

    Constructor de copia (eliminado)
        Priority_Queue(const Priority_Queue<E>& other) = delete
        -> No está disponible.
        -> Previene copias no deseadas.

    Operador de asignación (eliminado)
        operator=(const Priority_Queue<E>&) = delete
        -> No está disponible.
        -> Previene asignaciones no deseadas.

    Destructor virtual
        ~Priority_Queue()
        -> Destructor virtual.
        -> Permite la destrucción correcta de objetos derivados.
        -> Está implementado (vacío) pero puede ser sobrescrito.

    insert(E element, int priority)
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Inserta un elemento con su prioridad asociada.
        -> La prioridad determina el orden de extracción.

    min()
        -> Devuelve un elemento de tipo E.
        -> Método virtual puro.
        -> Retorna el elemento con menor prioridad (sin eliminarlo).
        -> Lanza excepción si la cola está vacía.

    removeMin()
        -> Devuelve un elemento de tipo E.
        -> Método virtual puro.
        -> Elimina y retorna el elemento con menor prioridad.
        -> Lanza excepción si la cola está vacía.

    clear()
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Elimina todos los elementos de la cola.

    getSize()
        -> Devuelve un int.
        -> Método virtual puro.
        -> Retorna la cantidad de elementos actualmente en la cola.

    is_empty()
        -> Devuelve un bool.
        -> Método virtual puro.
        -> Retorna true si la cola está vacía, false en caso contrario.

    print()
        -> No devuelve nada (void).
        -> Método virtual puro.
        -> Imprime el contenido de la cola (útil para depuración).
*/

#pragma once
template <typename E>
class Priority_Queue {
public:
    Priority_Queue() {}
    Priority_Queue(const Priority_Queue<E>& other) = delete;
    void operator=(const Priority_Queue<E>&) = delete;
    virtual ~Priority_Queue() {}
    virtual void insert(E element, int priority) = 0;
    virtual E min() = 0;
    virtual E removeMin() = 0;
    virtual void clear() = 0;
    virtual int getSize() = 0;
    virtual bool is_empty() = 0;
    virtual void print() = 0;
};
