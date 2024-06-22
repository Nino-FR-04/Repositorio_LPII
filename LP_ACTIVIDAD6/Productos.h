#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <iostream>
using namespace std;

// Definición de la clase genérica Producto
template<typename T>
class Producto {
    protected:
        // Atributos comunes a todos los productos
        string nombre;
        int codigo;
        float precio;
        int cant_disp;
        string categoria;

    public:
        // Constructor para inicializar los atributos
        Producto(string n, int c, float p, int cd, string cat):
            nombre(n), codigo(c), precio(p), cant_disp(cd), categoria(cat) {}

        // Métodos set para modificar los atributos
        void setNombre(string n) { this->nombre = n; }
        void setCodigo(int c) { this->codigo = c; }
        void setPrecio(float p) { this->precio = p; }
        void setCantDisp(int cd) { this->cant_disp = cd; } 
        void setCategoria(string cat) { this->categoria = cat; }

        // Métodos get para obtener los atributos
        string getNombre() { return this->nombre; }
        int getCodigo() { return this->codigo; }
        float getPrecio() { return this->precio; }
        int getCantDisp() { return this->cant_disp; }
        string getCategoria() { return this->categoria; }

        // Método virtual para mostrar los detalles del producto
        virtual void mostrarDetalles() {
            cout << "Nombre: " << this->nombre << endl;
            cout << "Codigo: " << this->codigo << endl;
            cout << "Precio: " << this->precio << endl;
            cout << "Cantidad disponible: " << this->cant_disp << endl;
            cout << "Categoria: " << this->categoria << endl;
        }
};

#endif