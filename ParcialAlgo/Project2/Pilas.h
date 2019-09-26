#ifndef __PILAS_H__
#define __MYSTACK_H__
template <typename T>
class MyStack {

	struct Node
	{
		T elem;
		Node* next;
		Node(T elem, Node*next = nullptr) : elem(elem), next(next) {}
	};

	Node* _top;
public:
	MyStack() : _top(nullptr) {}
	~MyStack()
	{
		eliminarTodos(_top);
	}

	void eliminarTodos(Node* n)
	{
		if (n != nullptr)
		{
			eliminarTodos(n->next);
			delete n;
		}
	}


	bool push(T elem)
	{
		_top = new Node(elem, _top);
		return true;
	}

	bool pop() {
		if (_top != nullptr)
		{
			Node*aux = _top;
			_top = _top->next;
			delete aux;
			return true;
		}
		return false;
	}

	T top()
	{
		return _top->elem;
	}

	bool is_empty()
	{
		return _top == nullptr;
	}
};


#endif