#include <stdio.h>
#include <string.h>
#include "practica3.h"

int main(void) {
    struct pelicula videoteca[TAM];
    int n;

    printf("¿Cuántas películas vas a guardar? (máximo %d): ", TAM);
    scanf("%d", &n);

    if (n <= 0 || n > TAM) {
        printf("Error: número inválido de películas.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n🎬 Película #%d\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", videoteca[i].nombre);

        printf("Género: ");
        scanf(" %[^\n]", videoteca[i].genero);

        printf("Año: ");
        scanf("%d", &videoteca[i].year);

        printf("¿Cuántos directores tiene? (1 a %d): ", NUM_DIR);
        scanf("%d", &videoteca[i].numDirectores);

        if (videoteca[i].numDirectores <= 0 || videoteca[i].numDirectores > NUM_DIR) {
            printf("Error: número inválido de directores.\n");
            return 1;
        }

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  Nombre del director #%d: ", j + 1);
            scanf(" %[^\n]", videoteca[i].directores[j]);
        }
    }

    printf("\n####### Contenido de la videoteca #######\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("\n🎞️ Película: %s\n", videoteca[i].nombre);
        printf("Género: %s\n", videoteca[i].genero);
        printf("Año: %d\n", videoteca[i].year);
        printf("Directores (%d):\n", videoteca[i].numDirectores);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
    }

    // Búsquedas
    char nombreBuscado[50], directorBuscado[50];
    int yearBuscado;

    printf("\n🔎 Buscar película por nombre: ");
    scanf(" %[^\n]", nombreBuscado);
    buscarPorNombre(videoteca, n, nombreBuscado);

    printf("\n🔎 Buscar película por año: ");
    scanf("%d", &yearBuscado);
    buscarPorYear(videoteca, n, yearBuscado);

    printf("\n🔎 Buscar película por director: ");
    scanf(" %[^\n]", directorBuscado);
    buscarPorDirector(videoteca, n, directorBuscado);

    contarPorGenero(videoteca, n);

    return 0;
}