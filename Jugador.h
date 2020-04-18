/*
  Archivo: Jugador.h
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
    Clase Jugador

    Relación: conoce Lugares(es propietario) usando un vector de punteros a Lugar

    Utilidad: 

    Atributos: 
          
*/

#ifndef HH_JUGADOR
#define HH_JUGADOR

#include "Lugar.h"
#include "Barca.h"
#include "Orilla.h"
#include <vector>
#include <iostream>

using namespace std;

class Jugador
{
	protected:
		vector <Lugar *> losLugares;
		Orilla *laOrillaIzquierda;
		Orilla *laOrillaDerecha;
		int cantidadMaxIndividuos;
		Barca *barcaFantasma;
		int aux = 0; //variable auxiliar que sirve para realizar modificaciones una sola vez
		Barca *laBarca;
	
	public:
		/**
		 * Constructor 
		*/
		Jugador(Barca *unaBarca, Orilla *orillaIzquierda, Orilla *orillaDerecha);

		/**
		 * Destructor
		*/
		virtual ~Jugador();

		/**
		 * 
		*/
		virtual void Jugar();

		/**
		 * agregarLugar adiciona un objeto Lugar al vector losLugares
		*/
		virtual void agregarLugar(Lugar *unLugar);

		/**
		 * comprobarEstadoDeJuego verifica si se ha perdido o ganado y retorna true o false            * respectivamente
		*/
		virtual bool comprobarEstadoDeJuego();

		/**
		 * organizarTexto muestra en pantalla una string dada con una cantidad de espacios en blanco   * que depende del tamanyo que debe ocupar la string
		*/
		virtual void organizarTexto(string textoParaMostrar, int tamanyoAOcupar);

		/**
		 * completarEspacios muestra en pantalla espacios en blanco 
		*/
		virtual void completarEspacios();

		/**
		 * mostrarIndividuosDelLugar muestra en pantalla de manera organizada los individuos de cada 
		 * lugar del vector losLugares
		*/
		virtual void mostrarIndividuosDelLugar(Lugar *unLugar, int indice);	

		/**
		 * recibirEntrada recibe una string por medio de getline y cin la cual actua como orden para 
		 * mover un Individuo
		*/
		virtual void recibirEntrada();

		/**
		 * mostrarJuego muestra en pantalla todos los elementos del juego de manera organizada por
		 * medio de cout
		*/	
		virtual void mostrarJuego();

};
#else
class Jugador;
#endif