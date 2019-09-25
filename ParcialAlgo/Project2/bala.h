#pragma once
#include "Rectangulo.h"
class bala: public Rectangulo
{
	
public:
	bala();
	~bala();

	void Mover(System::Drawing::Graphics ^espacio);
	void Mostrar(System::Drawing::Graphics ^espacio,
		System::Drawing::Bitmap^ bmp);

};
