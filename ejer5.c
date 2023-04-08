#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char nombre[20];
    printf("Ingrese la cantidad de nombres que desea ingresar: ");
    scanf("%d", &n);
    fflush(stdin);
    // Reservamos espacio para n punteros a char
    char** nombres = (char**)malloc(n * sizeof(char*)); //doble puntero, apunta a un vector de punteros
    
    // Pedimos al usuario que ingrese los nombres y los guardamos en los punteros
    for (int i = 0; i < n; i++) {

        printf("Ingrese el nombre %d: ", i+1);
        gets(nombre);
        nombres[i] = (char*)malloc((strlen(nombre)+1) * sizeof(char));  // Reservamos espacio para cada nombre en cada puntero
        strcpy(nombres[i], nombre); 
    }
    
    // Mostramos los nombres ingresados
    printf("Nombres ingresados:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nombres[i]);
    }
    
    // Liberamos la memoria reservada
    for (int i = 0; i < n; i++) {
        free(nombres[i]);
    }
    free(nombres);
    
    return 0;
}
