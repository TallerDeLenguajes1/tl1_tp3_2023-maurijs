#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRES 5
#define LONGITUD_NOMBRE 30

int main() {

    char *nombres[NOMBRES];
    int i;

    printf("Ingrese %d nombres:\n", NOMBRES);

    for (i = 0; i < NOMBRES; i++) {
    
        nombres[i] = (char *) malloc(LONGITUD_NOMBRE * sizeof(char));     // Reservar memoria para el nombre

        gets(nombres[i]); // Leer el nombre ingresado por el usuario
    }

    printf("Los nombres ingresados son:\n");
    for (i = 0; i < NOMBRES; i++) {
        printf("%s\n", nombres[i]);
    }

    // Mostrar la tercera letra de cada nombre ingresado usando doble indice
    printf("La tercera letra de cada nombre es:\n");
    for (i = 0; i < NOMBRES; i++) {
        printf("%c\n", nombres[i][2]);
    }

     // Mostrar la tercera  cuarta letra de cada nombre ingresado usando aritmetica de puntero
    printf("La tercera letra de cada nombre es:\n");
    for (i = 0; i < NOMBRES; i++) {
        printf("%c\n", *(nombres[i] + 2));
    }

    // Liberar la memoria reservada para los nombres
    for (i = 0; i < NOMBRES; i++) {
        free(nombres[i]);
    }

    return 0;
}
