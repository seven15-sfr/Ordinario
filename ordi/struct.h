#ifndef STRUCTS_H
#define STRUCTS_H


struct Alumno{
    char matricula[10];
    char carrera[5];    //mas punto si es con apuntadores
    int semestre;
    char correo[23];    //agrgar fin de cadena para poder imprimir todo
    float calif[5][5];
};

struct Persona{
    char *nombre;
    int edad;
    char genero;
    char fn[8];     //fecha de nacimiento
    struct Persona *ptrSig;
    struct Alumno *ptrAlum; //para encadenar
};

#endif