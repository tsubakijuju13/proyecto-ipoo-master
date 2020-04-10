/*
  Archivo: Barca.cpp
  Autores: 
        -Daniel Felipe Vélez Cuaical
        -Santiago Ramirez Ospina
    
  Fecha creación: abril-04-2020
  Fecha última modificación: abril-10-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Barca.h"
#include <iostream>

Barca::Barca(std::string _nombre, Lugar *unVecino, Individuo *_elGuardian, int laCapacidad) : Lugar(_nombre, unVecino, _elGuardian)
{
  capacidad = laCapacidad;
}

Barca::~Barca()
{
    /*No hace nada*/
}

void Barca::agregarVecinos(Lugar *unVecino, Lugar *otroVecino)
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