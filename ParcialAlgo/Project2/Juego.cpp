#include <stdlib.h>
#include "Juego.h"
#include "Asteroide.h"


Juego::Juego()
{	
	vidas = new Pila<int>();
	puntuacion = 0;
	cant_asteroides_delete = 0;
	Lst = new Lista<Asteroide*>();
	Pl = new MyStack<Asteroide*>();
    objNave = new Nave();
	objNave->cambiar_x(299);
	objNave->cambiar_y(500);
	vidas->Push(1);
	vidas->Push(1);
	vidas->Push(1);
}
Juego::~Juego() {
	delete objNave;
}

void Juego::Volver_Inicio()
{
	objNave->cambiar_x(299);
	objNave->cambiar_y(500);
}

void Juego::Insertar_Figura(int TipoAsteroid)
{	
	if (Lst->longitud() < 12)
	{
		Asteroide*a1 = new Asteroide(1);
		Lst->agregaInicial(a1);
		Lst->obtenerInicial()->cambiar_x(15 + rand() % 550);
		Lst->obtenerInicial()->cambiar_y(90);
		Asteroide*a2 = new Asteroide(2);
		a2->cambiar_x(15 + rand() % 550);
		a2->cambiar_y(90);	
		Lst->agregaInicial(a2);		
		Pl->push(a2);
	}
	
}
void Juego::Mover_Figuras(System::Drawing::Graphics ^espacio)
{
	for (int i = 0; i < Lst->longitud(); i++)
	{
		Lst->obtenerPos(i)->Mover(espacio);
	}
}
void Juego::Mostrar_Figuras(System::Drawing::Graphics ^espacio,
	System::Drawing::Bitmap^ bmp1, System::Drawing::Bitmap^ bmp2)
{
	for (int i = 0; i < Lst->longitud(); i++)
	{
		Lst->obtenerPos(i)->Mostrar(espacio, bmp1, bmp2);
	}
}
void Juego::Mover_Nave(System::Drawing::Graphics ^espacio, direccion movimiento)
{	if (movimiento == direccion::abajo) 		objNave->Mover_Abajo(espacio);
	if (movimiento == direccion::arriba) 		objNave->Mover_Arriba(espacio);
	if (movimiento == direccion::izquierda)		objNave->Mover_Izquierda(espacio);
	if (movimiento == direccion::derecha)		objNave->Mover_Derecha(espacio);
}
void Juego::Mostrar_Nave(System::Drawing::Graphics ^espacio,
	   System::Drawing::Bitmap^ bmp)
{
	objNave->Mostrar(espacio, bmp);
}

bool Juego::Colision_Nave_Figura()
{
	bool colision = false;	

	//cuando no haya colision
	for (int i = 0; !colision && i < Lst->longitud(); i++)
	{
		if (Lst->obtenerPos(i)->getTipoAsteroid() == 1 || Lst->obtenerPos(i)->getTipoAsteroid() == 2)
		{
			colision = Lst->obtenerPos(i)->Area().IntersectsWith(objNave->Area());	
		}
		
	}
	return colision;
}


void Juego::Colision_Bala_Figura()
{
	for (int i = 0; i < objNave->devolver_arr_balas()->longitud(); i++)
	{
		System::Drawing::Rectangle a =
		System::Drawing::Rectangle(objNave->devolver_arr_balas()->obtenerPos(i)->devolver_x(), 
			                       objNave->devolver_arr_balas()->obtenerPos(i)->devolver_y(), 
			                       objNave->devolver_arr_balas()->obtenerPos(i)->devolver_ancho(), 
			                       objNave->devolver_arr_balas()->obtenerPos(i)->devolver_largo());
		for (int j = 0;j < Lst->longitud(); j++)
		{
			if (Lst->obtenerPos(j)->getTipoAsteroid() == 1)
			{
				if (Lst->obtenerPos(j)->Area().IntersectsWith(a))
				{
					Lst->eliminaPos(j);
					objNave->devolver_arr_balas()->eliminaPos(i);
					this->puntuacion = this->puntuacion + 1000;
				}
			}
		}
	}
}


void Juego::Disparar(System::Drawing::Graphics ^espacio)
{
	objNave->Disparar(espacio);
}
void Juego::Mover_Balas(System::Drawing::Graphics ^espacio)
{
	objNave->Mover_Balas(espacio);
}

void Juego::eliminar_Asteroides()
{
	for (int i = 0; i < Lst->longitud(); i++)
	{
		if (Lst->obtenerPos(i)->devolver_y() >= 540 && Lst->obtenerPos(i)->getTipoAsteroid() == 2)
		{
			Lst->eliminaPos(i);
			Pl->pop();
			++cant_asteroides_delete;
		}
	}
}

int Juego::get_cant_delete()
{
	return cant_asteroides_delete;
}
void Juego::Mostrar_Portada(System::Drawing::Graphics ^espacio, System::Drawing::Bitmap ^bmp)
{
	bmp->MakeTransparent(bmp->GetPixel(1, 1));
	int ancho = bmp->Width / 2;
	int largo = bmp->Height / 2;
	System::Drawing::Rectangle celda = System::Drawing::Rectangle((x * ancho), (y*largo), ancho, largo);
	espacio->DrawImage(bmp, 0, 0, celda, System::Drawing::GraphicsUnit::Pixel);
}

void Juego::Mostrar_Mapa(System::Drawing::Graphics ^espacio, System::Drawing::Bitmap ^bmp)
{
	espacio->DrawImage(bmp, 0, 0, 600, 600);
}
void Juego::set_y(int nuevo)
{
	this->y = nuevo;
}
int Juego::get_y()
{
	return this->y;
}
void Juego::set_x(int nuevo)
{
	this->x = nuevo;
}
int Juego::get_x()
{
	return this->x;
}

int Juego::get_puntuacion()
{
	return this->puntuacion;
}

void Juego::set_puntuacion(int nuevo)
{
	this->puntuacion = nuevo;
}

int Juego::get_vidas()
{
	return vidas->returnLong();
}

void Juego::set_vidas(int nuevo)
{
	if (nuevo == 1)
	{
		vidas->Push(1);
	}
	else
	{
		vidas->Pop();
	}
}


void Juego::Guardar_Partida()
{
	Archivo = fopen("Guardar.txt", "w+");
	if(Archivo != NULL)
	{
		std::string x = std::to_string(objNave->devolver_x());
		std::string y = std::to_string(objNave->devolver_y());
		std::string V = std::to_string(vidas->returnLong());
		std::string P = std::to_string(puntuacion);
		fputs(x.c_str() , Archivo); fputs(",", Archivo);
		fputs(y.c_str(), Archivo); fputs(",", Archivo);
		fputs(V.c_str(), Archivo); fputs(",", Archivo);
		fputs(P.c_str(), Archivo); fputs(",", Archivo);
		fclose(Archivo);
	}

}


void Juego::Cargar_Partida()
{
	std::ifstream f("Guardar.txt");
	if (!f.is_open())
	{
		return;
	}
	else
	{
		std::string linea, num;
		while (f >> linea)
		{
			std::stringstream ss(linea);
			int x, y, v, p;
			int cont = 1;
			while (std::getline(ss, num, ','))
			{
				switch (cont)
				{
				case 1: x = std::atoi(num.c_str()); break;
				case 2: y= std::atoi(num.c_str()); break;
				case 3: v= std::atoi(num.c_str()); break;
				case 4: p = std::atoi(num.c_str()); break;
				}
				cont++;
			}
			objNave->cambiar_x(x);
			objNave->cambiar_y(y);
			puntuacion = p;
			delete vidas;
			vidas = new Pila<int>();

			for (int i = 0; i < v; ++i)
			{
				vidas->Push(i);
			}
		}
	}
}