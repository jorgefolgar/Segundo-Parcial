// Bibliotecas
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
//CLASES
//PERSONA
class persona
{
private:
    string nombre, apellido, ocupacion;
    int edad;

public:
    persona(string nombre1, string apellido1, string ocupacion1, int edad1)
    {
        nombre = nombre1;
        apellido = apellido1;
        ocupacion = ocupacion1;
        edad = edad1;
    }
    void mostrarInfo()
    {
        cout << "___________"
             << "\nNombre: " << nombre << "\nApellido: " << apellido << "\nOcupacion: " << ocupacion << "\nEdad: " << edad << "\n_____________" << endl;
    }
    const string &getNombre() const { return nombre; }
    const string &getApellido() const { return apellido; }
    const string &getOcupacion() const { return ocupacion; }
    const int &getEdad() const { return edad; }
};
vector<persona> listaPersonas;

//ESTUDIANTE
class Estudiante : public persona {
private:
    int numeroEstudiante;
    float promedioNotas;
public:
    Estudiante(const string& _nombre, const string& _apellido, const string& _ocupacion, int _edad,
               int _numeroEstudiante, float _promedioNotas)
        : persona(_nombre, _apellido, _ocupacion, _edad), numeroEstudiante(_numeroEstudiante),
          promedioNotas(_promedioNotas) {}

    int getNumeroEstudiante() const { return numeroEstudiante; }
    float getPromedioNotas() const { return promedioNotas; }
};

vector<Estudiante> listaEstudiantes;

// Prototipos
void crearPersona();
void crearEstudiante();
void crearArchivo();
void abrirArchivo();
void modificarArchivo();
void ordenarPersonasPorNombre();
void ordenarEstudiantesPorNombre();
void guardarPersonaEnArchivo(const persona& p);
void guardarEstudianteEnArchivo(const Estudiante& e);
void guardarPersonasOrdenadas(const string& nombreArchivo);
void guardarEstudiantesOrdenados(const string& nombreArchivo);

int main()
{
    string datosLab7 = "Datos.txt";
    int opcion;
    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Crear archivo" << endl;
        cout << "2. Abrir archivo" << endl;
        cout << "3. Modificar archivo (INSERTAR A UNA NUEVA PERSONA)" << endl;
        cout << "4. Ordenar Datos" << endl;
        cout << "5. Salir" << endl;
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
            modificarArchivo();
            system("CLS");
            break;
        case 4:
            system("CLS");
            ordenarPersonasPorNombre();
            ordenarEstudiantesPorNombre();
            guardarPersonasOrdenadas("PersonasOrdenadas.txt");
            guardarEstudiantesOrdenados("EstudiantesOrdenados.txt");
            cout << "Datos ordenados por nombre y guardados en archivos." << endl;
            break;
        case 5:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor, selecciona una opcion valida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
/*********************crearArchivo()**************************/

void crearArchivo()
{
    string archivo_ejercicio;
    cout << "Introduce el nombre del archivo a crear: ";
    cin >> archivo_ejercicio;

    ofstream archivo(archivo_ejercicio);

    if (!archivo.is_open())
    {
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

/*********************crearPersona()**************************/

void crearPersona(){
    string nombre, apellido, ocupacion;
    int edad;
    cout << "Ingresar Persona:" << endl << endl;

    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;

    cout << "\nIngrese el apellido de la persona: ";
    cin >> apellido;

    cout << "\nIngrese la ocupacion de la persona: ";
    cin >> ocupacion;

    cout << "\nIngrese la edad de la persona: ";
    cin >> edad;

    persona persona1(nombre, apellido, ocupacion, edad);
    listaPersonas.push_back(persona1);
    guardarPersonaEnArchivo(persona1);
}

/*********************guardarPersonaArchivo()***********************/

void guardarPersonaEnArchivo(const persona& p) {
    ofstream archivo("Datos.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << p.getNombre() << endl;
        archivo << "Apellido: " << p.getApellido() << endl;
        archivo << "Ocupación: " << p.getOcupacion() << endl;
        archivo << "Edad: " << p.getEdad() << endl;
        archivo << "-------------------" << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

/*********************crearEstudiante()**************************/

void crearEstudiante() {
    string nombre, apellido, ocupacion;
    int edad, numeroEstudiante;
    float promedioNotas;

    cout << "Ingresar Estudiante:" << endl << endl;

    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;

    cout << "\nIngrese el apellido del estudiante: ";
    cin >> apellido;

    cout << "\nIngrese la ocupacion del estudiante: ";
    cin >> ocupacion;

    cout << "\nIngrese la edad del estudiante: ";
    cin >> edad;

    cout << "\nIngrese el número de estudiante: ";
    cin >> numeroEstudiante;

    cout << "\nIngrese el promedio de notas del estudiante: ";
    cin >> promedioNotas;

    Estudiante estudiante(nombre, apellido, ocupacion, edad, numeroEstudiante, promedioNotas);
    listaEstudiantes.push_back(estudiante);
    guardarEstudianteEnArchivo(estudiante);
}

/*********************guardarEstudianteArchivo()***********************/

void guardarEstudianteEnArchivo(const Estudiante& e) {
    ofstream archivo("Datos.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << e.getNombre() << endl;
        archivo << "Apellido: " << e.getApellido() << endl;
        archivo << "Ocupación: " << e.getOcupacion() << endl;
        archivo << "Edad: " << e.getEdad() << endl;
        archivo << "Número de estudiante: " << e.getNumeroEstudiante() << endl;
        archivo << "Promedio de notas: " << e.getPromedioNotas() << endl;
        archivo << "-------------------" << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
/*********************abrirArchivo()***********************/

void abrirArchivo()
{
    string archivo_ejercicio;
    cout << "Introduce el nombre del archivo a abrir: ";
    cin >> archivo_ejercicio;

    ifstream archivo(archivo_ejercicio);

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    cout << "Contenido del archivo:" << endl;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
}

/*********************modificarArchivo()***********************/

void modificarArchivo() {
    cout <<"Desea ingresar un estudiante o una persona (e/p):";
    char opcion;
    cin>>opcion;
    if  (opcion=='e' or opcion == 'E') { 
        crearEstudiante();
    }
    if (opcion == 'p'  or opcion == 'P') {
        crearPersona();
    }
    else {
        cout <<"Opcion no valida\n";
        return;
    }
}

/*********************guardarPersonasOrdenadas()***********************/
void guardarPersonasOrdenadas(const string& datosOrdenados) {
    ofstream archivo(datosOrdenados);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (const auto& p : listaPersonas) {
        archivo << "Nombre: " << p.getNombre() << endl;
        archivo << "Apellido: " << p.getApellido() << endl;
        archivo << "Ocupación: " << p.getOcupacion() << endl;
        archivo << "Edad: " << p.getEdad() << endl;
        archivo << "-------------------" << endl;
    }

    archivo.close();
}

/*********************guardarEstudiantesOrdenados()***********************/

void guardarEstudiantesOrdenados(const string& datosOrdenados) {
    ofstream archivo(datosOrdenados);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (const auto& e : listaEstudiantes) {
        archivo << "Nombre: " << e.getNombre() << endl;
        archivo << "Apellido: " << e.getApellido() << endl;
        archivo << "Ocupación: " << e.getOcupacion() << endl;
        archivo << "Edad: " << e.getEdad() << endl;
        archivo << "Número de estudiante: " << e.getNumeroEstudiante() << endl;
        archivo << "Promedio de notas: " << e.getPromedioNotas() << endl;
        archivo << "-------------------" << endl;
    }

    archivo.close();
}
/*********************ordenarPersonasPorNombre()***********************/

void ordenarPersonasPorNombre() {
    sort(listaPersonas.begin(), listaPersonas.end(), [](const persona& a, const persona& b) {
        return a.getNombre() < b.getNombre();
    });
}

/*********************ordenarEstudiantesPorNombre()***********************/

void ordenarEstudiantesPorNombre() {
    sort(listaEstudiantes.begin(), listaEstudiantes.end(), [](const Estudiante& a, const Estudiante& b) {
        return a.getNombre() < b.getNombre();
    });
}

