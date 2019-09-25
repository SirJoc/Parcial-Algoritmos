#pragma once

class Figura
{
protected:
	int x, y, dx, dy;
	int r, g, b;
public:
	Figura();
	~Figura();
	void cambiar_x(int nuevo);
	void cambiar_y(int nuevo);
	void cambiar_dx(int nuevo);
	void cambiar_dy(int nuevo);
	int  devolver_x();
	int  devolver_y();
	int  devolver_dx();
	int  devolver_dy();
	int  devolver_r();
	int  devolver_g();
	int  devolver_b();
	virtual void Mover(System::Drawing::Graphics ^espacio);
	virtual void Mostrar(System::Drawing::Graphics ^espacio,
		                 System::Drawing::Bitmap^ bmp);
};

