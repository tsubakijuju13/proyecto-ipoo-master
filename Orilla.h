/*
  Archivo: Orilla.h
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
    Clase Orilla

    Relación: Es un Lugar

    Utilidad: 

    Atributos: 
          
*/

#ifndef HH_ORILLA
#define HH_ORILLA

#include "Lugar.h"

class Orilla : public Lugar
{
    protected:
    
    public:
        /**
         * Constructor
        */
        Orilla(std::string _nombre, Lugar *unVecino, Individuo *elGuardian);

        /**
         * Destructor
        */
        virtual ~Orilla();

        /**
         * aun no estoy seguro, pero es necesario que este aqui porque en la clase Lugar esta definida como una funcion virtual pura
        */
        virtual void moverBarca();
};
#else 
class Orilla;
#endif