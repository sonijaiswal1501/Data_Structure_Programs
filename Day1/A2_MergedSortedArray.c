/*Write a program to merge two sorted arrays: A of size n, B of size m.
Merge arrays A and B to third array C of size n+m.*/


#include<stdio.h>


int main()
{
	int i, j, n, m, num;

	printf("\nEnter the size of array n and m  : ");
	scanf("%d%d", &n, &m);

	num = n + m;

	int A[n], B[m], C[num];

	printf("\nEnter the elements for first sorted array A: ");
	for(i=0; i<n; i++)
	 scanf("%d", &A[i]);

	printf("\nEnter the elements for second sorted array B: ");
	for(i=0; i<m; i++)
	  scanf("%d", &B[i]);
	  
	
	printf("\nMerged arrays A and B to third array C: ");
	for(i=0; i<n; i++)
	 {
	   C[i] = A[i];
	   printf("%d, ", C[i]);
	 }

	for(i=0,j=n; j<num; i++,j++)
	 {
	   C[j] = B[i]; 
	   printf("%d, ", C[j]);
	 }
	printf("\n");

	return 0;
}
