/*
 * 02
 * Selection Sort
 * Name: Ritty Thomas
 * Roll no: 42
 */

#include <stdio.h>
 
int main()
{
   int a[100], n, i, j, pos, swap;
 
   printf("Enter number of elements\n");
   scanf("%d", &n);
 
   printf("Enter %d integers\n", n);
 
   for (i=0 ; i<n ; i++ )
      scanf("%d", &a[i]);
 
   for ( i= 0 ; i<( n - 1 ) ; i++ )
   {
      pos = i;
 
      for ( j=i+1 ; j<n ; j++ )
      {
         if ( a[pos] > a[j] )
            pos = j;
      }
      if ( pos != i )
      {
         swap = a[i];
         a[i] = a[pos];
         a[pos] = swap;
      }
   }
 
   printf("Sorted list in ascending order:\n");
 
   for ( i=0 ; i<n ; i++ )
      printf("%d ", a[i]);
 
   return 0;
}
OUTPUT:
Enter number of elements 5
Enter 5 integers 9 2 8 4 1
Sorted list in ascending order:
1 2 4 8 9 
