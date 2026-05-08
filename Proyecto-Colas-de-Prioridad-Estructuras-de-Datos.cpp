// Proyecto-Colas-de-Prioridad-Estructuras-de-Datos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <ctime>
#include "ArrayList.h"
#include "Heap_Priority_Queue.h"
#include "Tiquete.h"
#include "Ventanilla.h"
#include "Area.h"
#include "Servicios.h"
#include "Usuario.h"
#include "Estadisticas.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

static const int MAX_AREAS = 20;
Area* areas[MAX_AREAS];
int numAreas = 0;
static const int MAX_SERVICIOS = 100;
Servicios* servicios[MAX_SERVICIOS];
int numServicios = 0;
static const int MAX_USUARIOS = 50;
Usuario* usuarios[MAX_USUARIOS];
int numUsuarios = 0;
Estadisticas* estadisticas = nullptr;

string leerString(const string& mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

int leerEntero(const string& prompt, int min, int max) {
    string input;
    int valor;
    while (true) {
        cout << prompt;
        getline(cin, input);
        bool esNumero = true;
        for (size_t i = 0; i < input.length(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                esNumero = false;
                break;
            }
        }
        if (!esNumero || input.empty()) {
            cout << "Error: Debe ingresar un numero valido." << endl;
            continue;
        }
        valor = 0;
        for (size_t i = 0; i < input.length(); i++) 
            valor = valor * 10 + (input[i] - '0');
        if (valor < min || valor > max) {
            cout << "Error: El valor debe estar entre " << min << " y " << max << "." << endl;
            continue;
        }
        return valor;
    }
}

char leerChar(const string& prompt, const string& opciones) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) {
            cout << "Error: Debe ingresar una opcion." << endl;
            continue;
        }
        char valor = input[0];
        if (valor >= 'A' && valor <= 'Z') {
            valor = valor + ('a' - 'A');
        }
        bool valido = false;
        for (size_t i = 0; i < opciones.length(); i++) {
            if (valor == opciones[i]) {
                valido = true;
                break;
            }
        }
        if (valido) {
            return valor;
        }
        cout << "Opcion invalida. Intente de nuevo." << endl;
    }
}

void presioneTeclaParaContinuar() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}

void limpiarPantalla() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

bool confirmarAccion(const string& mensaje) {
    char resp = leerChar(mensaje + " (s/n): ", "sn");
    return resp == 's';
}

void ordenarUsuarios() {
    for (int i = 0; i < numUsuarios - 1; i++) {
        for (int j = i + 1; j < numUsuarios; j++) {
            if (usuarios[j] != nullptr && usuarios[i] != nullptr &&
                *(usuarios[j]) < *(usuarios[i])) {
                Usuario* temp = usuarios[i];
                usuarios[i] = usuarios[j];
                usuarios[j] = temp;
            }
        }
    }
}

int buscarUsuario(const string& descripcion) {
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i] != nullptr && usuarios[i]->getDescripcion() == descripcion) {
            return i;
        }
    }
    return -1;
}

int buscarServicio(const string& descripcion) {
    for (int i = 0; i < numServicios; i++) {
        if (servicios[i] != nullptr && servicios[i]->getDescripcion() == descripcion) {
            return i;
        }
    }
    return -1;
}

int buscarArea(const string& codigo) {
    for (int i = 0; i < numAreas; i++) {
        if (areas[i] != nullptr && areas[i]->getCodigo() == codigo) {
            return i;
        }
    }
    return -1;
}

Area* getAreaPorIndice(int indice) {
    if (indice >= 0 && indice < numAreas) {
        return areas[indice];
    }
    return nullptr;
}

void mostrarUsuarios() {
    cout << "\nTipos de usuario" << endl;
    for (int i = 0; i < numUsuarios; i++) {
        cout << i + 1 << ". " << usuarios[i]->getDescripcion() << endl;
    }
}

void agregarUsuario() {
    string descripcion = leerString("Descripcion del tipo de usuario: ");
    if (buscarUsuario(descripcion) != -1) {
        cout << "Error: Ya existe un tipo de usuario con esa descripcion." << endl;
        return;
    }
    if (numUsuarios >= MAX_USUARIOS) {
        cout << "Error: Limite maximo de usuarios alcanzado." << endl;
        return;
    }
    int prioridad = leerEntero("Prioridad (menor numero = mayor prioridad): ", 1, 1000);
    usuarios[numUsuarios++] = new Usuario(descripcion, prioridad);
    ordenarUsuarios();
    cout << "Tipo de usuario agregado exitosamente." << endl;
}

void eliminarUsuario() {
    if (numUsuarios == 0) {
        cout << "No hay tipos de usuario para eliminar." << endl;
        return;
    }
    mostrarUsuarios();
    int idx = leerEntero("Seleccione tipo a eliminar (1-" + std::to_string(numUsuarios) + "): ", 1, numUsuarios);
    if (confirmarAccion("¿Eliminar " + usuarios[idx - 1]->getDescripcion() + "? Esto borrara TODOS los tiquetes del sistema.")) {
        delete usuarios[idx - 1];
        for (int i = idx - 1; i < numUsuarios - 1; i++) {
            usuarios[i] = usuarios[i + 1];
        }
        numUsuarios--;
        cout << "Tipo de usuario eliminado." << endl;
    }
}

void mostrarAreas() {
    cout << "\nAreas" << endl;
    for (int i = 0; i < numAreas; i++) {
        cout << i + 1 << ". " << areas[i]->getCodigo() << " - " << areas[i]->getDescripcion() << endl;
    }
}

void agregarArea() {
    string codigo = leerString("Codigo del area (ej: C, S, E): ");
    if (buscarArea(codigo) != -1) {
        cout << "Error: Ya existe un area con ese codigo." << endl;
        return;
    }
    if (numAreas >= MAX_AREAS) {
        cout << "Error: Limite maximo de areas alcanzado." << endl;
        return;
    }
    string descripcion = leerString("Descripcion del area: ");
    int numVentanillas = leerEntero("Numero de ventanillas: ", 1, 20);
    areas[numAreas++] = new Area(codigo + " - " + descripcion, codigo, descripcion, numVentanillas);
    cout << "Area agregada exitosamente." << endl;
}

void modificarVentanillas() {
    if (numAreas == 0) {
        cout << "No hay areas para modificar." << endl;
        return;
    }
    mostrarAreas();
    int idx = leerEntero("Seleccione area (1-" + std::to_string(numAreas) + "): ", 1, numAreas);
    int nuevoNum = leerEntero("Nuevo numero de ventanillas: ", 1, 20);
    cout << "Ventanillas modificadas." << endl;
}

void eliminarArea() {
    if (numAreas == 0) {
        cout << "No hay areas para eliminar." << endl;
        return;
    }
    mostrarAreas();
    int idx = leerEntero("Seleccione area a eliminar (1-" + std::to_string(numAreas) + "): ", 1, numAreas);
    if (confirmarAccion("¿Eliminar area " + areas[idx - 1]->getCodigo() + "? Esto eliminara los servicios asociados.")) {
        for (int i = 0; i < numServicios; i++) {
            if (servicios[i] != nullptr && servicios[i]->getCodigo() == areas[idx - 1]->getCodigo()) {
                delete servicios[i];
                for (int j = i; j < numServicios - 1; j++) {
                    servicios[j] = servicios[j + 1];
                }
                numServicios--;
                i--;
            }
        }
        delete areas[idx - 1];
        for (int i = idx - 1; i < numAreas - 1; i++) {
            areas[i] = areas[i + 1];
        }
        numAreas--;
        cout << "Area eliminada." << endl;
    }
}

void mostrarServicios() {
    cout << "\nServicios disponibles:" << endl;
    for (int i = 0; i < numServicios; i++) {
        cout << i + 1 << ". " << servicios[i]->getDescripcion()
            << " (Area: " << servicios[i]->getCodigo() << ")" << endl;
    }
}

void agregarServicio() {
    if (numAreas == 0) {
        cout << "Primero debe crear al menos un area." << endl;
        return;
    }
    string descripcion = leerString("Descripcion del servicio: ");
    if (buscarServicio(descripcion) != -1) {
        cout << "Error: Ya existe un servicio con esa descripcion." << endl;
        return;
    }
    int prioridad = leerEntero("Prioridad del servicio: ", 1, 100);
    mostrarAreas();
    int idxArea = leerEntero("Seleccione area donde se atiende (1-" + std::to_string(numAreas) + "): ", 1, numAreas);
    servicios[numServicios++] = new Servicios(descripcion, prioridad, areas[idxArea - 1]->getCodigo());
    cout << "Servicio agregado exitosamente." << endl;
}

void eliminarServicio() {
    if (numServicios == 0) {
        cout << "No hay servicios para eliminar." << endl;
        return;
    }
    mostrarServicios();
    int idx = leerEntero("Seleccione servicio a eliminar (1-" + std::to_string(numServicios) + "): ", 1, numServicios);
    if (confirmarAccion("¿Eliminar " + servicios[idx - 1]->getDescripcion() + "? Esto borrara TODOS los tiquetes del sistema.")) {
        delete servicios[idx - 1];
        for (int i = idx - 1; i < numServicios - 1; i++) {
            servicios[i] = servicios[i + 1];
        }
        numServicios--;
        cout << "Servicio eliminado." << endl;
    }
}

void reordenarServicios() {
    if (numServicios <= 1) {
        cout << "Se necesitan al menos 2 servicios para reordenar." << endl;
        return;
    }
    mostrarServicios();
    int origen = leerEntero("Posicion del servicio a mover (1-" + std::to_string(numServicios) + "): ", 1, numServicios);
    int destino = leerEntero("Posicion destino (1-" + std::to_string(numServicios) + "): ", 1, numServicios);
    if (origen == destino) {
        return;
    }
    Servicios* temp = servicios[origen - 1];
    if (origen < destino) {
        for (int i = origen - 1; i < destino - 1; i++) {
            servicios[i] = servicios[i + 1];
        }
    } else {
        for (int i = origen - 1; i > destino - 1; i--) {
            servicios[i] = servicios[i - 1];
        }
    }
    servicios[destino - 1] = temp;
    cout << "Servicios reordenados." << endl;
}

string seleccionarUsuario() {
    if (numUsuarios == 0) {
        cout << "No hay tipos de usuario registrados." << endl;
        return "";
    }
    mostrarUsuarios();
    int opcion = leerEntero("Seleccione tipo de usuario (1-" + std::to_string(numUsuarios) + "): ", 1, numUsuarios);
    return usuarios[opcion - 1]->getDescripcion();
}

string seleccionarServicio() {
    if (numServicios == 0) {
        cout << "No hay servicios registrados." << endl;
        return "";
    }
    mostrarServicios();
    int opcion = leerEntero("Seleccione servicio (1-" + std::to_string(numServicios) + "): ", 1, numServicios);
    return servicios[opcion - 1]->getDescripcion();
}

void solicitarTiquete() {
    limpiarPantalla();
    if (numUsuarios == 0) {
        cout << "No hay tipos de usuario registrados." << endl;
        presioneTeclaParaContinuar();
        return;
    }
    if (numServicios == 0) {
        cout << "No hay servicios registrados." << endl;
        presioneTeclaParaContinuar();
        return;
    }
    string descUsuario = seleccionarUsuario();
    if (descUsuario.empty()) {
        presioneTeclaParaContinuar();
        return;
    }
    string descServicio = seleccionarServicio();
    if (descServicio.empty()) {
        presioneTeclaParaContinuar();
        return;
    }
    int usuarioPos = buscarUsuario(descUsuario);
    int servicioPos = buscarServicio(descServicio);
    if (usuarioPos == -1 || servicioPos == -1) {
        cout << "Error: Datos no encontrados." << endl;
        presioneTeclaParaContinuar();
        return;
    }
    Usuario* usuario = usuarios[usuarioPos];
    Servicios* servicio = servicios[servicioPos];
    int areaPos = buscarArea(servicio->getCodigo());
    if (areaPos == -1) {
        cout << "Error: Area no encontrada para este servicio." << endl;
        presioneTeclaParaContinuar();
        return;
    }
    Tiquete tiquete(servicio->getCodigo(), usuario->getPrioridad(), servicio->getPrioridad());
    areas[areaPos]->agregarTiquete(tiquete);
    if (estadisticas != nullptr) {
        estadisticas->registrarTiqueteServicio(descServicio);
        estadisticas->registrarTiqueteUsuario(descUsuario);
        estadisticas->registrarTiqueteArea(servicio->getCodigo());
    }
    cout << "\Tiquete generado" << endl;
    cout << "Codigo: " << tiquete.getCodigo() << endl;
    cout << "Prioridad final: " << tiquete.getPrioridadFinal() << endl;
    cout << "Area: " << areas[areaPos]->getCodigo() << " - " << areas[areaPos]->getDescripcion() << endl;
    cout << "Tipo de usuario: " << usuario->getDescripcion() << endl;
    cout << "Servicio: " << servicio->getDescripcion() << endl;
    cout << endl;
    presioneTeclaParaContinuar();
}

void atenderTiquete() {
    limpiarPantalla();
    if (numAreas == 0) {
        cout << "No hay areas registradas." << endl;
        presioneTeclaParaContinuar();
        return;
    }
    mostrarAreas();
    int idxArea = leerEntero("Seleccione area (1-" + std::to_string(numAreas) + "): ", 1, numAreas);
    areas[idxArea - 1]->atenderSiguiente();
    presioneTeclaParaContinuar();
}

void limpiarColasYEstadisticas() {
    if (estadisticas != nullptr) {
        estadisticas->clearStats();
    }
    for (int i = 0; i < numAreas; i++) {
        if (areas[i] != nullptr) {
            areas[i]->reiniciarEstadisticas();
        }
    }
    cout << "Colas y estadisticas limpiadas." << endl;
}


void estadoColas() {
    limpiarPantalla();
    cout << "\nEstado del sistema:" << endl;
    if (numAreas == 0) {
        cout << "No hay areas registradas." << endl;
    }
    else {
        for (int i = 0; i < numAreas; i++) {
            if (areas[i] != nullptr) {
                areas[i]->print();
            }
        }
    }
    presioneTeclaParaContinuar();
}

void mostrarEstadisticas() {
    limpiarPantalla();
    if (estadisticas != nullptr) {
        estadisticas->printStats(areas, numAreas, servicios, numServicios, usuarios, numUsuarios);
    }
    presioneTeclaParaContinuar();
}

void MenuTiquete() { //Print del menu
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nMenu de tiquetes" << endl;
        cout << "1. Agregar Tiquete" << endl;
        cout << "2. Regresar" << endl;
        opcion = leerEntero("Seleccione opción: ", 1, 2);
        switch (opcion) {
        case 1:
            solicitarTiquete();
            break;
        case 2:
            break;
        }
    } while (opcion != 2);
}

void MenuUsuario() { //Print del menu
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nMenu de usuarios" << endl;
        cout << "1. Agregar" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Regresar" << endl;
        opcion = leerEntero("Seleccione opcion: ", 1, 3);
        switch (opcion) {
        case 1:
            agregarUsuario();
            presioneTeclaParaContinuar();
            break;
        case 2:
            eliminarUsuario();
            presioneTeclaParaContinuar();
            break;
        case 3:
            break;
        }
    } while (opcion != 3);
}

void MenuAreas() { //Print del menu
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nMenu de areas" << endl;
        cout << "1. Agregar" << endl;
        cout << "2. Modificar Ventanillas" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Regresar" << endl;
        opcion = leerEntero("Seleccione opcion: ", 1, 4);
        switch (opcion) {
        case 1:
            agregarArea();
            presioneTeclaParaContinuar();
            break;
        case 2:
            modificarVentanillas();
            presioneTeclaParaContinuar();
            break;
        case 3:
            eliminarArea();
            presioneTeclaParaContinuar();
            break;
        case 4:
            break;
        }
    } while (opcion != 4);
}

void MenuServicio() { //Print del menu
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nMenu de servicios" << endl;
        cout << "1. Agregar" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Reorganizar" << endl;
        cout << "4. Regresar" << endl;
        opcion = leerEntero("Seleccione opcion: ", 1, 4);
        switch (opcion) {
        case 1:
            agregarServicio();
            presioneTeclaParaContinuar();
            break;
        case 2:
            eliminarServicio();
            presioneTeclaParaContinuar();
            break;
        case 3:
            reordenarServicios();
            presioneTeclaParaContinuar();
            break;
        case 4:
            break;
        }
    } while (opcion != 4);
}

void MenuAdministracion() { //Print del menu
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nMenu de administracion" << endl;
        cout << "1. Tipo de usuario" << endl;
        cout << "2. Areas" << endl;
        cout << "3. Servicios" << endl;
        cout << "4. Limpiar colas y estadisticas" << endl;
        cout << "5. Regresar" << endl;
        opcion = leerEntero("Seleccione opcion: ", 1, 5);
        switch (opcion) {
        case 1:
            MenuUsuario();
            break;
        case 2:
            MenuAreas();
            break;
        case 3:
            MenuServicio();
            break;
        case 4:
            if (confirmarAccion("¿Eliminar TODOS los tiquetes y reiniciar estadisticas?")) {
                limpiarColasYEstadisticas();
                presioneTeclaParaContinuar();
            }
            break;
        case 5:
            break;
        }
    } while (opcion != 5);
}

void Menu() { //Print del menu
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nMenu Principal" << endl;
        cout << "1. Estado de las colas" << endl;
        cout << "2. Tiquetes" << endl;
        cout << "3. Atender Tiquete" << endl;
        cout << "4. Administracion" << endl;
        cout << "5. Estadisticas del sistema" << endl;
        cout << "6. Salir" << endl;
        opcion = leerEntero("Seleccione opcion: ", 1, 6);
        switch (opcion) {
        case 1:
            estadoColas();
            break;
        case 2:
            MenuTiquete();
            break;
        case 3:
            atenderTiquete();
            break;
        case 4:
            MenuAdministracion();
            break;
        case 5:
            mostrarEstadisticas();
            break;
        case 6:
            cout << "Saliendo del sistema..." << endl;
            break;
        }
    } while (opcion != 6);
}

int main() {
    estadisticas = new Estadisticas();
    usuarios[numUsuarios++] = new Usuario("Regular", 2);
    usuarios[numUsuarios++] = new Usuario("Adulto Mayor", 1);
    usuarios[numUsuarios++] = new Usuario("Discapacitado", 1);
    ordenarUsuarios();
    areas[numAreas++] = new Area("C - Cajas", "C", "Cajas", 3);
    areas[numAreas++] = new Area("S - Servicio al Cliente", "S", "Servicio al Cliente", 2);
    servicios[numServicios++] = new Servicios("Comprar boleto", 1, "C");
    servicios[numServicios++] = new Servicios("Cambiar boleto", 2, "C");
    servicios[numServicios++] = new Servicios("Solicitar informacion", 1, "S");
    servicios[numServicios++] = new Servicios("Realizar reclamo", 3, "S");
    Menu();
    for (int i = 0; i < numUsuarios; i++) {
        delete usuarios[i];
    }
    for (int i = 0; i < numServicios; i++) {
        delete servicios[i];
    }
    for (int i = 0; i < numAreas; i++) {
        delete areas[i];
    }
    delete estadisticas;
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
