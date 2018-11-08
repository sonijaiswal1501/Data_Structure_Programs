//Implement Searching an element in a list using binary search.


#include<stdio.h>

void binary_search(int *, int, int);

int main()
{
	int search, i, j, n, low, high, mid, temp;

	printf("\nEnter the number of elements in array\n");
	scanf("%d", &n);
	int array[100];

	printf("\nEnter the element one by one ");
	for(i=0; i<n; i++)
	 scanf("%d", &array[i]);

	printf("\nInput array elements :");
	for(i=0; i<n; i++)
	 printf("\t%d", array[i]);
	
	for(i=0; i<n; i++)
	{
	  for(j=0; j<(n-i-1); j++)
	   {
	     if(array[j] > array[j+1])
	      {
	        temp = array[j];
		array[j] = array[j+1];
		array[j+1] = temp;
	      }
	   }
	}
	printf("\nSorted array is...");
	for(i=0; i<n; i++)
	 printf("\t%d", array[i]);

	printf("\nEnter the number to  search");
	scanf("%d", &search);
	
	binary_search(array, search, n);
	
	return 0;
}
void binary_search(int *array, int search, int n)
{
	int low, high, mid;

	low = 1;
	high = n;
	do
	{
	  mid = (low + high)/2;
	  
	  if(search < array[mid])
	     high = mid - 1;

	  if(search > array[mid])
	     low = mid + 1;

	}while(search != array[mid] && low <= high);

	if(search == array[mid])
	   printf("\nSearch Successful\n");
	else
	   printf("\nSearch failed\n");	
	
}
