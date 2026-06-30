#ifndef ALTAS_H
#define ALTAS_H

#include "struct.h"

/* Homologado a minúsculas y recibiendo ambos punteros para la Cola (FIFO) */
int altas(struct Persona **ptrFrente, struct Persona **ptrFinal);
struct Persona* nuevaPersona(void);
struct Alumno* nuevoAlumno(void);

#endif