#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MES 12
#define ANIO 5

int main() 
{
    int produccion[ANIO][MES];
    srand(time(NULL));
    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
         produccion[i][j] = 10000 + rand() % 40000;   
         printf("%7d", produccion[i][j]);
        }
        printf("\n\n");
    }

    printf("\nCalculo de ganancias por anio\n\n");
    float ganancias[] = {0, 0, 0, 0, 0};
    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
         ganancias[i] = ganancias[i] + produccion[i][j];
        }
        ganancias[i] = ganancias[i]/12;
    }
    printf("\nMuestra de ganancias por anio\n");
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    
}
