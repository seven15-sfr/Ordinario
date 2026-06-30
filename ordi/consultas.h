#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "struct.h"

void ejecutarConsultas(struct Persona *ptrFrente);
void imprimirMateriasUCalificaciones(struct Alumno *alumno);
void imprimirAlumnoCompleto(struct Persona *persona);
void mostrarTodaLaLista(struct Persona *ptrFrente);
void mostrarPorCarrera(struct Persona *ptrFrente);
void mostrarPorSemestre(struct Persona *ptrFrente);
void mostrarPorCarreraSemestre(struct Persona *ptrFrente);
void buscarPorNombre(struct Persona *ptrFrente);
void buscarPorMatricula(struct Persona *ptrFrente);

#endif