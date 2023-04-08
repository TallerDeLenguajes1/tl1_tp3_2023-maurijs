#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MES 12
#define ANIO 5

int main() 
{
    
    int produccion[ANIO][MES];
    int *p_prod = produccion;
    printf("Cargo los elementos a la matriz usando punteros con notacion subindexada\n\n");
    for (int i = 0; i < MES*ANIO; i++)
    {
        p_prod[i] = 10000 + rand() % 40000;
        printf("%7d", p_prod[i]); 
        if ( (i+1) % MES == 0)
        {
            printf("\n\n");
        } 
    }
    
    printf("\n\n\nCargo los elementos a la matriz usando punteros con notacion indexada\n\n");
     for (int i = 0; i <MES*ANIO; i++)
    {
        *(p_prod + i) = 10000 + rand() % 40000;
        printf("%7d", *(p_prod + i)); 
        if ((i+1) % MES == 0)
        {
            printf("\n\n");
        }  
    }
}
/* for (i = 0; i < ANIOS; i++) {
        for (j = 0; j < MESES; j++) {
            produccion[i][j] = rand() % 40001 + 10000; // Valor aleatorio entre 10000 y 50000
        }
    }
*/    