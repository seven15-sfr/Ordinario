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
    int opc; 
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
                menuConsultas(ptrFrente);
                do{
                opc = mostar(); 
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
                        printf("Regresando al menu principal \n");
                        break;
                    default: 
                        printf("Opcion de consulta no valida \n"); 
                        break;
                } 
            }while(opc != 7);
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
