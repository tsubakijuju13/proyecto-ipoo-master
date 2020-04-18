/*
  Archivo: Lugar.h
  Autores: 
        -Daniel Felipe Vélez Cuaical
        -Santiago Ramirez Ospina
        -Julián Andrés Orejuela Erazo
    
  Fecha creación: marzo-31-2020
  Fecha última modificación: abril-17-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

/*
    Clase Lugar

    Relaciones: 
        -posee Individuos (es propietario) usando un vector de punteros a Individuos
        -conoce un Lugar 

    Utilidad: 

    Atributos: 
          
*/

#ifndef HH_LUGAR
#define HH_LUGAR

#include "Individuo.h"
#include <vector>
#include <string>

using namespace std;

class Lugar
{
    protected:
        string nombre;
        vector <Individuo *> losIndividuos;
        string posicion;
        Lugar *vecino;
        Individuo *guardian;
        Individuo *individuoParaMover;

    public:
        /**
         * Constructor
        */
        Lugar(string _nombre, Lugar *unVecino, Individuo *guardian);

        /**
         * Destructor
        */
        virtual ~Lugar();

        /**
         * comprobarSobrevivientes retorna true si un individuo ha sido devorado y false en caso        * contrario.
        */
        virtual bool comprobarSobrevivientes();

        /**
         * agregarIndividuos anexa los individuos de un vector dado al vector losIndividuos del Lugar
        */
        virtual void agregarIndividuos(vector <Individuo *> individuos);

        /**
         * mostrarUnIndividuo retorna el nombre del individuo en la posicion i del vector losIndividuos
        */
        virtual string mostrarUnIndividuo(int _i);

        /**
         * mostrarCantidadIndividuos retorna la cantidad de individuos del vector losIndividuos
        */
        virtual int mostrarCantidadIndividuos();

        /**
         * mostrarNombre retorna un string con el nombre del Lugar actual
        */
        virtual string mostrarNombre();

        /**
         * buscarLetra retorna true si la letra ingresada es la inicial del nombre de un individuo del * vector losIndividuos
        */
        virtual bool buscarLetra(string unaLetra);

        /**
         * cambiarIndividuo reemplaza el individuo que se va a cambiar con el vecino
        */
        virtual void cambiarIndividuo();

        /**
         * reemplazarUnIndividuo reemplaza el individuo de una posicion ingresada por otro individuo   * dado
        */
        virtual void reemplazarUnIndividuo(Individuo *unIndividuo, int posicion);

        /**
         * agregarIndividuosFantasma llena el vector losIndividuos del lugar en caso de que se          * encuentre vacio
        */
        virtual void agregarIndividuosFantasma(int cantidad);

        /**
         * mostrarVecino retorna un string con el nombre del vecino del Lugar
        */
        virtual string mostrarVecino();

        /**
         * retornarIndividuo retorna la dirección en memoria del individuo en la posicion i del vector
        */
        virtual Individuo* retornarIndividuo(int i);

        /**
         * moverBarca es una funcion virtual pura para mover la barca
        */
        virtual void moverBarca()=0;

        /**
         * comprobarVictoria retorna true en caso de que el vector de Individuos del Lugar sea igual a * uno dado
        */
        virtual bool comprobarVictoria(vector <Individuo *> unosIndividuos);

};
#else
class Lugar;
#endif