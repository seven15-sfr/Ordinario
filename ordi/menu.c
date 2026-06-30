#include <stdio.h>
#include "menu.h"

int menuPrincipal(void) {
    int op;
    printf("-        MENU \n");
    printf("1. Crear datos de un nuevo usuario \n");
    printf("2. Bajas de usuarios \n");
    printf("3. Mostar \n");
    printf("4. Sub-Menu Especial \n");
    printf("5. Salir \n");
    scanf("%d", &op);
    return op;
}

int mostar(void) {
    int opc;
    printf("-  Seleccione una opcion \n");
    printf("1. Mostar toda la lista \n");
    printf("2. Mostar alumnos de la carrera \n");
    printf("3. Mostar alumnos del semestre \n");
    printf("4. Mostar carrera y semestre \n");
    printf("5. Buscar a persona por nombre \n");
    printf("6. Buscar alumno por numero de matricula \n");
    printf("7. Regresar \n");
    scanf("%d", &opc);
    return opc;
}

int submenu(void) {
    int sub;
    printf("-       FC-ESPECIALES \n");
    printf("-  Seleccione una opcion: \n");
    printf("1. Modificaciones \n");
    printf("2. Calificaciones \n");
    printf("3. Regresar al menu principal \n");
    scanf("%d", &sub);
    return sub;
}

int menuCarreras(void) {
    int opcion;
    printf("-    SELECCIONE LA CARRERA \n");
    printf("1: Ingenieria en desarrollo de software\n");
    printf("2: Ingenieria forestal\n");
    printf("3: Licenciatura en administracion turistica\n");
    printf("4: Licenciatura en ciencias ambientales\n");
    printf("5: Licenciatura en biologia\n");
    printf("Seleccione la carrera: ");
    scanf("%d", &opcion);
    return opcion;
}
