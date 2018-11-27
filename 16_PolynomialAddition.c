#include<stdio.h>
struct poly
 {
	 int coeff;
	 int expo;
 } p1[10],p2[10],p3[10];

int readPoly(struct poly p[10])
 {
	int t1,i;

	printf("\n Enter the total number of terms in the polynomial:");
	scanf("%d",&t1);
	printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
	for(i=0;i<t1;i++)
	{
		printf("   Enter the Coefficient(%d): ",i+1);
		scanf("%d",&p[i].coeff);
		printf("      Enter the exponent(%d): ",i+1);
		scanf("%d",&p[i].expo);     
	}
	return(t1);
 }

int addPoly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10])
 {
	int i=0,j=0,k=0;
	while(i<t1 && j<t2)
	{
		if(p1[i].expo==p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff + p2[j].coeff;
			p3[k].expo=p1[i].expo;
			i++;
			j++;
			k++;
		}
		else if(p1[i].expo>p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff;
			p3[k].expo=p1[i].expo;
			i++;
			k++;
		}
		else
		{
			p3[k].coeff=p2[j].coeff;
			p3[k].expo=p2[j].expo;
			j++;
			k++;
		}
	}
	while(i<t1)
	{
		p3[k].coeff=p1[i].coeff;
		p3[k].expo=p1[i].expo;
		i++;
		k++;
	}

	while(j<t2)
	{
		p3[k].coeff=p2[j].coeff;
		p3[k].expo=p2[j].expo;
		j++;
		k++;
	}

	return(k);
 }

 void displayPoly(struct poly p[10],int term)
 {
	int k;
	for(k=0;k<term-1;k++)
	printf("%d(x^%d)+",p[k].coeff,p[k].expo);
	printf("%d(x^%d)",p[term-1].coeff,p[term-1].expo);
}
 int main()
 {
	int t1,t2,t3;
	t1=readPoly(p1);
	printf(" \n First polynomial : ");
	displayPoly(p1,t1);
	t2=readPoly(p2);
	printf(" \n Second polynomial : ");
	displayPoly(p2,t2);
	t3=addPoly(p1,p2,t1,t2,p3);
	printf(" \nResultant polynomial after addition : ");
	displayPoly(p3,t3);
	printf("\n");

	return 0;
 }

OUTPUT:
Enter the total number of terms in the polynomial:3

 Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER
   Enter the Coefficient(1): 2
      Enter the exponent(1): 2
   Enter the Coefficient(2): 6
      Enter the exponent(2): 1
   Enter the Coefficient(3): 7
      Enter the exponent(3): 0
 
 First polynomial : 2(x^2)+6(x^1)+7(x^0)
 Enter the total number of terms in the polynomial:3

 Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER
   Enter the Coefficient(1): 4
      Enter the exponent(1): 2
   Enter the Coefficient(2): 1
      Enter the exponent(2): 1
   Enter the Coefficient(3): 7
      Enter the exponent(3): 0
 
 Second polynomial : 4(x^2)+1(x^1)+7(x^0) 
Resultant polynomial after addition : 6(x^2)+7(x^1)+14(x^0)
