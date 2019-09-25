#include "bala.h"



bala::bala()
{
	dy = 30;
}

void bala::Mover(System::Drawing::Graphics ^espacio)
{
	//espacio->VisibleClipBounds.Bottom
	if (y + dy < 150 || y + largo + dy >  500) 
		cambiar_dy(devolver_dy()*-1);
	if (x + dx < 1 || x + ancho + dx > espacio->VisibleClipBounds.Right)  
		cambiar_dx(devolver_dx()*-1);
	x += dx;
	y += -20;
}

void bala::Mostrar(System::Drawing::Graphics ^espacio, System::Drawing::Bitmap^ bmp)
{
	System::Drawing::Color micolor = System::Drawing::Color::FromArgb(r, g, b);
	System::Drawing::SolidBrush ^b = gcnew System::Drawing::SolidBrush(micolor);
	espacio->FillRectangle(b, x, y, ancho, largo);
}

bala::~bala()
{
}