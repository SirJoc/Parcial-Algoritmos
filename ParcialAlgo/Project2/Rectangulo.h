#pragma once
#include "Figura.h"
class Rectangulo :	public Figura
{
protected:
	int largo, ancho;

public:
	Rectangulo();
	~Rectangulo();
	void cambiar_largo(int nuevo);
	void cambiar_ancho(int nuevo);
	int devolver_largo();
	int devolver_ancho();
	void Mover(System::Drawing::Graphics ^espacio);
	void Mostrar(System::Drawing::Graphics ^espacio,
		System::Drawing::Bitmap^ bmp);
	System::Drawing::Rectangle Area();
};

