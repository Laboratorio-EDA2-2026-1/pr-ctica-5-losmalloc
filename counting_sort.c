// Escribe aquí la implementación de los ejercicios de Counting Sort.

//Ejercicio 1 
//Implementacion de counting sort 
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
	for (int i = 0; i< range; i++) {
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
	char Arr[100];

	printf("Ingrese la cadena que quiere ordenar:\n");
	scanf("%s", Arr);

	int n = strlen(Arr); //tamaño del arreglo usando la longitud de la cadena
	
	CountingSort(Arr, n);

	printf("Cadena ordenada: %s\n", Arr);

	return 0;
}
