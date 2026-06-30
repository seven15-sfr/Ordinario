#ifndef ALTAS_H
#define ALTAS_H

#include "struct.h"

int altas(struct Persona **ptrFrente, struct Persona **ptrFinal, const char *carreraElegida);
struct Persona* nuevaPersona(void);
struct Alumno* nuevoAlumno(const char *nombrePersona, const char *carreraElegida); 

#endif
