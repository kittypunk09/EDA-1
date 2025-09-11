#include <stdio.h>
#include <stdio.h>


#define TAM 21

int main(void) 
{
    int array[TAM];
    int n;

    do 
    {
        printf("Ingresa una cantidad ( 0 a %d): ", TAM);
        scanf("%d", &n);

        if (n < 0 || n > TAM)
            printf("Inválido: debe ser un número entre 0 y %d.\n", TAM);

    } while (n < 0 || n > TAM);



    for (int i = 0; i < n; i++) 
    {
        printf("Elemento [%d]: ", i);
        scanf("%d", &array[i]);
    }



    int suma = 0, min = array[0], max = array[0];
    int posicionMin = 0, posicionMax = 0;

    for (int i = 0; i < n; i++) 
    {
        suma = suma + array[i];

        if (array[i] < min) 
        {
            min = array[i];
            posicionMin = i;
        }

        if (array[i] > max) 
        {
            max = array[i];
            posicionMax = i;
        }
    }


    float total = suma;
    float avg = total / n;

    printf("\nResultados: \n");
    printf("Suma: %d\n", suma);
    printf("Promedio: %.2f\n", avg);
    printf("Mínimo: %d en el indice %d del arreglo\n", min, posicionMin);
    printf("Máximo: %d en el indice %d del arreglo\n", max, posicionMax);



    for (int i = 0; i < n / 2; i++) {
        int temp = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = temp;
    }


    printf("\nArreglo Invertido: \n");
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: %d\n", i, array[i]);
    }

    return 0;

}