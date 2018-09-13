#include<stdio.h>
int main()
{
	int first=0,last,middle,search;
	int i,n,A[100];
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Enter element to search:");
	scanf("%d",&search);
	last=n-1;
	middle=(first+last)/2;
	while(first<=last)
	{
		if(A[middle]<search)
			first=middle+1;
		else if (A[middle]==search)
		{
			printf("%d found at location %d \n",search,middle+1);
			break;
		}
		else
			last=middle-1;
		middle=(last+first)/2;
	}
	if(first>last)
		printf("Element doesnt exist \n");
	return 0;
}		
