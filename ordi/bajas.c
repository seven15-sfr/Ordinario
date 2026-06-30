#include <stdio.h>
#include <stdlib.h>
#include "bajas.h"

void bajas(struct Persona **ptrFrente, struct Persona **ptrFinal) {
    if (*ptrFrente == NULL) {
        printf("No hay registros para dar de baja (Cola vacia).\n");
        return;
    }

    struct Persona *ptrAuxiliar = *ptrFrente;
    *ptrFrente = (*ptrFrente)->ptrSig;

    if (*ptrFrente == NULL) {
        *ptrFinal = NULL;
    }

    if (ptrAuxiliar->ptrAlum != NULL) {
        free(ptrAuxiliar->ptrAlum); 
    }
    free(ptrAuxiliar->nombre);      
    free(ptrAuxiliar);              

    printf("\nPrimer registro de la cola eliminado exitosamente.\n");
}

void vaciarCola(struct Persona **ptrFrente, struct Persona **ptrFinal) {
    while (*ptrFrente != NULL) {
        bajas(ptrFrente, ptrFinal);
    }
}