// StackAndQueu.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

class Nodo {
public:
	int dato;
	Nodo* nodoSiguiente = nullptr;

	Nodo(int dato) {
		this->dato = dato;
	}
	Nodo() {
		this->dato = 0;
	}

	~Nodo() {

	}
};

class Queue {

	Nodo* queue;

public:
	Queue() {
		queue = nullptr;
	}

	~Queue() {
		if (queue != nullptr)
		{
			Nodo* ultimoNodo = queue;
			Nodo* penultimoNodo = queue;

			while (queue->nodoSiguiente)
			{
				while (ultimoNodo->nodoSiguiente != nullptr)
				{
					ultimoNodo = ultimoNodo->nodoSiguiente;
				}
				while (penultimoNodo->nodoSiguiente != ultimoNodo)
				{
					penultimoNodo = penultimoNodo->nodoSiguiente;
				}

				ultimoNodo->~Nodo();
				penultimoNodo->nodoSiguiente = nullptr;

				ultimoNodo = queue;
				penultimoNodo = queue;
			}

			ultimoNodo->~Nodo();
			penultimoNodo->~Nodo();
		}

		queue->~Nodo();
	}

	bool IsEmpty() {
		return queue == nullptr;
	}

	void PrintList() {
		Nodo* holder = queue;


		if (holder == nullptr)
			std::cout << "[NULL]";

		else {
			std::cout << "[NULL]";

			while (holder != nullptr) {
				std::cout << "<-[" << holder->dato << "]";

				holder = holder->nodoSiguiente;
			}

			std::cout << std::endl;

		}
	}

	void Enqueue(int value) {

		if (queue == nullptr) queue = new Nodo(value);

		else
		{
			Nodo* holder = new Nodo(value);
			holder->nodoSiguiente = queue;

			queue = holder;
		}
	}
	
	int Dequeue() {
		Nodo* holder = queue;
		Nodo* previo = queue;

		if (holder == nullptr) return NULL;

		else 
		{
			while (holder->nodoSiguiente != nullptr) {

				previo = holder;
				holder = holder->nodoSiguiente;
			}

			previo->nodoSiguiente = nullptr;
			int value = holder->dato;

			holder->~Nodo();

			return value;
		}
	}

	int Front() {
		Nodo* holder = queue;

		if (holder == nullptr) return NULL;

		else
		{
			while (holder->nodoSiguiente != nullptr) {

				holder = holder->nodoSiguiente;
			}

			return holder->dato;
		}
	}
};

class Stack {

	Nodo* stack;

public:
	Stack() {
		stack = nullptr;
	}

	~Stack() {
		if (stack != nullptr)
		{
			Nodo* ultimoNodo = stack;
			Nodo* penultimoNodo = stack;

			while (stack->nodoSiguiente)
			{
				while (ultimoNodo->nodoSiguiente != nullptr)
				{
					ultimoNodo = ultimoNodo->nodoSiguiente;
				}
				while (penultimoNodo->nodoSiguiente != ultimoNodo)
				{
					penultimoNodo = penultimoNodo->nodoSiguiente;
				}

				ultimoNodo->~Nodo();
				penultimoNodo->nodoSiguiente = nullptr;

				ultimoNodo = stack;
				penultimoNodo = stack;
			}

			ultimoNodo->~Nodo();
			penultimoNodo->~Nodo();
		}

		stack->~Nodo();
	}

	bool IsEmpty() {
		return stack == nullptr;
	}

	void PrintList() {
		Nodo* holder = stack;


		if (holder == nullptr)
			std::cout << "[NULL]";

		else {

			while (holder != nullptr) {
				std::cout << "[" << holder->dato << "]->";

				holder = holder->nodoSiguiente;
			}

			std::cout << "[NULL]\n";

		}
	}

	int Top() {
		Nodo* holder = stack;

		if (holder == nullptr) return NULL;

		else
		{
			while (holder->nodoSiguiente != nullptr) {

				holder = holder->nodoSiguiente;
			}

			return holder->dato;
		}
	}

	int Pop() {
		Nodo* holder = stack;
		Nodo* previo = stack;

		if (holder == nullptr) return NULL;

		else
		{
			while (holder->nodoSiguiente != nullptr) {

				previo = holder;
				holder = holder->nodoSiguiente;
			}

			previo->nodoSiguiente = nullptr;
			int value = holder->dato;

			holder->~Nodo();

			return value;
		}
	}


	void Push(int value) {

		if (stack == nullptr) stack = new Nodo(value);

		else {
			Nodo* holder = stack;

			while (holder->nodoSiguiente != nullptr)
			{
				holder = holder->nodoSiguiente;
			}

			holder->nodoSiguiente = new Nodo(value);
		}
	}
};

int main()
{
	Queue* queue = new Queue();

	queue->Enqueue(10);
	queue->Enqueue(15);

	queue->PrintList();

	std::cout << queue->Front() << "\n";
	std::cout << queue->Dequeue() << "\n";

	queue->PrintList();

	Stack* stack = new Stack();

	stack->Push(20);
	stack->Push(25);

	stack->PrintList();

	std::cout << stack->Top() << "\n";
	std::cout << stack->Pop() << "\n";

	stack->PrintList();
}