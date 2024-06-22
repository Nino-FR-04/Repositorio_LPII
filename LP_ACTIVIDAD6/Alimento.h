#ifndef ALIMENTO_H
#define ALIMENTO_H

#include <iostream>
#include "Productos.h"
using namespace std;

// Definición de la clase Alimento, que hereda de Producto<Alimento>
class Alimento : public Producto<Alimento> {
    protected:
        string f_venc; // Atributo específico de productos de alimentos

    public:
        // Constructor específico para productos de alimentos
        Alimento(string n, int c, float p, int cd, string cat, string fv):
            Producto(n, c, p, cd, cat), f_venc(fv) {}

        // Método set para la fecha de vencimiento
        void setF_venc(string fv) { this->f_venc = fv; }

        // Método get para obtener la fecha de vencimiento
        string getF_venc() { return this->f_venc; }

        // Método para mostrar detalles, sobrescribe el método virtual de Producto
        void mostrarDetalles() override {
            Producto::mostrarDetalles(); // Llama al método de la clase base
            cout << "Fecha de vencimiento: " << this->f_venc << endl;
        }
};

#endif