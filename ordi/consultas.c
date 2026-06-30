#include <stdio.h>
#include <string.h>
#include "consultas.h"
#include "menu.h"

//Revisamos si la lista esta vacia
void menuConsultas(struct Persona *ptrFrente) {
    if (ptrFrente == NULL) {
        printf("No hay ningun usuario registrado en el sistema aun \n");
        return;
    }
}

// Funcion para imprimir calificaciones y materias
void imprimirMateriasUCalificaciones(struct Alumno *alumno) {
    printf("Materias y calificaciones\n");
    for (int i = 0; i < 5; i++) {
        float sumaMateria = 0.0;
        printf("\nMateria %d:\n", i + 1);
        
        // Recorre 3 vueltas para los parciales
        for (int j = 0; j < 3; j++) {
            printf("  Parcial %d  : %.2f\n", j + 1, alumno->calif[i][j]);
            sumaMateria += alumno->calif[i][j];
        }
        
        // La columna del índice 3 es el ordinario
        printf("  Ordinario  : %.2f\n", alumno->calif[i][3]);
        sumaMateria += alumno->calif[i][3];
        
        // El promedio se divide entre 4, 3 parciales + 1 ordinario
        float promedio = sumaMateria / 4.0;
        printf("  Promedio   : %.2f\n", promedio);
    }
}

// Función para imprimir todo el perfil del nodo
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
        printf("Sin datos \n");
    }
}

// 1. Mostrar toda la lista
void mostrarTodaLaLista(struct Persona *ptrFrente) {
    struct Persona *aux = ptrFrente;
    int contador = 1;

    printf("Usuarios registrados \n");
    while (aux != NULL) {
        printf("\n[%d] PERSONA:  Nombre: %s | Edad: %d | Genero: %c\n", 
               contador++, aux->nombre, aux->edad, aux->genero);
        
        if (aux->ptrAlum != NULL) {
            printf("ALUMNO:  Matricula: %s | Carrera: %s | Semestre: %d\n",
                   aux->ptrAlum->matricula, aux->ptrAlum->carrera, aux->ptrAlum->semestre);
        } else {
            printf("No hay datos \n");
        }
        aux = aux->ptrSig;
    }
}

// 2. Filtrar por carrera con opción de regresar 
void mostrarPorCarrera(struct Persona *ptrFrente) {
    char carrera[5];
    printf("Ingrese la carrera a buscar (o escriba 'r' para regresar): ");
    scanf(" %4s", carrera);

    if (strcmp(carrera, "r") == 0 || strcmp(carrera, "R") == 0) {
        printf("Consulta cancelada.\n");
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
        printf("No hay alumnos en esa carrera \n");
    }
}

/* 3. Filtrar por Semestre con opción de regresar */
void mostrarPorSemestre(struct Persona *ptrFrente) {
    int semestre;
    printf("Ingrese el semestre a buscar o ingrese 0 para regresar: ");
    scanf("%d", &semestre);

    if (semestre == 0) {
        printf("Consulta cancelada \n");
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
        printf("No hay alumnos en ese semestre \n");
    }
}

// 4. Filtrar por carrera y semestre con opción de regresar
void mostrarPorCarreraSemestre(struct Persona *ptrFrente) {
    char carrera[5];
    int semestre;

    printf("Ingrese la carrera a buscar o 'r' para regresar: \n");
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
        printf("No hay alumnos con esos datos\n");
    }
}

// 5. Buscar a personas por nombre con opción de regresar
void buscarPorNombre(struct Persona *ptrFrente) {
    char nombre[50];
    printf("Ingrese el nombre completo a buscar o 'r' para regresar: ");
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
        printf("No se encontro el alumno \n");
    }
}

// 6. Buscar Alumno por Matrícula con opción de regresar 
void buscarPorMatricula(struct Persona *ptrFrente) {
    char matricula[10];
    printf("Ingrese la matricula del alumno o 'r' para regresar: ");
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
        printf("Alumno no encontrado \n");
    }
}
