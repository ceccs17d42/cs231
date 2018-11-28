#include<stdio.h>

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void BubbleSort( int A[], int n)
{
	int i,j;
	for (i=0;i<n-1;i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (A[j] > A[j+1])
			{
				swap(&A[j],&A[j+1]);
			}
		}
	}
}
void print(int A[], int n)
{
	int i;
	for (int i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}
}
int main()
{
	int i,n, A[50];
	printf("\nEnter number of elements:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);
	/*printf("\nUnsorted Array:");
	print(A,n); */
	BubbleSort(A,n);
	printf("\nSorted Array:");
	print(A,n);	
	return 0;
}
OUTPUT:
Enter number of elements:5

Enter elements:23 12 98 66 2

Sorted Array:2 12 23 66 98
