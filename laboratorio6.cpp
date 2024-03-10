#include <iostream>
using namespace std;

void menu();
void escuela();
void biblioteca();
void calculadora();
void banco();
void pelis();


int opc;
class Libro {
    private: 
        string titulo, autor, genero;
        int anio_publicacion; 
    public: 
        Libro(string titulo, string autor, string genero, int anio_publicacion) {
            this->titulo = titulo;
            this->autor = autor;
            this->genero = genero;
            this->anio_publicacion = anio_publicacion;
        }
        void mostrarInfo() {
            cout  << "Titulo: "<< titulo << endl << "Autor: " << autor << endl << "Genero: " << genero << endl << "Anio de Publicacion: " << anio_publicacion << endl;
        }
}; 

class Estudiante {
    private: 
        string nombre, apellido, curso;
        int edad; 
    public: 
        Estudiante(string nombre, string apellido, string curso, int edad) {
            this->nombre = nombre;
            this->apellido = apellido;
            this->curso = curso;
            this->edad = edad;
        }
        void mostrarInfo() {
            cout  << "Titulo: "<< nombre << endl << "Autor: " << apellido << endl << "Genero: " << curso << endl << "Anio de Publicacion: " << edad << endl;
        }
}; 

class Calculadora {
    private: 
        int numero1, numero2;
    public: 
        Calculadora(int numero1, int numero2) {
            this->numero1 = numero1;
            this->numero2 = numero2;
        }
        void sumar() {
            cout  << "El resultado de la suma es: " << numero1 + numero2 << endl;
        }
        void restar() {
            cout  << "El resultado de la resta es: " << numero1 - numero2 << endl;
        }
        void multiplicar() {
            cout  << "El resultado de la multiplicacion es: " << numero1 * numero2 << endl;
        }
        void dividir() {
            cout  << "El resultado de la division es: " << numero1 / numero2 << endl;
        }
}; 

class cuentaBancaria {
    private: 
        string titular;
        int no_cuenta;
        float saldo;
    public: 
        cuentaBancaria (string titular, int no_cuenta, float saldo) {
            this->titular = titular;
            this->no_cuenta = no_cuenta;
            this->saldo = saldo;
        }
        void mostrarInfo() {
            cout  << "Titulo: "<< titular << endl << "No_Cuenta: " << no_cuenta << endl << "saldo: " << saldo << endl;
        }
        void consultarSaldo() {
            cout << "El saldo en esta cuenta bancaria es de: Q."<< saldo <<endl;
        }
        void depositar() {
            float deposito;
            cout << "Ingresa la cantidad de saldo que deseas ingresar" << endl;
            cin >> deposito;
            saldo += deposito;
            cout  << "Se ha realizado el depósito con exito. Tu nuevo saldo es de :Q." << saldo << endl;
        }
        void retirar() {
            float retiro;
            cout << "Ingresa la cantidad de saldo que deseas retirar" << endl;
            cin >> retiro;
            saldo -= retiro;
            cout  << "Se ha realizado el depósito con exito. Tu nuevo saldo es de :Q." << saldo << endl;
        }
}; 

class Pelicula {
    private: 
        string nombre, director, protagonista;
        int anio_publicacion; 
    public: 
        Pelicula(string nombre, string director, string protagonista, int anio_publicacion) {
            this->nombre = nombre;
            this->director = director;
            this->protagonista = protagonista;
            this->anio_publicacion = anio_publicacion;
        }
        void mostrarInfo() {
            cout  << "Titulo: "<< nombre << endl << "director: " << director << endl << "protagonista: " << protagonista << endl << "Anio de Publicacion: " << anio_publicacion << endl;
        }
}; 



int main()
{
    menu();
    system("pause");
    return 0;
}
void menu() {
    system("cls");
    while (opc <= 5) {
    system("cls");
    cout  << "Laboratorio No.6" << endl;
    cout << "1) Gestion de libros en una biblioteca" << endl;
    cout << "2) Registro de estudiantes" << endl;
    cout << "3) Calculadora simple" << endl;
    cout << "4) Gestion de cuentas bancarias" << endl;
    cout << "5) Registro de peliculas" << endl;
    cout << "6) Salir" << endl;
    cout << "Seleccione una operacion ";
    cin >> opc; 
    system("cls");
        switch(opc){
		case 1:
			biblioteca();
            system("pause");
			break;
		case 2:
            escuela();
			system("pause");
			break;
		case 3: 
            calculadora();
			system("pause");
			break;
		case 4:
            banco();
			system("pause");
			break;
		case 5: 
            pelis();
			system("pause");
			break;
        case 6: 
			break;
            system("pause");
            return;
		default:
			cout << "Opcion invalida" << endl;
	    }
    }
}

void biblioteca() {
    cout  << "------------------------------------------------------------" << endl;
    Libro libro1("Escodidos como AnneFrank", "Marcel Prins", "Historia", 2016);
    libro1.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Libro libro2("Cien anios de soledad", "Gabriel Garcia Marquez", "Realismo magico", 1967);
    libro2.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Libro libro3("El Principito", "Antoine de Saint-Exupery", "Fabula", 1943);
    libro3.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Libro libro4("1984", "George Orwell", "Ciencia ficcion", 1949);
    libro4.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Libro libro5("Orgullo y prejuicio", "Jane Austen", "Novela romantica", 1813);
    libro5.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
}

void escuela() {
    cout  << "------------------------------------------------------------" << endl;
    Estudiante estudiante1("Juan", "Garcia", "Matematicas", 20);
    estudiante1.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Estudiante estudiante2("Maria", "Lopez", "Literatura", 21);
    estudiante2.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Estudiante estudiante3("Pedro", "Martinez", "Fisica", 22);
    estudiante3.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Estudiante estudiante4("Ana", "Sanchez", "Biologia", 19);
    estudiante4.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Estudiante estudiante5("Carlos", "Gonzalez", "Historia del Arte", 23);
    estudiante5.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
}

void calculadora() {
    cout  << "------------------------------------------------------------" << endl;
    Calculadora Operacion1(100, 3);
    Operacion1.sumar();
    cout  << "------------------------------------------------------------" << endl;
    Calculadora Operacion2(3, 1);
    Operacion2.dividir();
    cout  << "------------------------------------------------------------" << endl;
    Calculadora Operacion3(1000, 40);
    Operacion3.restar();
    cout  << "------------------------------------------------------------" << endl;
    Calculadora Operacion4(90, 3);
    Operacion4.dividir();
    cout  << "------------------------------------------------------------" << endl;
    Calculadora Operacion5(100, 5);
    Operacion5.multiplicar();
    cout  << "------------------------------------------------------------" << endl;
}

void banco() {
    cuentaBancaria cuenta1("Pepe", 123456789, 3999.99);
    cuenta1.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    cuenta1.depositar();
    cuenta1.retirar();
    cout  << "------------------------------------------------------------" << endl;
    cuentaBancaria cuenta2("Saul", 987654321, 2000.00);
    cuenta2.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    cuenta2.depositar();
    cuenta2.retirar();
}

void pelis() {
    cout  << "------------------------------------------------------------" << endl;
    Pelicula peli1("Titanic", "James Cameron", " Leonardo DiCaprio", 1997);
    peli1.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Pelicula peli2("El Padrino", "Francis Ford Coppola", "Marlon Brando", 1972);
    peli2.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Pelicula peli3("La La Land", "Damien Chazelle", "Ryan Gosling", 2016);
    peli3.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Pelicula peli4("Avatar", "James Cameron", "Sam Worthington", 2009);
    peli4.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
    Pelicula peli5("Forrest Gump", "Robert Zemeckis", "Tom Hanks", 1994);
    peli5.mostrarInfo();
    cout  << "------------------------------------------------------------" << endl;
}