/*
 * 03
 * Insertion Sort
 * Name: Ritty Thomas
 * Roll no: 42
 */
#include <stdio.h>

int insertionSort(int array[], int size) {
	int i, j, temp;
	for (i=1; i<size; i++) {
		temp = array[i];
		for (j=i-1; j>=0 && array[j] > temp; j--) {
				array[j+1] = array[j];
		}
		array[j+1] = temp;
	}
}
void main() {
	int array[100], i, j, size;

	printf("Enter size of the array : ");
	scanf("%d", &size);

	printf("Enter array\n");
	for (i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}

	insertionSort(array, size);
	
	printf("Sorted array\n");
	for (i=0; i<size; i++) {
		printf("%d\n", array[i]);
	}
}
OUTPUT:
Enter size of the array : 5 
Enter array
8 4 2 5 7
Sorted array
2
4
5
7
8
