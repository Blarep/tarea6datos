#include <iostream>

using namespace std;

void Sorteo_burbuja(int* arreglo, int size)
{
	int aux;
	for (int i = 0; i < (size-1); i++)
	{
		for (int j = 0; j < (size-1); j++)
		{
			if(arreglo[j] > arreglo[j+1])
			{
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1]=aux;
			}
		}
	}
}

int Separar_flash(int* arreglo, int inicio, int fin)
{
	//Numero a comparar con los demas.
	int pivote;
	//Identificara el mayor, de izquierda a derecha.
	int mayor;
	//Identificara el menor, de derecha a izquierda.
	int menor;
	//Auxiliar para intercambiar valores.
	int aux;

	//Corresponde al primer elemento.
	pivote = arreglo[inicio];
	//El mayor comenzara en el inicio del arreglo.
	mayor = inicio;
	//El menor comenzara en el fin del arreglo.
	menor = fin;

	//Mientras el izquierdo no alcance al derecho.
	while (mayor < menor)
	{
		//Mientras el valor del menor sea mayor al pivote.
		while(arreglo[menor] > pivote)
		{
			//Nos movemos a la izquierda.
			menor--;
		}
		//Mientras el indice del mayor sea menor que el otro
		//(ya que de otra forma no existiria).
		while((mayor < menor) && (arreglo[mayor] <= pivote))
		{
			//Si el valor del mayor sea menor o igual al pivote.
			mayor++;
		}

		//Si los indices no se han cruzado debemos intercambiar los valores entre si.
		if(mayor < menor)
		{
			aux = arreglo[mayor];
			arreglo[mayor] = arreglo[menor];
			arreglo[menor] = aux;
		}
	}

	//Luego de que se cruzaron los indices, el valor del pivote se debe mover de lugar.
	//Se intercambia el valor del menor, por el pivote, que esta en el inicio del arreglo.
	aux = arreglo[menor];
	arreglo[menor] = arreglo[inicio];
	arreglo[inicio] = aux;

	//Se retorna la posicion del pivote, que es donde se dividira el arreglo en dos.
	return menor;  
}
void flash_sort(int *arreglo,int inicio,int fin)
{
	//Separador que dividira el arreglo en 2.
	//Los menores a el, y los mayores a el.
	int separador;

	//Mientras no se choquen los indices.
	if(inicio < fin)
	{
		//Separamos el arreglo y obtenemos la posicion de donde se separo.
		separador = Separar_flash(arreglo,inicio,fin);
		
		//Se ordena la lista de los menores.
		//Va desde el inicio al anterior al separador.
		flash_sort(arreglo,inicio,separador-1);

		//Se ordena la lista de los mayores.
		//Va desde el siguiente al separador hasta el fin.
		flash_sort(arreglo,separador+1,fin);
	}
}

int sumar(int *arreglo,int size, int dinero)
{
	//Variable que almacenara la cantidad de juegos.
	int cantidad = 0;

	//Recorreremos el arreglo ordenado de menor a mayor precio.
	for (int i = 0; i < size; i++)
	{
		//Si la resta del presupuesto con el valor del juego es mayor que 0
		//podemos seguir comprando!
		if((dinero - arreglo[i]) > 0)
		{
			//Un juego mas a la cuenta de steam.
			cantidad++;
			//Adios dinero.
			dinero = dinero - arreglo[i];
		}
		//Si se acabo todo el dinero termino el ciclo.
		else
		{
			break;
		}
	}

	//Retornamos la cantidad de juegos.
	return cantidad;
}

void imprimir(int *ordenado,int *cronologico,int size)
{
	//Por cada tiempo en el arreglo ordenado debemos buscar
	//su igual en el otro.
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(ordenado[i] == cronologico[j])
			{
				cout << j+1 << " ";
				//Dado que los valores se pueden repetir
				//una vez que se encuentra uno se cambia su valor.
				//Lo cambiamos a -1 debido a que es imposible que este valor
				//pueda aparecer.
				cronologico[j] = -1;
			}
		}
	}
	cout << endl;
}


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
	
	//Creacion del arreglo y asignacion de valores.

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

	//Se llama al algoritmo para ordenarlos
	flash_sort(t_total_ordenado,0,(pedidos-1));

	//Se llama a la funcion para mostrar los pedidos en orden
	imprimir(t_total_ordenado, t_total, pedidos);

	return 0;
}