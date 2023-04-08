#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRES 5
#define LONGITUD_NOMBRE 30

int main() {

    char *nombres[NOMBRES]; //vector de punteros
    int i;
    char nombre[20];
    printf("Ingrese %d nombres:\n", NOMBRES);

    for (i = 0; i < NOMBRES; i++) {

        gets(nombre); 
        /*Al utilizar la función strlen(nombre) para calcular la longitud de la cadena de caracteres ingresada, estamos asegurando que la memoria asignada para almacenar el nombre es exactamente la necesaria. De lo contrario, podríamos estar asignando más memoria de la necesaria. Además, al utilizar la variable nombre nos aseguramos de que no estamos sobrescribiendo datos en otras áreas de la memoria.*/
        nombres[i] = (char *) malloc((strlen(nombre)+1) * sizeof(char));     // Reservar memoria para el nombre
        strcpy(nombres[i], nombre);
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
