#include <stdio.h>
#include <string.h>
#include "practica3.h"

void buscarPorNombre(struct pelicula videoteca[], int cantidad, char nombre[]) {
    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(videoteca[i].nombre, nombre) == 0) {
            printf("\nPelícula encontrada por nombre:\n");
            printf("Nombre: %s\n", videoteca[i].nombre);
            printf("Genero: %s\n", videoteca[i].genero);
            printf("Año: %d\n", videoteca[i].year);
            printf("Directores:\n");
            for (int j = 0; j < videoteca[i].numDirectores; j++) {
                printf("  - %s\n", videoteca[i].directores[j]);
            }
            encontrado = 1;
        }
    }
    if (!encontrado) printf("\nNo se encontró ninguna película con ese nombre.\n");
}

void buscarPorYear(struct pelicula videoteca[], int cantidad, int year) {
    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (videoteca[i].year == year) {
            printf("\nPelícula encontrada por año:\n");
            printf("Nombre: %s\n", videoteca[i].nombre);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("\nNo se encontró ninguna película con ese año.\n");
}

void buscarPorDirector(struct pelicula videoteca[], int cantidad, char director[]) {
    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            if (strcmp(videoteca[i].directores[j], director) == 0) {
                printf("\nPelícula encontrada por director:\n");
                printf("Nombre: %s\n", videoteca[i].nombre);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) printf("\nNo se encontró ninguna película con ese director.\n");
}

void contarPorGenero(struct pelicula videoteca[], int cantidad) {
    printf("\nConteo por género:\n");
    for (int i = 0; i < cantidad; i++) {
        int conteo = 1;
        int yaContado = 0;

        for (int k = 0; k < i; k++) {
            if (strcmp(videoteca[i].genero, videoteca[k].genero) == 0) {
                yaContado = 1;
                break;
            }
        }

        if (!yaContado) {
            for (int j = i + 1; j < cantidad; j++) {
                if (strcmp(videoteca[i].genero, videoteca[j].genero) == 0) {
                    conteo++;
                }
            }
            printf("%s: %d\n", videoteca[i].genero, conteo);
        }
    }
}