#include "Rectangulo.h"



Rectangulo::Rectangulo() :Figura()
{
}
Rectangulo::~Rectangulo()
{
}

void Rectangulo::cambiar_largo(int nuevo)
{	largo = nuevo;}
void Rectangulo::cambiar_ancho(int nuevo)
{	ancho = nuevo;}
int Rectangulo::devolver_largo() { return largo; }
int Rectangulo::devolver_ancho() { return ancho; }

System::Drawing::Rectangle Rectangulo::Area() {
	System::Drawing::Rectangle b =
		System::Drawing::Rectangle(x, y, ancho, largo);
	return b;
}

void Rectangulo::Mover(System::Drawing::Graphics ^espacio)
{
	if (y + dy<1 || y + largo + dy>espacio->VisibleClipBounds.Bottom)
		cambiar_dy(devolver_dy()*-1);
	if (x + dx<1 || x + ancho + dx>espacio->VisibleClipBounds.Right)
		cambiar_dx(devolver_dx()*-1);
	x += dx;
	y += dy;
	
}
void Rectangulo::Mostrar(System::Drawing::Graphics ^espacio,
	System::Drawing::Bitmap^ bmp)
{
	System::Drawing::Color micolor = System::Drawing::Color::FromArgb(r, g, b);
	System::Drawing::SolidBrush ^b = gcnew System::Drawing::SolidBrush(micolor);
	espacio->FillRectangle(b, x, y, ancho, largo);


}