#include <iostream>
#include <vector>

#include "Productos.h"
#include "Electronico.h"
#include "Ropa.h"
#include "Alimento.h"
#include "Inventario.h"

using namespace std;

// Función para mostrar el menú de opciones
void mostrarMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Agregar Producto\n";
    cout << "2. Actualizar Producto\n";
    cout << "3. Eliminar Producto\n";
    cout << "4. Buscar Producto\n";
    cout << "5. Generar Informe por Categoria\n";
    cout << "6. Listar Productos\n";
    cout << "7. Ordenar Productos por Nombre\n";
    cout << "8. Ordenar Productos por Precio\n";
    cout << "9. Salir\n";
    cout << "Ingrese opcion: ";
}

// Función principal
int main() {
    // Creación de instancias de inventario para diferentes tipos de productos
    Inventario<Producto<Electronico>> inventarioElectronics;
    Inventario<Producto<Ropa>> inventarioRopa;
    Inventario<Producto<Alimento>> inventarioAlimentos;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Agregar Producto
                string nombre, categoria, tipo, talla, color, f_venc;
                int codigo, cant_disp;
                float precio;

                cout << "\nAgregar Producto\n";
                cout << "Nombre: "; cin >> nombre;
                cout << "Codigo: "; cin >> codigo;
                cout << "Precio: "; cin >> precio;
                cout << "Cantidad Disponible: "; cin >> cant_disp;

                int tipo_producto;
                cout << "\nTipo de Producto:\n";
                cout << "1. Electronico\n";
                cout << "2. Ropa\n";
                cout << "3. Alimento\n";
                cout << "Ingrese opcion: "; cin >> tipo_producto;

                switch (tipo_producto) {
                    case 1: {
                        cout << "Tipo (Electrónico): "; cin >> tipo;
                        Electronico e(nombre, codigo, precio, cant_disp, categoria, tipo);
                        inventarioElectronics.agregarProducto(e);
                        break;
                    }
                    case 2: {
                        cout << "Talla (Ropa): "; cin >> talla;
                        cout << "Color (Ropa): "; cin >> color;
                        Ropa r(nombre, codigo, precio, cant_disp, categoria, talla, color);
                        inventarioRopa.agregarProducto(r);
                        break;
                    }
                    case 3: {
                        cout << "Fecha de Vencimiento (Alimento): "; cin >> f_venc;
                        Alimento a(nombre, codigo, precio, cant_disp, categoria, f_venc);
                        inventarioAlimentos.agregarProducto(a);
                        break;
                    }
                    default:
                        cout << "Opcion no valida.\n";
                        break;
                }
                break;
            }
            case 2: {
                // Actualizar Producto
                int codigo;
                float nuevo_precio;
                int nueva_cantidad;

                cout << "\nActualizar Producto\n";
                cout << "Ingrese el codigo del producto: "; cin >> codigo;
                cout << "Nuevo precio: "; cin >> nuevo_precio;
                cout << "Nueva cantidad disponible: "; cin >> nueva_cantidad;

                // Implementación según el tipo de inventario correspondiente
                inventarioElectronics.actualizarProducto(codigo, nuevo_precio, nueva_cantidad);
                break;
            }
            case 3: {
                // Eliminar Producto
                int codigo;
                cout << "\nEliminar Producto\n";
                cout << "Ingrese el codigo del producto a eliminar: "; cin >> codigo;

                // Implementación según el tipo de inventario correspondiente
                Alimento a("", codigo, 0.0, 0, "", "");
                inventarioAlimentos.eliminarProductos(a);
                break;
            }
            case 4: {
                // Buscar Producto
                int codigo;
                cout << "\nBuscar Producto\n";
                cout << "Ingrese el codigo del producto: "; cin >> codigo;

                // Implementación según el tipo de inventario correspondiente
                Ropa r("", codigo, 0.0, 0, "", "", "");
                Producto<Ropa>* encontrado = inventarioRopa.buscarProducto(r);
                if (encontrado) {
                    cout << "Producto encontrado:\n";
                    encontrado->mostrarDetalles();
                } else {
                    cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 5: {
                // Generar Informe por Categoría
                string categoria;
                cout << "\nGenerar Informe por Categoria\n";
                cout << "Ingrese la categoría: "; cin >> categoria;

                // Implementación según el tipo de inventario correspondiente
                inventarioElectronics.generarInformeCategorias(categoria);
                break;
            }
            case 6: {
                // Listar Productos
                cout << "\nListado de Productos\n";
                cout << "Electronicos:\n";
                inventarioElectronics.listarProductos();
                cout << "Ropa:\n";
                inventarioRopa.listarProductos();
                cout << "Alimentos:\n";
                inventarioAlimentos.listarProductos();
                break;
            }
            case 7: {
                // Ordenar Productos por Nombre
                ordenarPorNombre(inventarioElectronics);
                ordenarPorNombre(inventarioRopa);
                ordenarPorNombre(inventarioAlimentos);
                cout << "\nProductos ordenados por Nombre.\n";
                break;
            }
            case 8: {
                // Ordenar Productos por Precio
                ordenarPorPrecio(inventarioElectronics);
                ordenarPorPrecio(inventarioRopa);
                ordenarPorPrecio(inventarioAlimentos);
                cout << "\nProductos ordenados por Precio.\n";
                break;
            }
            case 9: {
                // Salir del programa
                cout << "Saliendo...\n";
                break;
            }
            default:
                cout << "Opcion no valida.\n";
                break;
        }

    } while (opcion != 9);

    return 0;
}
