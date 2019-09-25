#pragma once
#include "Rectangulo.h"
class Asteroide :	public Rectangulo
{
private:
	int fila, columna;
	int tipoAsteroid;
	//si la bala imnpacta con un asteroide se elimina
	bool eliminar;
public:
	Asteroide(int tipoAsteroid);
	~Asteroide();

	bool  devolver_eliminar();
	bool cambiar_eliminar(bool nuevo);
	void Mover(System::Drawing::Graphics ^espacio);
	void Mostrar(System::Drawing::Graphics ^espacio,
		System::Drawing::Bitmap^ bmp1, System::Drawing::Bitmap^ bmp2);
	int getTipoAsteroid();
};

