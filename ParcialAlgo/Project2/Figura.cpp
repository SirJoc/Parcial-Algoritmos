#include <stdlib.h>
#include "Figura.h"
Figura::Figura()
{	r = rand() % 256; //0..255
	g = rand() % 256;
	b = rand() % 256;
	dx = dy = 1;
}
Figura::~Figura()
{
}
void Figura::cambiar_x(int nuevo) 
{ x = nuevo; }
void Figura::cambiar_y(int nuevo)
{ y = nuevo; }
void Figura::cambiar_dx(int nuevo)
{ dx= nuevo; }
void Figura::cambiar_dy(int nuevo) 
{ dy= nuevo; }
int  Figura::devolver_x() { return x; }
int  Figura::devolver_y() { return y; }
int  Figura::devolver_dx() { return dx; }
int  Figura::devolver_dy() { return dy; }
int  Figura::devolver_r() { return r; }
int  Figura::devolver_g() { return g; }
int  Figura::devolver_b() { return b; }
void Figura::Mover (System::Drawing::Graphics ^espacio)
{}
void Figura::Mostrar (System::Drawing::Graphics ^espacio,
	                  System::Drawing::Bitmap^ bmp)
{}
