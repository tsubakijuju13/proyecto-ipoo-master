/*
  Archivo: main.cpp
  Autores: 
        -Daniel Felipe Vélez Cuaical - 1924306
        -Santiago Ramirez Ospina - 1841391
        -Julián Andrés Orejuela Erazo - 1541304

  Emails: 
        daniel.cuaical@correounivalle.edu.co
        santiago.ramirez.ospina@correounivalle.edu.co
        orejuela.julian@correounivalle.edu.co
    
  Fecha creación: marzo-31-2020
  Fecha última modificación: abril-17-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Jugador.h"
#include "Individuo.h"
#include "Lugar.h"
#include "Barca.h"
#include "Orilla.h"

int main()
{
    Individuo *robot = new Individuo("Robot", 0);
    Individuo *zorro = new Individuo("Zorro", 1);
    Individuo *conejo = new Individuo("Conejo", 2);
    Individuo *lechuga = new Individuo("Lechuga", 3);

    vector <Individuo *> individuos = {robot, zorro, conejo, lechuga};

    Orilla *orillaIzquierda;
    Orilla *orillaDerecha;

    Barca barca("BARCA", orillaIzquierda, robot, 3);
    orillaIzquierda = new Orilla("IZQUIERDA", &barca, robot);
    orillaDerecha = new Orilla("DERECHA", nullptr, robot);
      
    barca.agregarVecinos(orillaIzquierda, orillaDerecha);

    zorro->agregarIndividuoParaComer(conejo);
    conejo->agregarIndividuoParaComer(lechuga);

    orillaIzquierda->agregarIndividuos(individuos);

    Jugador nuevoJugador(&barca, orillaIzquierda, orillaDerecha);
    
    do
    {
        nuevoJugador.Jugar();
        
    }while(nuevoJugador.comprobarEstadoDeJuego());
    

    return 0;
}
