/*
Enunciado: Realizar un programa en C++ que simule una cola.

Participantes:
1- John Luis Del Rosario Sánchez - ID 1106940
2- Ashly Marisell Paula Ynoa - ID 1108023
3- Elián Matos Díaz - ID 1106901
4- Juan Daniel Ubiera Méndez - ID 1107248
5- Kelvin Arístides García Espinal - ID 1107646

Fecha de entrega: 5/12/2022
*/


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

//declaracion de la estructura Nodo
struct Nodo
{
	string dato;
	Nodo* siguiente{};//declaracion default
	int priority{};//declaracion default
};

//funcion que evalua si la funcion esta vacia o no
bool emptyqueues(Nodo* front)  //valida si esta vacio
{
	return (front == NULL);
}

//Agregar valor a la cola, dependiendo de la prioridad
void Enqueue(Nodo*& front, Nodo*& last, int priority, string n)
{

	Nodo* nuevo_nodo = new Nodo(); //apartar el espacio en memoria
	nuevo_nodo->dato = n; //asignar la el dato al nodo creado
	nuevo_nodo->priority = priority; //asignar la prioridad al nuevo nodo
	nuevo_nodo->siguiente = NULL;


	if (emptyqueues(front)) //si la cola esta vacia
	{
		front = nuevo_nodo;
		last = nuevo_nodo;
	}
	else //sino
	{
		//bucle que itera por cada nodo de la cola
		for (Nodo* aux = front; aux != NULL; aux = aux->siguiente) {
			//si la prioridad del primer elemento es mayor a la prioridad del nuevo nodo
			if (aux->priority > priority) {
				front = nuevo_nodo;
				nuevo_nodo->siguiente = aux;
				break;
			}
			//si el siguiente es NULL (fin de la cola)
			else if (aux->siguiente == NULL) {
				aux->siguiente = nuevo_nodo;
				last = nuevo_nodo;
				break;
			}
			//si la priroridad del nodo siguiente es mayor que la del nuevo nodo
			else if (aux->siguiente->priority > priority) {
				nuevo_nodo->siguiente = aux->siguiente;
				aux->siguiente = nuevo_nodo;
				break;
			}
		}

	}
	cout << "Elemento " << n << " agregado con exito" << endl;
}

//eliminar el nodo del frente de la cola
void Dequeue(Nodo*& front, Nodo*& last, string& n)
{
	n = front->dato; //dato del frente
	Nodo* aux = front;

	if (front == last) //(solo un elemento en la cola)
	{
		front = NULL;
		last = NULL;
	}
	else//(mas de un elemento de la cola)
	{
		front = front->siguiente;
	}
	delete aux;
}

int main()
{
	//parametros de los nodos
	string dato, priority;
	int priorityInt = 16;

	//punteros de la cola
	Nodo* front = NULL;
	Nodo* last = NULL;

	//opcion del menu
	string opcion;
	int opcionInt = 0;

	//menu
	while (opcionInt != 5) {
		//opciones
		cout << "Seleccione la opcion que desea ejecutar:\n(1)Enqueue\n(2)Dequeue\n(3)Mostrar datos (Dequeue de toda la cola)\n(4)Salir\n>>";
		cin >> opcion;

		//asignar valor dependiendo si es numero o no
		opcionInt = ValidarNumero(opcion) == opcion ? stoi(opcion) : -1;

		switch (opcionInt) {
		case 1:  //Enqueue
			cout << "Escriba la cadena que desea insertar en la cola: ";
			cin >> dato;
			cout << "Escriba la prioridad que tendra la cadena: ";
			cin >> priority;

			//validar prioridad introducida
			if (ValidarNumero(priority) == priority) priorityInt = stoi(priority);
			else {
				cout << "Prioridad invalida, inserte solo numeros enteros por favor" << endl;
				break;
			}

			if (priorityInt > 16) priorityInt = 16;

			Enqueue(front, last, priorityInt, dato);

			break;
		case 2: //Dequeue

			if (front != NULL) { //si la cola no esta vacia, realizar dequeue
				cout << "Valor eliminado: " << front->dato << endl;
				Dequeue(front, last, dato);
			}
			else cout << "La cola esta vacia, inserte valores" << endl;
			break;

		case 3: //Mostrar datos (Dequeue de toda la cola)
			if (front != NULL) {
				while (front != NULL)
				{
					cout << "|" << front->dato << "[" << front->priority << "]|" << "->";
					Dequeue(front, last, dato);
				}
				cout << " NULL" << endl;
			}
			else cout << "La cola esta vacia, inserte valores" << endl;

			break;

		case 4:
			cout << "Adios!" << endl;
			exit(0);
		default: //
			cout << "Valor invalido introducido, solo se permiten numeros entre el 1 y el 3" << endl;
			break;
		}
		system("PAUSE");
		system("CLS");
	}
}
