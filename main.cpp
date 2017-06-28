#include <iostream>
#include "funciones.h"

using namespace std;

int main()
{
	//PROBLEMA 1
	//Tamanio del arreglo de precios, dinero disponible, cantidad de juegos que podremos comprar.
	int juegos,dinero,cantidad;
	cin >> juegos >> dinero;

	//Creacion del arreglo y asignacion de valores.
	int costos[juegos];
	for (int i = 0; i < juegos; i++)
	{
		cin >> costos[i];
	}

	//Se llama al algoritmo para ordenarlos.
	Sorteo_burbuja(costos, juegos);

	//Se llama a la funcion para entregar la cantidad de juegos.
	cantidad = sumar(costos, juegos, dinero);

	//Se muestra en pantalla.
	cout << cantidad << endl;

	//PROBLEMA 2
	//Variables para almacenar el numero de pedidos, el tiempo de pedido y
	//tiempo en que se demora en hacerse.
	int pedidos,t_pedido,t_demora;
	cin >> pedidos;
	
	//Creacion de arreglos y asignacion de valores.

	//El primero corresponde al que no sera modificado, para, de cierta manera
	//guardar el orden de los pedidos.
	int t_total[pedidos];
	//El segundo sera para ordenarlos de menor a mayor.
	int t_total_ordenado[pedidos];

	for (int i = 0; i < pedidos; i++)
	{
		cin >> t_pedido >> t_demora;
		//Dado que nos importa el tiempo total que tendra la orden
		//asignamos la suma de los valores a los arreglos.
		t_total[i] = t_demora + t_pedido;
		t_total_ordenado[i] = t_demora + t_pedido;
	}

	//Se llama al algoritmo para ordenarlo.
	flash_sort(t_total_ordenado,0,(pedidos-1));

	//Se llama a la funcion para mostrar los pedidos en orden.
	imprimir(t_total_ordenado, t_total, pedidos);

	return 0;
}