#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include "Productos.h"
using namespace std;

// Definición de la clase genérica Inventario para almacenar productos de cualquier tipo
template<typename T>
    class Inventario {
    protected:
        vector<T> productos; // Vector para almacenar los productos

    public:
        // Método para agregar un producto al inventario
        void agregarProducto(T& producto) { this->productos.push_back(producto); }

        // Método para actualizar el precio y cantidad disponible de un producto
        void actualizarProducto(int codigo, float precio, int cantidad) {
            for (int i = 0; i < productos.size(); i++) {
                if (productos[i].getCodigo() == codigo) {
                    productos[i].setPrecio(precio);
                    productos[i].setCantDisp(cantidad);
                    break; // Salir del bucle una vez actualizado
                }
            }
        }

        // Método para eliminar un producto del inventario
        void eliminarProductos(T& producto) {
            for (int i = 0; i < productos.size(); i++) {
                if (productos[i].getCodigo() == producto.getCodigo()) {
                    productos.erase(productos.begin() + i); // Elimina el producto
                    break; // Salir del bucle una vez eliminado
                }
            }
        }

        // Método para buscar un producto por código y devolver un puntero al producto encontrado
        T* buscarProducto(T& dato) {
            for (int i = 0; i < productos.size(); i++) {
                if (productos[i].getCodigo() == dato.getCodigo()) {
                    return &productos[i]; // Devuelve un puntero al producto encontrado
                }
            }
            return nullptr; // Si no se encuentra el producto, devuelve nullptr
        }

        // Método para generar un informe de productos por una categoría específica
        void generarInformeCategorias(string& categoria) {
            for (int i = 0; i < productos.size(); i++) {
                if (categoria == productos[i].getCategoria()) {
                    productos[i].mostrarDetalles(); // Muestra los detalles del producto
                }
            }
        }

        // Funciones amigas para ordenar los productos por precio y nombre
        template <typename U>
        friend void ordenarPorPrecio(Inventario<U>& inventario);
        template <typename U>
        friend void ordenarPorNombre(Inventario<U>& inventario);

        // Método para listar todos los productos del inventario
        void listarProductos() {
            for (int i = 0; i < productos.size(); i++) {
                productos[i].mostrarDetalles(); // Muestra los detalles de cada producto
            }
        }
};

// Función para ordenar productos por precio (amiga de la clase Inventario)
template <typename U>
void ordenarPorPrecio(Inventario<U>& inventario) {
    for (int i = 0; i < inventario.productos.size(); i++) {
        for (int j = i + 1; j < inventario.productos.size(); j++) {
            if (inventario.productos[i].getPrecio() > inventario.productos[j].getPrecio()) {
                U aux = inventario.productos[i];
                inventario.productos[i] = inventario.productos[j];
                inventario.productos[j] = aux;
            }
        }
    }
}

// Función para ordenar productos por nombre (amiga de la clase Inventario)
template <typename U>
void ordenarPorNombre(Inventario<U>& inventario) {
    for (int i = 0; i < inventario.productos.size(); i++) {
        for (int j = i + 1; j < inventario.productos.size(); j++) {
            if (inventario.productos[i].getNombre() > inventario.productos[j].getNombre()) {
                U aux = inventario.productos[i];
                inventario.productos[i] = inventario.productos[j];
                inventario.productos[j] = aux;
            }
        }
    }
}

#endif