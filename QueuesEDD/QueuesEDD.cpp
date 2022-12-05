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
};


bool emptyqueues(Nodo* front)  //valida si esta vacio
{
	return (front == NULL);
}

void Enqueue(Nodo*& front, Nodo*& last, string n)
{
	Nodo* nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;

	if (emptyqueues(front)) //si cumple con la funcion 
	{
		front = nuevo_nodo;
	}
	else
	{
		last->siguiente = nuevo_nodo;
	}
	last = nuevo_nodo;
	cout << "Elemento " << n << " Agregado con exito" << endl;
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
	Nodo* front = NULL;
	Nodo* last = NULL;
	string opcion;
	int opcionInt = 0;

	while (opcionInt != 4) {
		cout << "Seleccione la opcion que desea ejecutar:\n(1)Enqueue\n(2)Dequeue\n(3)Mostrar datos (Dequeue de toda la cola)" << endl;
		cin >> opcion;

		opcionInt = ValidarNumero(opcion) == opcion ? stoi(opcion) : -1;

		switch (opcionInt) {
		case 1:
			cout << "Escriba la cadena que desea insertar en la cola: ";
			cin >> dato;

			Enqueue(front, last, dato);
			break;
		case 2:
			
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
