// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
//Implementa el algoritmo de búsqueda binaria (recuerda que es un algoritmo recursivo).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Funcion de busqueda Binaria recursiva
int busquedaBinaria(int A[],int dato,int inicio,int fin){
	int mitad =(inicio + fin)/2;

	// Caso base 
	if(A[mitad] == dato){
		return mitad;
	}
	if (inicio > fin){
		return -1;
	}
	// Caso general
	if(dato < A[mitad]){
		return busquedaBinaria(A,dato,inicio,mitad-1);
	}else if(dato > A[mitad]){
		return busquedaBinaria(A,dato,mitad +1 ,fin);
	}

}
//Funcion para ordenar el arreglo

//Encontrar Maximo en el arreglo
int getMax(int arr[], int n){
	int max = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}
// Ordenamiento
void coutingSort(int arr[],int n){
	int max = getMax(arr,n);
	int *count = (int *)malloc(n*sizeof(int));
	int *output = (int *)malloc(n*sizeof(int));

	for(int i = 0;i < n; i++ ){
		count[arr[i]]++; 
	}
	for(int i = 0;i <= max; i++ ){
		count[i] += count[i-1];
	}
	//arreglo de salida
	for(int i = n-1;i >= 0; i-- ){
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]--];
	}
	for(int i = 0;i < n; i++ ){
		arr[i]= output[i];
	}
	free(count);
	free(output);

}
int main(){
	int n;

	printf("Ingresa el numero de elementos de tu arreglo\n");
	scanf("%d",&n);

	int arr[n];
	printf("Ingresa elos %d numeros de tu arreglo\n",n);
	for(int i = 0;i < n; i++){
		scanf("%d",&arr[i]);
	}
	coutingSort(arr,n);
	printf("Arreglo ordenado\n");
	for(int i = 0;i < n; i++){
		printf("%d\t",arr[i]);
	} 
	printf("\n");
	int dato;
	printf("Que numero deseas bucar en tu arreglo\n");
	scanf("%d",&dato);
	int pos = busquedaBinaria(arr,dato,0,n-1);
	if(pos == -1){
		printf("El dato no esta en el arreglo\n");
	}else{
		printf("El dato se encuntra en la posicion %d\n",pos);
	}
return  0;

}
