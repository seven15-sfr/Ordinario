#include <stdio.h>
#include <stdlib.h>
#include "bajas.h"

void bajas(struct Persona **ptrFrente, struct Persona **ptrFinal) {
    char respuesta;

    do {
        if (*ptrFrente == NULL) {
            printf("No hay registros para dar de baja \n");
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

        printf("Eliminado exitosamente \n");

        // Preguntamos si desea eliminar otro usuario 
        printf("\n¿Desea eliminar a otro usuario? (s/n): ");
        scanf(" %c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');// Para no tener error tambien metemos mayuscula
}

void vaciarCola(struct Persona **ptrFrente, struct Persona **ptrFinal) {
    while (*ptrFrente != NULL) {
        // Para vaciar la cola en la salida
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
    }
    printf("Lista vaciada \n");

}
