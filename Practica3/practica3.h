#ifndef VIDEOTECA_H
#define VIDEOTECA_H

#define TAM 5
#define NUM_DIR 3

struct pelicula {
    char nombre[50];
    char genero[30];
    int  year;
    int  numDirectores;
    char directores[NUM_DIR][50];
};

// Funciones
void buscarPorNombre(struct pelicula videoteca[], int cantidad, char nombre[]);
void buscarPorYear(struct pelicula videoteca[], int cantidad, int year);
void buscarPorDirector(struct pelicula videoteca[], int cantidad, char director[]);
void contarPorGenero(struct pelicula videoteca[], int cantidad);

#endif