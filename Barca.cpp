/*
  Archivo: Barca.cpp
  Autores: 
        -Daniel Felipe Vélez Cuaical
        -Santiago Ramirez Ospina
        -Julián Andrés Orejuela Erazo
    
  Fecha creación: abril-04-2020
  Fecha última modificación: abril-17-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Barca.h"

Barca::Barca(std::string _nombre, Orilla *unVecino, Individuo *_elGuardian, int laCapacidad) : Lugar(_nombre, unVecino, _elGuardian)
{
  capacidad = laCapacidad;
}

Barca::~Barca()
{
    /*No hace nada*/
}

void Barca::agregarVecinos(Orilla *unVecino, Orilla *otroVecino)
{
    laOrillaIzquierda = unVecino;
    laOrillaDerecha = otroVecino;
    vecino = laOrillaIzquierda;
}

void Barca::moverBarca()
{
	if(vecino == laOrillaIzquierda)
  	{
    	vecino = laOrillaDerecha;
  	}
  	else
	{
		vecino = laOrillaIzquierda;
	}
}

bool Barca::comprobarGuardian()
{
	for (int i = 0; i < losIndividuos.size(); i++)
	{
		if(losIndividuos[i] == guardian) return true;
	}
	return false;
}