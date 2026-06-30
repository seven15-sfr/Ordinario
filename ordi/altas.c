#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>  
#include "altas.h"

int altas(struct Persona **ptrFrente, struct Persona **ptrFinal, const char *carreraElegida)
{
    struct Persona *P = NULL;
    struct Alumno *A = NULL;
    int b = 1; // Bandera

    P = nuevaPersona();

    if(P == NULL){
        b = 0;
    }else{
        // Pasamos tanto el nombre como la carrera ya procesada
        A = nuevoAlumno(P->nombre, carreraElegida); 
        if(A == NULL){
            b = 0;
            free(P->nombre); 
            free(P);
        } else {
            P->ptrAlum = A;
            P->ptrSig = NULL; 

            if(*ptrFinal == NULL) {
                *ptrFrente = P; 
            } else {
                (*ptrFinal)->ptrSig = P; 
            }
            *ptrFinal = P; 
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
    scanf(" %[^\n]", P->nombre); 
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

struct Alumno* nuevoAlumno(const char *nombrePersona, const char *carreraElegida)
{
    struct Alumno *A = (struct Alumno*)malloc(sizeof(struct Alumno));
    if (A == NULL) return NULL;

    printf("Matricula: ");
    scanf(" %s", A->matricula);

    // Copiamos directamente la carrera que se determinó en el main
    strcpy(A->carrera, carreraElegida);
    printf("Carrera asignada: %s\n", A->carrera);

    printf("Semestre: ");
    scanf("%d", &A->semestre);

    char dosLetras[3] = {0}; 
    strncpy(dosLetras, nombrePersona, 2);
    
    dosLetras[0] = tolower((unsigned char)dosLetras[0]);
    dosLetras[1] = tolower((unsigned char)dosLetras[1]);

    sprintf(A->correo, "%s%s@unsij.edu.mx", dosLetras, A->matricula);
    
    printf("Correo institucional asignado: %s\n", A->correo);

    return A;
}
