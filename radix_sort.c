// Escribe aquí la implementación del ejercicio de Radix Sort.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


	int encontrarMaximo(int arr[], int n){
		int max= arr[0];
		
		for(int i= 1; i<n; i++){

			if(arr[i]>max){
				max=arr[i];
			}
		
		}
		
		return max;
	
	}

	void countingSortRadix(int arr[], int n, int p){

		int output[n];
		int count[10] = {0};

		for (int i=0; i<n; i++){
			int numero= (arr[i]/ p)%10;
			count[numero]++;
		}

		for(int i = 1; i<10; i++){
			count[i]+= count[i-1];
		}

		for (int i = n-1; i>=0; i--){
			int numero = (arr[i]/p)%10;
			output[count[numero]-1]=arr[i];
			count[numero]--;
		}

		for(int i=0; i<n; i++){
			arr[i]=output[i];
		}
}

void radixSort(int arr[], int n){

	if(n<=0) return;

	int max= encontrarMaximo(arr,n);

	for(int p = 1; max / p > 0; p*=10){

	countingSortRadix(arr, n, p);
}
}

	void imprimir (int arr[], int n){

		for(int i=0; i<n; i++){
			printf("%d ", arr[i]);
		}
		
		printf("\n");
	}


int main()
{
	int arr[]={22, 4, 17, 19, 95, 30, 12, 20, 13};
	int n= sizeof(arr) / sizeof(arr[0]);

	printf("La primera lista, es: ");
	
	imprimir(arr,n);
	radixSort(arr,n);

	printf("El array ordenado, es: ");
	
	imprimir(arr, n);
	
	return 0;
}


	
