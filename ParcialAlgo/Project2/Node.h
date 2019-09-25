#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
struct Node
{
	Node* sig;
	T elem;
	Node(T elem, Node* sig = nullptr): elem(elem), sig(sig){}
};


#endif 