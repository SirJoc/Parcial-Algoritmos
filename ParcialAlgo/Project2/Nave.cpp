#include "Nave.h"

Nave::Nave()
{ 
	arreglo = new Lista<bala*>();
	dx = dy = 10;
}
Nave::~Nave()
{
}
void Nave::Mover_Arriba(System::Drawing::Graphics ^espacio)
{	if (y - dy > espacio->VisibleClipBounds.Top+75)
		y -= dy;
}
void Nave::Mover_Abajo(System::Drawing::Graphics ^espacio) 
{	if (y + dy + largo < espacio->VisibleClipBounds.Bottom-10)
		y += dy;
}
void Nave::Mover_Izquierda(System::Drawing::Graphics ^espacio) 
{	if (x - dx > espacio->VisibleClipBounds.Left+10)
		x -= dx;
}
void Nave::Mover_Derecha(System::Drawing::Graphics ^espacio) 
{	if (x + dx+ancho < espacio->VisibleClipBounds.Right-18)
		x += dx;
}

void Nave::Mostrar(System::Drawing::Graphics ^espacio, System::Drawing::Bitmap^ bmp)
{
	ancho = largo = 40;
	espacio->DrawImage(bmp, x, y, ancho, largo);
	bmp->MakeTransparent(bmp->GetPixel(1, 1));
}

void Nave::Disparar(System::Drawing::Graphics ^espacio) 
{
	arreglo->agregaInicial(new bala());
	arreglo->obtenerInicial()->cambiar_y(y);
	arreglo->obtenerInicial()->cambiar_x(x + ancho / 2);
	arreglo->obtenerInicial()->cambiar_dx(0);
	arreglo->obtenerInicial()->cambiar_dy(-1);
	arreglo->obtenerInicial()->cambiar_ancho(10);
	arreglo->obtenerInicial()->cambiar_largo(10);
}



int Nave::devolver_cant_elementos()
{
	return arreglo->longitud();
}

Lista<bala*>* Nave::devolver_arr_balas()
{
	return arreglo;
}

void Nave::Mover_Balas(System::Drawing::Graphics ^espacio)
{
	for (int i = 0; i < arreglo->longitud(); i++)
	{
		arreglo->obtenerPos(i)->Mover(espacio);
		arreglo->obtenerPos(i)->Mostrar(espacio, nullptr);//NULLPTR	no muestra nada, porque no hay imagen
		if (arreglo->obtenerPos(i)->devolver_y() <=110) 
			arreglo->eliminaPos(i);
	}
		
}