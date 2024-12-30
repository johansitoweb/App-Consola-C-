#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tarea {
    string titulo;
    string descripcion;
};

vector<Tarea> tareas;

void agregarTarea() {
    Tarea nuevaTarea;
    cout << "Ingrese el título de la tarea: ";
    getline(cin, nuevaTarea.titulo);
    cout << "Ingrese la descripción de la tarea: ";
    getline(cin, nuevaTarea.descripcion);
    tareas.push_back(nuevaTarea);
    cout << "Tarea agregada correctamente." << endl;
}

void eliminarTarea() {
    if (tareas.empty()) {
        cout << "No hay tareas para eliminar." << endl;
        return;
    }

    int indice;
    cout << "Ingrese el índice de la tarea a eliminar: ";
    cin >> indice;
    if (indice >= 0 && indice < tareas.size()) {
        tareas.erase(tareas.begin() + indice);
        cout << "Tarea eliminada correctamente." << endl;
    } else {
        cout << "Índice inválido." << endl;
    }
}

void listarTareas() {
    if (tareas.empty()) {
        cout << "No hay tareas." << endl;
        return;
    }

    cout << "Lista de tareas:" << endl;
    for (int i = 0; i < tareas.size(); i++) {
        cout << i << ". " << tareas[i].titulo << endl;
    }
}

int main() {
    int opcion;

    do {
        cout << "1. Agregar tarea" << endl;
        cout << "2. Eliminar tarea" << endl;
        cout << "3. Listar tareas" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarTarea();
                break;
            case 2:
                eliminarTarea();
                break;
            case 3:
                listarTareas();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }

    } while (opcion != 0);

    return 0;
}