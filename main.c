#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "menu.h"
#include "altas.h"
#include "bajas.h"
#include "consultas.h"
#include "submenu.h"   

int main(void){
    int op;
    struct Persona *ptrFrente = NULL;
    struct Persona *ptrFinal = NULL;

    do {
        op = menuPrincipal(); 
        switch (op) {
            case 1:
                altas(&ptrFrente, &ptrFinal);
                break;
            case 2:
                bajas(&ptrFrente, &ptrFinal);
                break;
            case 3:
                ejecutarConsultas(ptrFrente); 
                break;
            case 4:
                ejecutarSubmenu(ptrFrente);
                break;
            case 5:
                vaciarCola(&ptrFrente, &ptrFinal);
                printf("Saliendo del sistema de calificaciones \n");
                break;
            default:
                printf("Seleccione una opcion valida \n");
                break;
        }
    } while (op != 5); 
      
    return 0;
}
