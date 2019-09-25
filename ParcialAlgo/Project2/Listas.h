#ifndef __LISTAS_H__
#define __LISTAS_H__
#include <functional>
#include <stdlib.h>
#include "Node.h"
typedef unsigned int uint;
template <typename T, T NADA = 0>
class Lista
{
private:
	typedef std::function<int(T, T)> Comp;
	Node<T>* ini;
	uint lon;
	Comp    comparar;
	void eliminarPosPrivate(uint pos)
	{
		if (pos == 0)
		{
			Node<T>* n = ini;
			ini = ini->sig;
			delete n;
			--lon;
		}
		else if (pos < lon)
		{
			Node<T>* n = ini;
			for (uint i = 1; i < pos; ++i)
				n = n->sig;
			Node<T>* aux = n->sig;
			n->sig = n->sig->sig;
			delete aux;
			--lon;
		}

	}
	void agregarInicialPrivate(T elem)
	{
		Node<T>* n = new Node<T>(elem, ini);
		ini = n;
		++lon;
	}
	T obtenerPosPrivate(uint pos)
	{
		if (pos > lon || pos < 0)
		{
			return NADA;
		}
		else
		{
			Node<T>* n = ini;
			for (uint i = 0; i < pos; ++i)
			{
				n = n->sig;
			}
			return n->elem;
		}

	}
	void mostrarPrivate(Node<T>* n)
	{
		if (n->sig != nullptr)
		{
			std::cout << n->elem << " -> ";
			mostrarPrivate(n->sig);
		}
		else std::cout << n->elem;
	}

	void eliminarTodos(Node<T>* n)
	{
		if (n->sig != nullptr)
		{
			eliminarTodos(n->sig);
			delete n;
		}
		else delete n;
	}

	T buscarPrivate(T elem)
	{
		Nodo<T>* aux = ini;
		while (aux != nullptr) {
			if (comparar(aux->elem, elem) == 0) {
				return aux->elem;
			}
			aux = aux->sig;
		}
		return NADA;
	}

public:
	Lista() : ini(nullptr), lon(0), comparar([](T a, T b) {return a - b; }) {}
	~Lista() { eliminarTodos(ini); }
	uint longitud() { return this->lon; }
	void eliminaPos(uint pos) { eliminarPosPrivate(pos); }
	void agregaInicial(T elem) { agregarInicialPrivate(elem); }
	T obtenerInicial() { return ini->elem; }
	T obtenerPos(uint pos) {
		if (obtenerPosPrivate(pos) != nullptr)
			return obtenerPosPrivate(pos);
		else return 0;
	}
	void mostrar() { mostrarPrivate(ini); }
	T buscar(T elem){}
};



#endif