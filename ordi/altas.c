#include <stdio.h>
#include <stdlib.h>
#include "altas.h"

int altas(struct Persona **ptrFrente, struct Persona **ptrFinal)
{
    struct Persona *P = NULL;
    struct Alumno *A = NULL;
    int b = 1; // Bandera

    P = nuevaPersona();

    if(P == NULL){
        b = 0;
    }else{
        A = nuevoAlumno();
        if(A == NULL){
            b = 0;
            free(P->nombre); // Liberamos el nombre dinámico primero
            free(P);
        } else {
            P->ptrAlum = A;
            P->ptrSig = NULL; // Al ser el último, su siguiente es NULL

           
            if(*ptrFinal == NULL) {
                *ptrFrente = P; // Si está vacía, el frente es el nuevo nodo
            } else {
                (*ptrFinal)->ptrSig = P; // El último actual apunta al nuevo
            }
            *ptrFinal = P; // El nuevo nodo ahora es el final de la cola
        }
    }
    return b;
}

struct Persona* nuevaPersona(void)
{
    struct Persona *P = (struct Persona*)malloc(sizeof(struct Persona));
    if (P == NULL) return NULL;

    P->nombre = (char*)malloc(50 * sizeof(char));
    if (P->nombre == NULL) { free(P); return NULL; }

    printf("Nombre: ");
    scanf(" %[^\n]", P->nombre); // %[^\n] permite capturar nombres con espacios
    printf("Edad: ");
    scanf("%d", &P->edad);
    printf("Genero M o F: ");
    scanf(" %c", &P->genero);
    printf("Fecha de nacimiento (DD-MM-AAAA): ");
    scanf(" %s", P->fn);

    P->ptrAlum = NULL;
    P->ptrSig  = NULL;

    return P;
}

struct Alumno* nuevoAlumno(void)
{
    struct Alumno *A = (struct Alumno*)malloc(sizeof(struct Alumno));
    if (A == NULL) return NULL;

    printf("Matricula: ");
    scanf(" %s", A->matricula);
    printf("Carrera: ");
    scanf(" %s", A->carrera);
    printf("Semestre: ");
    scanf("%d", &A->semestre);
    printf("Correo: ");
    scanf(" %s", A->correo);

    return A;
}
