#ifndef ROPA_H
#define ROPA_H

#include <iostream>
#include "Productos.h"
using namespace std;

// Definición de la clase Ropa, que hereda de Producto<Ropa>
class Ropa : public Producto<Ropa> {
    protected:
        string talla;
        string color; // Atributos específicos de productos de ropa

    public:
        // Constructor específico para productos de ropa
        Ropa(string n, int c, float p, int cd, string cat, string t, string cl):
            Producto(n, c, p, cd, cat), talla(t), color(cl) {}

        // Métodos set para la talla y color
        void setTalla(string t) { this->talla = t; }
        void setColor(string c) { this->color = c; }

        // Métodos get para obtener la talla y color
        string getTalla() { return this->talla; }
        string getColor() { return this->color; }

        // Método para mostrar detalles, sobrescribe el método virtual de Producto
        void mostrarDetalles() {
            Producto::mostrarDetalles(); // Llama al método de la clase base
            cout << "Talla: " << this->talla << endl;
            cout << "Color: " << this->color << endl;
        }
};


#endif
