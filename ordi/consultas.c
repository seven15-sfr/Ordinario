#include <stdio.h>
#include <string.h>
#include "consultas.h"
#include "menu.h"

void ejecutarConsultas(struct Persona *ptrFrente) {
    if (ptrFrente == NULL) {
        printf("\nLa base de datos esta vacia. No hay registros que mostrar.\n");
        return;
    }

    int opc = mostar(); // Desplegamos el menú de consultas de menu.c
    
    switch (opc) {
        case 1: 
                mostrarTodaLaLista(ptrFrente); 
                break;
        case 2: 
                mostrarPorCarrera(ptrFrente); 
                break;
        case 3: 
                mostrarPorSemestre(ptrFrente); 
                break;
        case 4: 
                mostrarPorCarreraSemestre(ptrFrente); 
                break;
        case 5: 
                buscarPorNombre(ptrFrente); 
                break;
        case 6:    
                buscarPorMatricula(ptrFrente); 
                break;
        case 7:
               printf("Regresar \n");
        default: printf("Opcion de consulta no valida.\n"); 
                break;
    }
}

void imprimirMateriasUCalificaciones(struct Alumno *alumno) {
    printf("Materias y calificaciones \n");
    for (int i = 0; i < 5; i++) {
        float sumaMateria = 0.0;
        printf("\nMateria %d:\n", i + 1);
        
        for (int j = 0; j < 4; j++) {
            printf("  Parcial %d  : %.2f\n", j + 1, alumno->calif[i][j]);
            sumaMateria += alumno->calif[i][j];
        }
        
        /* La quinta columna (calif[i][4]) la tomamos como el examen Ordinario */
        printf("  Ordinario  : %.2f\n", alumno->calif[i][4]);
        sumaMateria += alumno->calif[i][4];
        
        /* Calcula y muestra el promedio final de esa materia (fila) */
        float promedio = sumaMateria / 5.0;
        printf("  Promedio   : %.2f\n", promedio);
    }
}

void imprimirAlumnoCompleto(struct Persona *persona) {
    printf("Nombre      : %s\n", persona->nombre);
    printf("Edad        : %d\n", persona->edad);
    printf("Genero      : %c\n", persona->genero);
    printf("Fecha Nac.  : %s\n", persona->fn);

    if (persona->ptrAlum != NULL) {
        printf("Matricula   : %s\n", persona->ptrAlum->matricula);
        printf("Carrera     : %s\n", persona->ptrAlum->carrera);
        printf("Semestre    : %d\n", persona->ptrAlum->semestre);
        printf("Correo      : %s\n", persona->ptrAlum->correo);
        imprimirMateriasUCalificaciones(persona->ptrAlum);
    } else {
        printf("no tiene datos academicos \n");
    }
}

void mostrarTodaLaLista(struct Persona *ptrFrente) {
    struct Persona *aux = ptrFrente;
    int contador = 1;

    while (aux != NULL) {
        printf("ALUMNO: %d ", contador++);
        imprimirAlumnoCompleto(aux);
        aux = aux->ptrSig;
    }
}

void mostrarPorCarrera(struct Persona *ptrFrente) {
    char carrera[5];
    printf("\nIngrese la carrera a buscar (o escriba 'r' para regresar): ");
    scanf(" %4s", carrera);

    if (strcmp(carrera, "r") == 0 || strcmp(carrera, "R") == 0) {
        printf("Consulta cancelada.\n");
        return;
    }

    struct Persona *aux = ptrFrente;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->carrera, carrera) == 0) {
            imprimirAlumnoCompleto(aux);
            encontrado = 1;
        }
        aux = aux->ptrSig;
    }

    if (!encontrado) {
        printf("\nNo hay alumnos en esa carrera.\n");
    }
}

void mostrarPorSemestre(struct Persona *ptrFrente) {
    int semestre;
    printf("\nIngrese el semestre a buscar (digite 0 para regresar): ");
    scanf("%d", &semestre);

    if (semestre == 0) {
        printf("Consulta cancelada.\n");
        return;
    }

    struct Persona *aux = ptrFrente;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && aux->ptrAlum->semestre == semestre) {
            imprimirAlumnoCompleto(aux);
            encontrado = 1;
        }
        aux = aux->ptrSig;
    }

    if (!encontrado) {
        printf("\nNo hay alumnos en ese semestre.\n");
    }
}

void mostrarPorCarreraSemestre(struct Persona *ptrFrente) {
    char carrera[5];
    int semestre;

    printf("\nIngrese la carrera a buscar (o 'r' para regresar): ");
    scanf(" %4s", carrera);
    if (strcmp(carrera, "r") == 0 || strcmp(carrera, "R") == 0) return;

    printf("Ingrese el semestre: ");
    scanf("%d", &semestre);

    struct Persona *aux = ptrFrente;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->carrera, carrera) == 0 && aux->ptrAlum->semestre == semestre) {
            imprimirAlumnoCompleto(aux);
            encontrado = 1;
        }
        aux = aux->ptrSig;
    }

    if (!encontrado) {
        printf("\nNo hay alumnos con esos criterios.\n");
    }
}

void buscarPorNombre(struct Persona *ptrFrente) {
    char nombre[50];
    printf("\nIngrese el nombre completo a buscar (o 'r' para regresar): ");
    scanf(" %[^\n]", nombre);

    if (strcmp(nombre, "r") == 0 || strcmp(nombre, "R") == 0) return;

    struct Persona *aux = ptrFrente;
    int encontrado = 0;

    while (aux != NULL) {
        if (strcmp(aux->nombre, nombre) == 0) {
            imprimirAlumnoCompleto(aux);
            encontrado = 1;
        }
        aux = aux->ptrSig;
    }

    if (!encontrado) {
        printf("\nNo se encontro el alumno.\n");
    }
}

void buscarPorMatricula(struct Persona *ptrFrente) {
    char matricula[10];
    printf("\nIngrese la matricula del alumno (o 'r' para regresar): ");
    scanf(" %9s", matricula);

    if (strcmp(matricula, "r") == 0 || strcmp(matricula, "R") == 0) return;

    struct Persona *aux = ptrFrente;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->ptrAlum != NULL && strcmp(aux->ptrAlum->matricula, matricula) == 0) {
            imprimirAlumnoCompleto(aux);
            encontrado = 1;
            break; 
        }
        aux = aux->ptrSig;
    }

    if (!encontrado) {
        printf("\nAlumno no encontrado.\n");
    }
}
