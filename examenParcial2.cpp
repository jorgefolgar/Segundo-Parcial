#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

void crearArchivo();
void abrirArchivo();
void crearEmpleado();

class empleado 
{
    private:
    string nombre, apellido;
    int edad;
    float salario;
    
    public:
    empleado(string nombre1, string apellido1, int edad1, float salario1)
    {
        nombre = nombre1;
        apellido = apellido1;
        edad = edad1;
        salario = salario1;
    }
    void mostrarInfo()
    {
        cout << "___________"
            << "\nNombre: " << nombre << "\nApellido: " << apellido << "\nEdad: " << edad << "\nSalario: " << salario << "\n_____________" << endl;
    }
    const string& getNombre() const { return nombre; }
    const string& getApellido() const { return apellido; }
    const int& getEdad() const { return edad; }
    const float& getSalario() const { return salario; }
};
vector<empleado> listaEmpleados;

void guardarEmpleadoEnArchivo(const empleado& p);

int main()
{
    string datosEmpleados = "Empleados.txt";
    int opcion;
    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Crear archivo" << endl;
        cout << "2. Ver empleados" << endl;
        cout << "3. Insertar empleados" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("CLS");
            crearArchivo();
            break;
        case 2:
            system("CLS");
            abrirArchivo();
            break;
        case 3:
            crearEmpleado();
            system("CLS");
            break;
        case 4:
            system("CLS");
            cout << "Saliendo del programa." << endl;
            break;     
        default:
            cout << "Opcion no valida. Por favor, selecciona una opcion valida." << endl;
        }
    } while (opcion != 4);
    system("pause");
    return 0;
}

void crearArchivo() {
    string archivo_ejercicio;
    cout << "Introduce el nombre del archivo a crear: ";
    cin >> archivo_ejercicio;

    ofstream archivo(D:\Users\folga\AppData\OneDrive\Escritorio\progra-20240417T041725Z-001\progra);

    if (!archivo.is_open()) {
        cout << "Error al crear el archivo." << endl;
        return;
    }

    string contenido;
    cout << "Introduce el contenido del archivo: ";
    cin.ignore();
    getline(cin, contenido);

    archivo << contenido;
    archivo.close();

    cout << "Archivo creado exitosamente." << endl;
}

void abrirArchivo() {
    string archivo_ejercicio;
    cout << "Introduce el nombre del archivo a abrir: ";
    cin >> archivo_ejercicio;

    ifstream archivo(archivo_ejercicio);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    cout << "Contenido del archivo:" << endl;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

void crearEmpleado(){
    string nombre, apellido;
    int edad;
    float salario;
    cout << "Ingresar Persona:" << endl << endl;

    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;

    cout << "\nIngrese el apellido de la persona: ";
    cin >> apellido;

    cout << "\nIngrese la edad de la persona: ";
    cin >> edad;

    cout << "\nIngrese el salario de la persona: ";
    cin >> salario;

    empleado empleado1(nombre, apellido, edad, salario);
    listaEmpleados.push_back(empleado1);
    guardarEmpleadoEnArchivo(empleado1);
}

void guardarEmpleadoEnArchivo(const empleado& p) {
    ofstream archivo("Empleados.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << p.getNombre() << " Apellido: " << p.getApellido() <<  " Edad: " << p.getEdad() << "Salario: " << p.getSalario() << endl;
        archivo << "-------------------" << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
