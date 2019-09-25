#pragma once
#include "Rectangulo.h"
#include "bala.h"
#include "Listas.h"
class Nave : public Rectangulo
{//ARREGLO DE BALAS
private:
	Lista<bala*>*arreglo;
public:
	Nave();
	~Nave();

	void Mover_Arriba(System::Drawing::Graphics ^espacio);
	void Mover_Abajo(System::Drawing::Graphics ^espacio);
	void Mover_Izquierda(System::Drawing::Graphics ^espacio);
	void Mover_Derecha(System::Drawing::Graphics ^espacio);
	void Disparar(System::Drawing::Graphics ^espacio);
	void Mostrar(System::Drawing::Graphics ^espacio,
		System::Drawing::Bitmap^ bmp);

	int devolver_cant_elementos();
	Lista<bala*>* devolver_arr_balas();
	void Mover_Balas(System::Drawing::Graphics ^espacio);
};

