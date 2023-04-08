#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MES 12
#define ANIO 5

int main() 
{
    int minFecha[2];
    int maxFecha[2];
    int minimo, maximo;
    int produccion[ANIO][MES];
    float ganancias[] = {0, 0, 0, 0, 0};

    srand(time(NULL));
    sleep(1);
    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
         produccion[i][j] = 10000 + rand() % 40000;   
         printf("%7d", produccion[i][j]);
        }
        printf("\n\n");
    }
    sleep(1);

    printf("\nCalculo del promedio de ganancias por anio\n\n");
    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
         ganancias[i] = ganancias[i] + produccion[i][j];
        }
        ganancias[i] = ganancias[i]/12;
    }
    sleep(1);
    printf("\nPromedio de ganancias por anio es:\n\n");
    printf("\n2024 : %.2f\n", ganancias[0]);
    printf("\n2025 : %.2f\n", ganancias[1]);
    printf("\n2026 : %.2f\n", ganancias[2]);
    printf("\n2027 : %.2f\n", ganancias[3]);
    printf("\n2028 : %.2f\n", ganancias[4]);
    sleep(1);
    maximo = minimo = produccion[0][0];

    printf("\nValor minimo y maximo anio\n");
    sleep(1);
    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
            if (produccion[i][j] > maximo)  {
                maximo = produccion[i][j];
                maxFecha[0] = i; // ANIO
                maxFecha[1] = j; // MES
            } 
            else if (produccion[i][j] < minimo)  {
                minimo = produccion[i][j];
                minFecha[0] = i;
                minFecha[1] = j;
            }       
        }
    }
    printf("\nLa ganancia minima fue de %d y se obtuvo el %d/%d\n", minimo, minFecha[1], minFecha[0]+2024);
    printf("\nLa ganancia maxima fue de %d y se obtuvo el %d/%d\n", maximo, maxFecha[1], maxFecha[0]+2024);

    return 0;
}
