/*
  Archivo: Lugar.cpp
  Autores: 
        -Daniel Felipe Vélez Cuaical
        -Santiago Ramirez Ospina
        -Julián Andrés Orejuela Erazo
    
  Fecha creación: abril-04-2020
  Fecha última modificación: abril-17-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/
#include "Lugar.h"


Lugar::Lugar(string _nombre, Lugar *unVecino, Individuo *elGuardian) : nombre(_nombre), vecino(unVecino), guardian(elGuardian)
{
}

Lugar::~Lugar()
{
    for (int i = 0; i < losIndividuos.size(); i++)
    {
        delete losIndividuos[i];
        losIndividuos[i] = nullptr;
    }   
}

string Lugar::mostrarNombre()
{
    return nombre;
}

string Lugar::mostrarUnIndividuo(int _i)
{
    return losIndividuos[_i]->mostrarNombre();
}

int Lugar::mostrarCantidadIndividuos()
{
    return losIndividuos.size();
}

bool Lugar::comprobarSobrevivientes()
{
    //Aqui se comprueba que el Robot no esté en el Lugar en cuestion
    for (int i = 0; i < losIndividuos.size(); i++)
    {
        if(losIndividuos[i] == guardian)
        {
            return false;
        }
    }
    //Como el Robot no esta, se procede a comprobar que un individuo ha sido devorado
    for (int i = 0; i < losIndividuos.size(); i++)
    {
        for (int j = i+1; j <= losIndividuos.size()-1; j++)
        {
            if(losIndividuos[i]->comerIndividuo(losIndividuos[j])) return true;
        }
    }

    return false;
}

void Lugar::agregarIndividuos(vector <Individuo *> individuos)
{
    losIndividuos = individuos;
}

bool Lugar::buscarLetra(string unaLetra)
{
    for (int i = 0; i < losIndividuos.size(); i++)
    {
        if (losIndividuos[i]->mostrarNombre()[0] == unaLetra[0])
        {
            individuoParaMover = losIndividuos[i];
            return true;
        }
    }
    return false;
}

void Lugar::cambiarIndividuo()
{
    int posicion = individuoParaMover->mostrarPosicion();
    reemplazarUnIndividuo(vecino->retornarIndividuo(posicion), posicion);
    vecino->reemplazarUnIndividuo(individuoParaMover, posicion);
    individuoParaMover = nullptr;
}

void Lugar::reemplazarUnIndividuo(Individuo *unIndividuo, int posicion)
{
    losIndividuos[posicion] = unIndividuo;
}

void Lugar::agregarIndividuosFantasma(int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        losIndividuos.push_back(new Individuo(" ",i));
    }
}

Individuo* Lugar::retornarIndividuo(int i)
{
    return losIndividuos[i];
}

bool Lugar::comprobarVictoria(vector <Individuo *> unosIndividuos)
{
    if (losIndividuos == unosIndividuos)
    {
        return true;
    }
    return false;
}

string Lugar::mostrarVecino()
{
    return vecino->mostrarNombre();
}