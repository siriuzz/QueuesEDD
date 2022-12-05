// Queues.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

//Valida que el str contenga solo numeros
string ValidarNumero(string str)
{
	bool notNum = false;
	int i = 0;
	while ((str[i] != '\0') && (notNum != true)) //'\0' es el character que marca el final del string	
	{
		if (isdigit(str[i]) == false)
		{
			str = "";
			notNum = true;
			break;
		}
		i++;
	}
	return str; //devuelve un str igual si no se encontraron letras
}

struct Nodo
{
	string dato;
	Nodo* siguiente;
	int priority;
};


bool emptyqueues(Nodo* front)  //valida si esta vacio
{
	return (front == NULL);
}

void Enqueue(Nodo*& front, Nodo*& last, int priority, string n)
{
	Nodo* nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->priority = priority;
	nuevo_nodo->siguiente = NULL;


	if (emptyqueues(front)) //si cumple con la funcion 
	{
		front = nuevo_nodo;
		last = nuevo_nodo;
	}
	else
	{
		for (Nodo* aux = front; aux != NULL; aux = aux->siguiente) {
			if (aux->priority > nuevo_nodo->priority) {
				front = nuevo_nodo;
				nuevo_nodo->siguiente = aux;
				break;
			}
			else if (aux->siguiente == NULL) {
				aux->siguiente = nuevo_nodo;
				last = nuevo_nodo;
				break;
			}
			else if (aux->siguiente->priority > priority) {
				nuevo_nodo->siguiente = aux->siguiente;
				aux->siguiente = nuevo_nodo;
				break;
			}
		}

	}
	cout << "Elemento " << n << " agregado con exito" << endl;
}

void Dequeue(Nodo*& front, Nodo*& last, string& n)
{
	n = front->dato;
	Nodo* aux = front;

	if (front == last)
	{
		front = NULL;
		last = NULL;
	}
	else
	{
		front = front->siguiente;
	}
	delete aux;

}

int main()
{

	string dato;

	Nodo* siguiente = NULL;

	string priority;
	int priorityInt = 16;

	Nodo* front = NULL;
	Nodo* last = NULL;

	string opcion;
	int opcionInt = 0;

	while (opcionInt != 5) {
		cout << "Seleccione la opcion que desea ejecutar:\n(1)Enqueue\n(2)Dequeue\n(3)Mostrar datos (Dequeue de toda la cola)\n>>";
		cin >> opcion;

		opcionInt = ValidarNumero(opcion) == opcion ? stoi(opcion) : -1;

		switch (opcionInt) {
		case 1:
			cout << "Escriba la cadena que desea insertar en la cola: ";
			cin >> dato;
			cout << "Escriba la prioridad que tendra la cadena: ";
			cin >> priority;

			if (ValidarNumero(priority) == priority) priorityInt = stoi(priority);
			else {
				cout << "Prioridad invalida, inserte solo numeros por favor" << endl;
				break;
			}

			if (priorityInt > 16) priorityInt = 16;

			Enqueue(front, last, priorityInt, dato);

			break;
		case 2:
			if (front != NULL) {
				cout << "Valor eliminado: " << front->dato << endl;
				Dequeue(front, last, dato);
			}
			else cout << "La cola esta vacia, inserte valores" << endl;
			break;

		case 3:
			if (front != NULL) {
				while (front != NULL)
				{
					Dequeue(front, last, dato);

					if (front != NULL) cout << dato << "  ,  ";
					else cout << dato << ".\n";
				}
			}
			else cout << "La cola esta vacia, inserte valores" << endl;

			break;

		case 4:
			for (Nodo* aux = front; aux != NULL; aux = aux->siguiente) {
				cout << "dato: " << aux->dato << "; prioridad: " << aux->priority << endl;
			}
			break;
		default:
			cout << "Valor invalido introducido, solo se permiten numeros entre el 1 y el 3" << endl;
			break;
		}
		system("PAUSE");
		system("CLS");

	}

	/*cout << "Digite un numero: ";
	cin >> dato;
	Enqueue(front, last, dato);

	cout << "Eliminando datos de la cola\n";
	while (front != NULL)
	{
		Dequeue(front, last, dato);

		if (front != NULL)
		{
			cout << dato << "  ,  ";
		}
		else
		{
			cout << dato << ".";
		}
	}*/

}
