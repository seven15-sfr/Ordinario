#include <stdio.h>
#include <string.h>
#include "submenu.h"
#include "menu.h"

void ejecutarSubmenu(struct Persona *ptrFrente) {
    if (ptrFrente == NULL) {
        printf("La base de datos esta vacia \n");
        return;
    }  
}

/* Registrar calificaciones con opción de regresar */
void registrarCalificaciones(struct Persona *ptrFrente) {
    char matBuscar[10];
    printf("Ingrese la matricula del alumno para asignar calificaciones: ");
    scanf(" %s", matBuscar);

    struct Persona *ptrActual = ptrFrente;
    int encontrado = 0;

    while (ptrActual != NULL) {
        if (ptrActual->ptrAlum != NULL && strcmp(ptrActual->ptrAlum->matricula, matBuscar) == 0) {
            encontrado = 1;
            
            // INTERFAZ DE CONFIRMACIÓN / REGRESAR
            char opRegresar;
            printf("Registro encontrado\n");
            printf("Alumno: %s\n", ptrActual->nombre);
            printf("¿Desea continuar con el registro de calificaciones o prefiere regresar?  C = Continuar / R = Regresa): ");
            scanf(" %c", &opRegresar);

            if (opRegresar == 'r' || opRegresar == 'R') {
                printf("Operacion cancelada. Regresando \n");
                return; // Salimos de la función y volemos al submenú
            }

            printf("Registrando matriz de calificaciones :\n");
            for (int i = 0; i < 5; i++) {
                printf("  -> Materia %d:\n", i + 1);
                for (int j = 0; j < 5; j++) {
                    printf("     Unidad %d: ", j + 1);
                    scanf("%f", &ptrActual->ptrAlum->calif[i][j]);
                }
            }
            printf("Matriz de calificaciones guardada exitosamente \n");
            break;
        }
        ptrActual = ptrActual->ptrSig;
    }

    if (!encontrado) {
        printf("No se encontro ningun alumno con la matricula: %s\n", matBuscar);
    }
}

/* Modificar datos con opción de regresar */
void modificarDatosAlumno(struct Persona *ptrFrente) {
    char matBuscar[10];
    printf("Ingrese la matricula del alumno a modificar: ");
    scanf(" %s", matBuscar);

    struct Persona *ptrActual = ptrFrente;
    int encontrado = 0;

    while (ptrActual != NULL) {
        if (ptrActual->ptrAlum != NULL && strcmp(ptrActual->ptrAlum->matricula, matBuscar) == 0) {
            encontrado = 1;
            
            // Interfazas de confirmacion
            char opRegresar;
            printf("Registro encontrado \n");
            printf("Alumno: %s\n", ptrActual->nombre);
            printf("¿Desea proceder con la modificacion o prefiere regresar? (m = Modificar   r = Regresar): ");
            scanf(" %c", &opRegresar);

            if (opRegresar == 'r' || opRegresar == 'R') {
                printf("Operacion cancelada \n");
                return; // Salimos de la función inmediatamente y vuelve al submenú */
            }

            int opcionMod;
            printf("1. Cambiar semestre (Actual: %d)\n", ptrActual->ptrAlum->semestre);
            printf("2. Cambiar correo (Actual: %s)\n", ptrActual->ptrAlum->correo);
            printf("Seleccione que dato desea modificar: ");
            scanf("%d", &opcionMod);

            if (opcionMod == 1) {
                printf("Nuevo semestre: ");
                scanf("%d", &ptrActual->ptrAlum->semestre);
                printf("Semestre actualizado.\n");
            } else if (opcionMod == 2) {
                printf("Nuevo correo: ");
                scanf(" %s", ptrActual->ptrAlum->correo);
                printf("Correo actualizado.\n");
            } else {
                printf("Opcion no valida.\n");
            }
            break;
        }
        ptrActual = ptrActual->ptrSig;
    }

    if (!encontrado) {
        printf("No se encontro ningun alumno con la matricula: %s\n", matBuscar);
    }
}
