// Escribe aquí la implementación de los ejercicios de búsqueda lineal.

//Ejercicio 3 algoritomo de busqueda lineal recursiva 
#include <stdio.h> 
int busquedaRecursiva(int arr[], int n, int clave){
	//caso base si el arreglo esta vacio
	if(n < 0){
		return -1;
	}
	//caso base si elelemento es la clave 
	if(arr[n] == clave){
		return n;
	}
	//llamada recursiva 
	return busquedaRecursiva(arr, n-1, clave);
} 

int main (){
	int arreglo1[] = {10, 20, 80, 30, 50, 110, 4};
	int tam = sizeof(arreglo1)/ sizeof(arreglo1[0]); 
	int elementobuscado = 4; 

	// llamamos a la funcion de busqueda
	int respuesta = busquedaRecursiva(arreglo1, tam-1, elementobuscado); 
	
	if(respuesta != -1){
		printf("El elemento %d se encuentra en el indice %d del arreglo\n ", elementobuscado, respuesta); 

	}else {
		printf("El elemento %d no esta en el arreglo de la matriz\n", elementobuscado, respuesta); 
	}

	// si otro elemento no se encuntra en el arreglo
	elementobuscado = 222;
	respuesta = busquedaRecursiva(arreglo1, tam-1, elementobuscado); 
	
	if(respuesta != -1){
		printf("El elemento %d se encuentra en el indice %d del arreglo\n", elementobuscado, respuesta); 

	}else {
		printf("El elemento %d no esta en el arreglo de la matriz\n", elementobuscado, respuesta); 
	}
	return 0; 
}



//Ejercicio 4 algoritmo de busqueda lineal con centinela 
#include <stdio.h>
int busquedaCentinela(int arr[], int n, int clave){
	//copiar el ultimo elemento como centinela 
	int temp = arr[n-1]; //guardar el varol original 
	arr[n-1]=clave;

	//indicar el indice de busqueda 
	int i = 0; 
	// recorrer el array hasta encontrar la clave 
	while (arr[i] != clave){
		i++;
	}

	// restaurara el valor original 
	arr[n-1] = temp; 
	// devolver el indice si se encontro
	if( i < n -1){
		return i; //sis e encuntra el indice 
	} else {
		return -1; // no se encontro la clave o centinela 
	}
}

int main (){
	int arr[] = {10, 20, 30, 40, 50, 1, 2, 3, 4}; 
	int n = sizeof(arr)/ sizeof(arr[0]); 
	int clave = 30; 

	int i = busquedaCentinela(arr, n, clave); 

	if(i != -1){
		printf("El elemento %d se encontro en el indice %d\n", clave, i); 

	}else {
		printf("El elemento %d no se encontro en el arreglo\n", clave); 
	}

	//si el elemento deseado no se encuntra en el arreglo 
	clave = 600; 
	i = busquedaCentinela(arr, n, clave); 

	if(i != -1){
		printf("El elemento %d se encontro en el indice %d\n", clave, i); 

	}else {
		printf("El elemento %d no se encontro en el arreglo\n", clave); 
	}
	return 0;
}
