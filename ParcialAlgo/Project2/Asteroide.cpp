#include "Asteroide.h"



Asteroide::Asteroide(int tipoAsteroid) : tipoAsteroid(tipoAsteroid)
{	fila = columna = 0;
	if(tipoAsteroid == 1) dy = 5;
	else dy = 3;
	eliminar = false;
	
}

Asteroide::~Asteroide()
{

}

void Asteroide::Mover(System::Drawing::Graphics ^espacio)
{
	if (y + dy +largo  > 560) 
		y = 90;
	y += dy;
}
void Asteroide::Mostrar(System::Drawing::Graphics ^espacio,
	System::Drawing::Bitmap^ bmp1, System::Drawing::Bitmap^ bmp2)
{
	if (tipoAsteroid == 1)
	{
		bmp1->MakeTransparent(bmp1->GetPixel(1, 1));
		ancho = bmp1->Width / 8;
		largo = bmp1->Height / 8;
		System::Drawing::Rectangle celda = System::Drawing::Rectangle((columna * ancho), (fila*largo), ancho, largo);
		espacio->DrawImage(bmp1, x, y, celda, System::Drawing::GraphicsUnit::Pixel);
	}
	else
	{
		bmp2->MakeTransparent(bmp2->GetPixel(1, 1));
		ancho = bmp2->Width / 8;
		largo = bmp2->Height / 8;
		System::Drawing::Rectangle celda = System::Drawing::Rectangle((columna * ancho), (fila*largo), ancho, largo);
		espacio->DrawImage(bmp2, x, y, celda, System::Drawing::GraphicsUnit::Pixel);
	}
	
	columna++;
	if (columna == 8)
		{fila++; columna=0;		}
	if (fila == 8)
		fila = 0;

}

bool Asteroide::devolver_eliminar()
{
	return eliminar;
}

bool Asteroide::cambiar_eliminar(bool nuevo)
{
	eliminar = nuevo;
	return eliminar;
}

int Asteroide::getTipoAsteroid() 
{
	return this->tipoAsteroid;
}