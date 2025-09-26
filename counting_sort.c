// Escribe aquí la implementación de los ejercicios de Counting Sort.

//EJERCICIO 1 
//Implementacion de Counting_Sort 
//Ejercicio 1 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CountingSort(char Arr[], int n) {
	int range = 26; //unicamente permite usar una de las 26
	//letras minusculas que compone al alfabeto 
	int count[26] = {0};
	char *output = (char *)malloc (n * sizeof(char));

	//Contamos cuantas veces aparece un valor en el arreglo(ocurrencias)
	for ( int i = 0; i < n ; i++){
		count[Arr[i] - 'a']++;
	}

	//Acumular conteos (sumamos el primer valor al siguiente
	// de manera sucesiva hasta llegar al final del arreglo a ordenar)
	for (int i = 1; i < range; i++) {
		count[i] += count[i - 1];
	}

	/*Construir el arreglo de salida (ya ordenado) aprovechando
	que nuestro arreglo ya tiene los indices en orden para acomodar
	cada valor en su lugar */
	for(int i = n - 1; i >= 0; i--) {
		output[count[Arr[i] - 'a'] - 1] = Arr[i];
		count[Arr[i] - 'a']--;
	}

	//Copia de regreso (pega en ARR el algoritmo ya ordenado)
	for(int i = 0; i < n; i++) {
		Arr[i] = output[i];
	}

	free (output); //Recordar que output es un arreglo de salida temporal
}	
int main() {
	char arr[100];

	printf("Ingrese la cadena que quiere ordenar (letras minusculas sin espacios):\n");
	scanf("%s", arr);

	int n = strlen(arr); //tamaño del arreglo usando la longitud de la cadena
	
	CountingSort(arr, n);

	printf("Cadena ordenada: %s\n", arr);

	return 0;
}

//EJERCICIO 2
//Implementacion de Counting_Sort (similar) para resolver el problema

#include <stdio.h>
#include <string.h>

//Examine
char Examine(char A[], int i) {
	return A[i];
}

//Swap 
void Swap(char A[], int i, int j){
	char temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//Implementamos Counting Sort
void CountingSort(char A[], int n) {
	int count_r = 0, count_b = 0, count_a = 0;

	//Contamos la frecuencia de aparicion de colores
	for(int i = 0; i < n; i++) {
		char c = Examine(A, i);
		if(c == 'r') {
			count_r++;
		} else if(c == 'b') {
			count_b++;
		} else if (c == 'a') {
			count_a++;
		} else {
			printf("Esa letra no simboliza ningun color permitido");
		}	
	}

	//Colocar en orden 
	int index = 0;

	//Bloque de rojo
	for(int i = 0; i < count_r; i++) {
		while(Examine(A, index) != 'r') {
			//buscamos una r que se encuentre adelante para traerla
			for(int j = index + 1; j < n; j++) {
				if(Examine(A, j) == 'r') {
					Swap(A, index, j);
				break;
				}
			}
		}
		index ++;
	}

	//Bloque de blanco 
	for(int i = 0; i < count_b; i++) {
		while(Examine(A, index) != 'b') {
			//buscamos una b que se encuentre adelante para traerla
			for(int j = index + 1; j < n; j++) {
				if(Examine(A, j) == 'b') {
					Swap(A, index, j);
				break;
				}
			}
		}
		index ++;
	}
	//ya no es necesario repetirlo con azul porque en automático quedarán al final
}

int main() {
	char Arr[100];

	printf("Ingresa la secuencia de colores usando:\n");
	printf(" (r = rojo), (b = blanco) y (a = azul)\n");
	scanf("%s", Arr);

	int n = strlen(Arr);
	CountingSort(Arr, n);

	printf("Ordenado (rojo / blanco / azul): %s\n", Arr);
	return 0;
}


