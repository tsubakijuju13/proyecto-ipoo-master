/*
  Archivo: Barca.h
  Autores: 
        -Daniel Felipe Vélez Cuaical
        -Santiago Ramirez Ospina
    
  Fecha creación: marzo-31-2020
  Fecha última modificación: abril-10-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

/*
    Clase Barca

    Relaciones:
        -Es parecido a un Lugar
        -Conoce Orillas (no es propietario)

    Utilidad: 

    Atributos: 
          
*/

#ifndef HH_BARCA
#define HH_BARCA

#include "Lugar.h"
#include "Orilla.h"

class Barca : public Lugar
{
    protected:
        Orilla *laOrillaDerecha;
        Orilla *laOrillaIzquierda;
        int capacidad;
        
    public:
        /**
         * Constructor
        */
        Barca(std::string _nombre, Orilla *unVecino, Individuo *Guardian, int laCapacidad);

        /**
         * Destructor
        */
        virtual ~Barca();

        /**
         * agregarVecinos establece los Lugares vecinos que conoce la barca
        */
        virtual void agregarVecinos(Orilla *unVecino, Orilla *otroVecino);

        /**
         * moverBarca cambio el vecino actual de la Barca por el otro Lugar que conoce
        */
        virtual void moverBarca();

        /**
         * comprobarGuardian retorna true si el Guardian de la barca se encuentra en el vector         * losIndividuos, retorna false en caso contrario 
        */
        virtual bool comprobarGuardian();

};
#else
class Barca;
#endif