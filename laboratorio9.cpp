#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int opc_pila_cola;
    cout << "¿Desea utilizar una pila o una cola para gestionar las tareas?\n";
    cout << "1. Pila\n";
    cout << "2. Cola\n";
    cout << "Seleccione una opcion: ";
    cin >> opc_pila_cola;

    if (opc_pila_cola != 1 && opc_pila_cola != 2) {
        cout << "Opción inválida. Saliendo del programa...\n";
        return 1;
    }

    // Elegir la estructura de datos adecuada según la opción del usuario
    if (opc_pila_cola == 1) {
        stack<string> taskStructure;
        do {
            // Mostrar menú
            int opc;
            cout << "Menu:\n";
            cout << "1. Agregar una tarea\n";
            cout << "2. Completar la ultima tarea\n";
            cout << "3. Atender la tarea más antigua\n";
            cout << "4. Mostrar todas las tareas\n";
            cout << "5. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opc;

            switch (opc) {
                case 1: {
                    string tarea;
                    cout << "Ingrese el nombre de la tarea: ";
                    cin >> tarea;
                    taskStructure.push(tarea);
                    break;
                }
                case 2: {
                    if (!taskStructure.empty()) {
                        cout << "Tarea completada: " << taskStructure.top() << endl;
                        taskStructure.pop();
                    } else {
                        cout << "No hay tareas pendientes en la pila.\n";
                    }
                    break;
                }
                case 3: {
                    if (!taskStructure.empty()) {
                        cout << "Tarea atendida: " << taskStructure.top() << endl;
                        taskStructure.pop();
                    } else {
                        cout << "No hay tareas pendientes en la pila.\n";
                    }
                    break;
                }
                case 4: {
                    cout << "Lista de tareas:\n";
                    stack<string> tempStack = taskStructure;
                    while (!tempStack.empty()) {
                        cout << tempStack.top() << endl;
                        tempStack.pop();
                    }
                    break;
                }
                case 5:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    cout << "Opción invalida. Por favor, seleccione una opción valida.\n";
            }
        } while (opc_pila_cola != 5);
    } else { // option == 2
        queue<string> taskStructure;
        do {
            int opc;
            // Mostrar menú
            cout << "Menu:\n";
            cout << "1. Agregar una tarea\n";
            cout << "2. Completar la ultima tarea\n";
            cout << "3. Atender la tarea mas antigua\n";
            cout << "4. Mostrar todas las tareas\n";
            cout << "5. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opc;

            switch (opc) {
                case 1: {
                    string tarea;
                    cout << "Ingrese el nombre de la tarea: ";
                    cin >> tarea;
                    taskStructure.push(tarea);
                    break;
                }
                case 2: {
                    if (!taskStructure.empty()) {
                        cout << "Tarea completada: " << taskStructure.front() << endl;
                        taskStructure.pop();
                    } else {
                        cout << "No hay tareas pendientes en la cola.\n";
                    }
                    break;
                }
                case 3: {
                    if (!taskStructure.empty()) {
                        cout << "Tarea atendida: " << taskStructure.front() << endl;
                        taskStructure.pop();
                    } else {
                        cout << "No hay tareas pendientes en la cola.\n";
                    }
                    break;
                }
                case 4: {
                    cout << "Lista de tareas:\n";
                    queue<string> tempQueue = taskStructure;
                    while (!tempQueue.empty()) {
                        cout << tempQueue.front() << endl;
                        tempQueue.pop();
                    }
                    break;
                }
                case 5:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    cout << "Opción invalida. Por favor, seleccione una opción valida.\n";
            }
        } while (opc_pila_cola != 5);
    }
    return 0;
}
