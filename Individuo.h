/*
  Archivo: Individuo.h
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
    Clase Individuo

    Relación: conoce Individuos usando un vector de punteros a Individuo

    Utilidad: 

    Atributos: 
          
*/

#ifndef HH_INDIVIDUO
#define HH_INDIVIDUO

#include <vector>
#include <string>

class Individuo
{
    protected:
        std::string nombre;
        std::vector <Individuo *> individuosParaComer;
        int posicion;

    public:
        /**
         * Constructor
        */
        Individuo(std::string _nombre, int _posicion);
        
        /**
         * Destructor 
        */
        virtual ~Individuo();

        /**
         * mostrarNombre retorna un string del nombre del individuo
        */
        virtual std::string mostrarNombre();

        /**
         * mostrarPosicion retorna un numero entero que es la posicion del individuo
        */
        virtual int mostrarPosicion();

        /**
         * agregarIndividuoParaComer agrega un individuo dado al vector individuosParaComer del        * individuo
        */
        virtual void agregarIndividuoParaComer(Individuo *unIndividuo);

        /**
         * comerIndividuo retorna true si el individuo come a un individuo del vector                  * individuosParaComer y retorna false en caso contrario
        */
        virtual bool comerIndividuo(Individuo *unIndividuo);

};
#else
class Individuo;
#endif