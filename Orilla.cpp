/*
  Archivo: Orilla.cpp
  Autores: 
        -Daniel Felipe Vélez Cuaical
        -Santiago Ramirez Ospina
    
  Fecha creación: abril-04-2020
  Fecha última modificación:  abril-10-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/
#include "Orilla.h"
#include  <iostream>

Orilla::Orilla(std::string _nombre, Lugar *unVecino, Individuo *elGuardian) : Lugar(_nombre, unVecino, elGuardian)
{  
}

Orilla::~Orilla()
{
    /* No hace nada */
}

void Orilla::moverBarca()
{
    /* No hace nada */
}