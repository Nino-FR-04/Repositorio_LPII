#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include <iostream>
#include "Productos.h"
using namespace std;

// Definición de la clase Electronico, que hereda de Producto<Electronico>
class Electronico : public Producto<Electronico> {
    protected:
        string tipo; // Atributo específico de electrónicos

    public:
        // Constructor específico para productos electrónicos
        Electronico(string n, int c, float p, int cd, string cat, string t):
            Producto(n, c, p, cd, cat), tipo(t) {}

        // Método set para el tipo de electrónico
        void setTipo(string t) { this->tipo = t; }

        // Método get para obtener el tipo
        string getTipo() { return this->tipo; }

        // Método para mostrar detalles, sobrescribe el método virtual de Producto
        void mostrarDetalles() {
            Producto::mostrarDetalles(); // Llama al método de la clase base
            cout << "Tipo: " << this->tipo << endl;
        }
};

#endif
