#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

// Clase Material base
class Material {
protected:
    string titulo;
    string autor;

public:
    Material(string t, string a) : titulo(t), autor(a) {}
    void setTitulo(string t) { titulo = t; }
    void setAutor(string a) { autor = a; }
    string getTitulo() { return titulo; }
    string getAutor() { return autor; }
};

// Clase Libro hereda de Material
class Libro : public Material {
private:
    string ISBN;
    string genero;
    int anio;
    bool disponibilidad;

public:
    Libro(string t, string a, string i, string g, int an, bool d)
        : Material(t, a), ISBN(i), genero(g), anio(an), disponibilidad(d) {}

    void setISBN(string i) { ISBN = i; }
    void setGenero(string g) { genero = g; }
    void setAnio(int an) { anio = an; }
    void setDisponibilidad(bool d) { disponibilidad = d; }

    string getISBN()  { return ISBN; }
    string getGenero()  { return genero; }
    int getAnio()  { return anio; }
    bool getDisponibilidad()  { return disponibilidad; }

    void mostrarInfo() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Genero: " << genero << endl;
        cout << "Anio: " << anio << endl;
        cout << "Disponibilidad: " << (disponibilidad ? "Disponible" : "No disponible") << endl;
    }

    string serializar(){
        stringstream ss;
        ss << titulo << ";" << autor << ";" << ISBN << ";" << genero << ";" << anio << ";" << disponibilidad;
        return ss.str();
    }

    static Libro deserializar(string& data) {
        stringstream ss(data);
        string t, a, i, g, d;
        int an;
        bool disp;

        getline(ss, t, ';');
        getline(ss, a, ';');
        getline(ss, i, ';');
        getline(ss, g, ';');
        ss >> an;
        ss.ignore(); 
        ss >> disp;

        return Libro(t, a, i, g, an, disp);
    }
};

// Clase Usuario base
class Usuario {
protected:
    string nombre;
    int ID;
    string tipo;

public:
    Usuario(string n, int i, string t) : nombre(n), ID(i), tipo(t) {}

    void setNombre(string n) { nombre = n; }
    void setID(int i) { ID = i; }
    void setTipo(string t) { tipo = t; }

    string getNombre() { return nombre; }
    int getID() { return ID; }
    string getTipo() { return tipo; }
};

// Clase Prestamo
class Prestamo {
private:
    Libro* libro_aso;
    Usuario* usuario_aso;
    string fecha_prestamo;
    string fecha_devolucion;

public:
    Prestamo(Libro* l, Usuario* u, string fp, string fd)
        : libro_aso(l), usuario_aso(u), fecha_prestamo(fp), fecha_devolucion(fd) {}

    Libro* getLibroAso() { return libro_aso; }
    Usuario* getUsuarioAso() { return usuario_aso; }
    string getFechaPrestamo() { return fecha_prestamo; }
    string getFechaDevolucion() { return fecha_devolucion; }

    void mostrarPrestamo() {
        cout << "Libro: " << libro_aso->getTitulo() << endl;
        cout << "Usuario: " << usuario_aso->getNombre() << endl;
        cout << "Fecha de prestamo: " << fecha_prestamo << endl;
        cout << "Fecha de devolucion: " << fecha_devolucion << endl;
    }
};

// Clase Biblioteca
class Biblioteca {
private:
    vector<Libro*> libros;
    vector<Usuario*> usuarios;
    vector<Prestamo*> prestamos;

public:
    void agregarLibro(Libro* libro) { libros.push_back(libro); }

    Libro* buscarLibroPorISBN(string isbn) {
        for (auto it = libros.begin(); it != libros.end(); it++) {
            if ((*it)->getISBN() == isbn) {
                return *it;
            }
        }
        return nullptr; // Si no se encuentra el libro
    }

    void prestarLibro(Libro* libro, Usuario* usuario, string fechaPrestamo, string fechaDevolucion) {
        if (libro->getDisponibilidad()) {
            libro->setDisponibilidad(false);
            Prestamo* prestamo = new Prestamo(libro, usuario, fechaPrestamo, fechaDevolucion);
            prestamos.push_back(prestamo);
            cout << "Prestamo realizado exitosamente." << endl;
        } else {
            throw runtime_error("El libro no esta disponible para préstamo.");
        }
    }

    void mostrarCatalogo() {
        cout << "=== Catalogo de Libros ===" << endl;
        for (auto it = libros.begin(); it != libros.end(); it++) {
            (*it)->mostrarInfo();
            cout << endl;
        }
    }

    void mostrarPrestamos() {
        cout << "=== Historial de Préstamos ===" << endl;
        for (auto it = prestamos.begin(); it != prestamos.end(); it++) {
            (*it)->mostrarPrestamo();
            cout << endl;
        }
    }
};


class RegistroArchivos {
private:
    string nombreArchivo;

public:
    RegistroArchivos(const string& nombre) : nombreArchivo(nombre) {}

    // Función para guardar un vector de objetos en archivo
    template<typename T>
    void guardarDatos(vector<T*>& datos) {
        ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo " + nombreArchivo);
        }
        for (auto ptr : datos) {
            archivo << ptr->serializar() << endl;
        }
        archivo.close();
    }

    // Función para cargar datos desde archivo a un vector de objetos
    template<typename T>
    vector<T*> cargarDatos() {
        vector<T*> datos;
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo " + nombreArchivo);
        }
        string linea;
        while (getline(archivo, linea)) {
            datos.push_back(new T(T::deserializar(linea)));
        }
        archivo.close();
        return datos;
    }
};



int main() {
    // Ejemplo de uso básico del sistema de biblioteca
    Libro libro1("El Principito", "Autor1", "9788467049838", "Genero1", 1943, true);
    Libro libro2("Cien anios de soledad", "Autor2", "9786071126432", "Genero2", 1967, true);

    Usuario usuario1("Nombre Ejemplo", 1001, "Estudiante");

    Biblioteca biblioteca;
    biblioteca.agregarLibro(&libro1);
    biblioteca.agregarLibro(&libro2);

    // Guardar libros en archivo
    RegistroArchivos registro("biblioteca.txt");
    vector<Libro*> librosParaGuardar = { &libro1, &libro2 };
    registro.guardarDatos(librosParaGuardar);

    // Cargar libros desde archivo
    vector<Libro*> librosCargados = registro.cargarDatos<Libro>();
    for (auto libro : librosCargados) {
        libro->mostrarInfo();
        cout << endl;
    }

    return 0;
}
