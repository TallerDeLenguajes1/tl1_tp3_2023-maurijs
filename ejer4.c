#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto
 {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente
 {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *productos; // El tamaño de este arreglo depende de la variable
} typedef Cliente;           // “CantidadProductosAPedir”


void cargarClientes(struct Cliente *clientes, int cantidadClientes);
void generarProductos(Producto *productos, int cantidadProductos);
void mostrarClientes(Cliente *clientes, int cantidadClientes);
float calcularCosto(Producto producto);


int main() 
{
    float costoProd;
    int cant;
    printf("Ingrese la cantidad de clientes\n");
    scanf("%d", &cant);
    Cliente *cliente = (Cliente *) malloc(cant * sizeof(Cliente));
    cargarClientes(cliente, cant);
    mostrarClientes(cliente, cant);
    printf("Calculamos el costo total del producto 1 del cliente 3:");
    costoProd = calcularCosto(cliente[0].productos[1]);
    printf("Total = %.2f", costoProd);
    free(cliente);
}

//DECLARACION DE FUNCIONES

void generarProductos(Producto *productos, int cantidadProductos) {
    int i;
    for (i = 0; i < cantidadProductos; i++) {
        productos[i].ProductoID = i + 1;
        productos[i].Cantidad = rand() % 10 + 1;
        productos[i].TipoProducto = TiposProductos[rand() % 5];
        productos[i].PrecioUnitario = rand() % 91 + 10; // Entre 10 - 100
    }
}

void cargarClientes(Cliente *clientes, int cantidadClientes) {
    int i, j;
    char nombre[50];
    for (i = 0; i < cantidadClientes; i++) {
        clientes[i].ClienteID = i + 1;
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        scanf("%s", nombre);  

        /*Al utilizar la función strlen(nombre) para calcular la longitud de la cadena de caracteres ingresada, estamos asegurando que la memoria asignada para almacenar el nombre es exactamente la necesaria. De lo contrario, podríamos estar asignando más memoria de la necesaria. Además, al utilizar la variable nombre nos aseguramos de que no estamos sobrescribiendo datos en otras áreas de la memoria.*/

        clientes[i].NombreCliente = (char *) malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, nombre);   //Pasamos el nombre
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].productos = (Producto *) malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        generarProductos(clientes[i].productos, clientes[i].CantidadProductosAPedir); // (puntero a struct producto, entero)
    }
}



void mostrarClientes(Cliente *clientes, int cantidadClientes) {
    int i, j;
    float total = 0;
    for (i = 0; i < cantidadClientes; i++) {
        sleep(1);
        printf("Cliente %d: %s\n", clientes[i].ClienteID, clientes[i].NombreCliente);
        printf("Productos:\n");
        for (j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("ID: %d, Cantidad: %d, Tipo: %s, Precio Unitario: %.2f\n",
                clientes[i].productos[j].ProductoID, clientes[i].productos[j].Cantidad,
                clientes[i].productos[j].TipoProducto, clientes[i].productos[j].PrecioUnitario);

            total = total + clientes[i].productos[j].Cantidad * clientes[i].productos[j].PrecioUnitario;
        }
         printf("\nTotal a pagar: %.2f\n\n", total);
    }
    
}


float calcularCosto(Producto producto) { //un dato de entrada puede ser por ejemplo clientes[2].productos
    printf("\ncantidad = %d\n", producto.Cantidad);
    printf("\nprecio unitario = %.2f\n", producto.PrecioUnitario);
    return producto.Cantidad * producto.PrecioUnitario;
}