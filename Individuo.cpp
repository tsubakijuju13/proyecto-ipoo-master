/*
  Archivo: Individuo.cpp
  Autores: 
        -Daniel Felipe Vélez Cuaical
        -Santiago Ramirez Ospina
        -Julián Andrés Orejuela Erazo
    
  Fecha creación: abril-04-2020
  Fecha última modificación: abril-17-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Individuo.h"

Individuo::Individuo(std::string _nombre, int _posicion) : nombre(_nombre), posicion(_posicion)
{
}

Individuo::~Individuo()
{
    /* No hace nada */
}

std::string Individuo::mostrarNombre()
{
    return nombre;
}

void Individuo::agregarIndividuoParaComer(Individuo *unIndividuo)
{
    individuosParaComer.push_back(unIndividuo);
}

bool Individuo::comerIndividuo(Individuo *unIndividuo)
{
    bool auxiliar=false;
    for (int i = 0; i < individuosParaComer.size(); i++)
    {
        if(unIndividuo == individuosParaComer[i]) 
            auxiliar = true; 
            break;
    }
    return auxiliar;
}

int Individuo::mostrarPosicion()
{
    return posicion;
}