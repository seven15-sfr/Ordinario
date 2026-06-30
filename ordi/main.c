#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "menu.h"
#include "altas.h"
#include "bajas.h"
#include "consultas.h"
#include "submenu.h"

int main(void){
    int op;
    int opc; 
    int opSub;
    struct Persona *ptrFrente = NULL;
    struct Persona *ptrFinal = NULL;

    do {
        op = menuPrincipal(); 
        switch (op) {
            case 1: {
                char carreraSeleccionada[5] = "S/C"; 
                int opCarrera = menuCarreras(); // Llamamos al menú de carreras
                
                switch(opCarrera) {
                    case 1:
                        strcpy(carreraSeleccionada, "IDSSI"); // Ing. en Desarrollo de Software
                        break;
                    case 2:
                        strcpy(carreraSeleccionada, "IF");  // Ing. Forestal
                        break;
                    case 3:
                        strcpy(carreraSeleccionada, "LAT"); // Lic. en Administración Turística
                        break;
                    case 4:
                        strcpy(carreraSeleccionada, "LCA"); // Lic. en Ciencias Ambientales
                        break;
                    case 5:
                        strcpy(carreraSeleccionada, "LB");  // Lic. en Biología
                        break;
                    default:
                        printf("Opcion no valida \n");
                        strcpy(carreraSeleccionada, "S/C");
                        break;
                }
                
                // Pasamos la carrera seleccionada a la función altas
                altas(&ptrFrente, &ptrFinal, carreraSeleccionada);
                break;
            }
                
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
                } while(opc != 7);
                break;

            case 4:
                ejecutarSubmenu(ptrFrente);
                do {
                    opSub = submenu(); 
                    switch (opSub) {
                        case 1:
                            modificarDatosAlumno(ptrFrente);
                            break;
                        case 2:
                            registrarCalificaciones(ptrFrente);
                            break;
                        case 3:
                            printf("Regresando al menu principal \n");
                            break;
                        default:
                            printf("Opcion no valida \n");
                            break;
                    }
                } while (opSub != 3); 
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
