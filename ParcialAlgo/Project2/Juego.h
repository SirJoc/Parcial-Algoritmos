#pragma once
#include "Figura.h"
#include "Nave.h"
#include "Pilas.h"
#include "Listas.h"
#include "Asteroide.h"
#include <fstream>
#include <string>

public enum direccion { izquierda, derecha, arriba, abajo };
class Juego
{
	char auxX, auxY;
	FILE* Archivo;
	std::fstream  mArchivo;
	Figura **arreglo;
	Nave* objNave;
	MyStack<Asteroide*> *Pl;
	Lista<Asteroide*> *Lst;
	int cant_asteroides_delete;
	int x = 0;
	int y = 0;
	long long puntuacion;
	Pila<int>* vidas;
public:
	Juego();
	~Juego();
	void Volver_Inicio();
	void Insertar_Figura(int TipoAsteroid);
	void Mover_Figuras(System::Drawing::Graphics ^espacio);
	void Mover_Nave(System::Drawing::Graphics ^espacio, direccion movimiento);
	void Mostrar_Nave(System::Drawing::Graphics ^espacio, System::Drawing::Bitmap^ bmp);
	void Mostrar_Figuras(System::Drawing::Graphics ^espacio, System::Drawing::Bitmap^ bmp1, System::Drawing::Bitmap^ bmp2);
	bool Colision_Nave_Figura();
	void Colision_Bala_Figura();
	void Disparar(System::Drawing::Graphics ^espacio);
	void Mover_Balas(System::Drawing::Graphics ^espacio);
	int get_cant_delete();
	void eliminar_Asteroides();
	void set_y(int nuevo);
	int get_y();
	void set_x(int nuevo);
	int get_x();
	void Mostrar_Portada(System::Drawing::Graphics ^espacio, System::Drawing::Bitmap ^bmp);
	void Mostrar_Mapa(System::Drawing::Graphics ^espacio, System::Drawing::Bitmap ^bmp);
	void set_puntuacion(int nuevo);
	int get_puntuacion();
	void set_vidas(int nuevo);
	int get_vidas();
	void Guardar_Partida();

	void Cargar_Partida();

};
