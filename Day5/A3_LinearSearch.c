//Implement Searching an element from the list using linear search.

#include<stdio.h>

int main()
{
	int search, i, n, count;

	printf("Enter the number of elements in array\n");
	scanf("%d", &n);
	int array[100];

	printf("\nEnter %d integer(s)\n", n);

	for(i=0; i<n; i++)
	 scanf("%d", &array[i]);

	printf("\nEnter the number to  search");
	scanf("%d", &search);
	
	for(i=0; i<n; i++)
	{
	  if(array[i] == search)
	   {
	     printf("\n%d is present at location %d\n", search, i+1);
	     goto lable;
	   }
	}
	lable:
	if(i == n)
	   printf("\n%d isn't present in the array.\n", search);

	return 0;
}
