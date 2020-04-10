/*
  Archivo: Jugador.cpp
  Autores: 
        -Daniel Felipe Vélez Cuaical
        -Santiago Ramirez Ospina
    
  Fecha creación: abril-04-2020
  Fecha última modificación: abril-10-2020
  Versión: 0.1
  Licencia: GPL v3.0
*/

#include "Jugador.h"

Jugador::Jugador(Barca *unaBarca, Orilla *orillaIzquierda, Orilla *orillaDerecha) : laBarca(unaBarca), laOrillaIzquierda(orillaIzquierda), laOrillaDerecha(orillaDerecha) 
{
    losLugares.push_back(laOrillaIzquierda);
    losLugares.push_back(laBarca);
}

Jugador::~Jugador()
{
    /* No hace nada */
}

bool Jugador::comprobarEstadoDeJuego()
{
    bool auxiliar = true;
    
    for (int i = 0; i < losLugares.size(); i++)
    {
        if(losLugares[i]->comprobarSobrevivientes()) 
        {
            cout << " ¡¡HAS PERDIDO!!" << endl;
            return false;
        }
    }
    return auxiliar;
}

void Jugador::agregarLugar(Lugar* unLugar)
{
    losLugares.push_back(unLugar);
    losLugares[1] = laBarca;
}

void Jugador::Jugar()
{
    //Esto solo tiene que hacerse una vez (al inicio del juego).
    if (aux == 0)
    {
        barcaFantasma = new Barca("", laOrillaDerecha, new Individuo("nadie",-1), -1);
        losLugares.push_back(barcaFantasma);
        losLugares.push_back(laOrillaDerecha);
        cantidadMaxIndividuos = losLugares[0]->mostrarCantidadIndividuos();
        aux += 1;
    }

    for (int i = 0; i < losLugares.size(); i++)
    {
        if(losLugares[i]->mostrarCantidadIndividuos() == 0)
        {
            losLugares[i]->agregarIndividuosFantasma(cantidadMaxIndividuos);
        }
    }

    mostrarJuego();
    recibirEntrada();
}

void Jugador::mostrarJuego()
{
    cout << "| ";
    //Se muestran los Lugares
    for (int i = 0; i < losLugares.size(); i++)
    {
        if(losLugares[i]->mostrarNombre().size() < 14)
        {
            organizarTexto(losLugares[i]->mostrarNombre(), losLugares[i]->mostrarNombre().size());
            cout << "| ";
        }
    }
    cout << endl;
    //Se muestran los Individuos de cada lugar
    for (int i = 0; i < cantidadMaxIndividuos; i++)
    {
        mostrarIndividuosDelLugar(losLugares[0], i);   
        mostrarIndividuosDelLugar(losLugares[1], i);
        mostrarIndividuosDelLugar(losLugares[2], i);
        mostrarIndividuosDelLugar(losLugares[3], i);
        cout << "|" << endl;
    }
}

void Jugador::recibirEntrada()
{
    string orden="";
    cout << "Ingrese una orden: ";
    getline(cin, orden);
    cout<<endl;
    
    if(orden == "B" and laBarca->comprobarGuardian())
    {    
        if (laBarca->mostrarVecino() == "IZQUIERDA")
        {
            laBarca->moverBarca();
            losLugares[1] = barcaFantasma;
            losLugares[2] = laBarca;
        }
        else if(laBarca->mostrarVecino() == "DERECHA")
        {
            laBarca->moverBarca();
            losLugares[1] = laBarca;
            losLugares[2] = barcaFantasma;
        }
    }
    else
    {
        for (int i = 0; i < losLugares.size(); i++)
        {
            if(losLugares[i]->buscarLetra(orden))
            {
                losLugares[i]->cambiarIndividuo();
                break;
            }     
        }
    }
}

void Jugador::organizarTexto(string textoParaMostrar, int tamanyoAOcupar)
{
    int auxiliar = 14 - tamanyoAOcupar;
    cout << textoParaMostrar;
    for (int i = 0; i < auxiliar; i++)
        cout << " ";
}

void Jugador::completarEspacios()
{
    for (int i = 0; i < 14; i++)
        cout <<" ";
    cout << " | ";
}

void Jugador::mostrarIndividuosDelLugar(Lugar *unLugar, int indice)
{
    if(unLugar->mostrarCantidadIndividuos() != 0)
    {
        cout << "| ";
        organizarTexto(unLugar->mostrarUnIndividuo(indice), unLugar->mostrarUnIndividuo(indice).size());
    }
    else completarEspacios();
}