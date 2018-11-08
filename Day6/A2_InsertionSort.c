/*Write a function “insertion_sort” to implement Insertion Sort. Pass
array “arr” and size “n” as arguments from main.*/

#include<stdio.h>


void insertion_sort(int *, int );



int main()
{
	int i, size;

	printf("\nEnter the size of array : ");
	scanf("%d", &size);

	int arr[size];

	printf("\nEnter the elements of array are : ");
	for(i=0; i<size; i++)
	  scanf("%d", &arr[i]);

	printf("\nElements of array are : ");
	for(i=0; i<size; i++)
	  printf("%d, ", arr[i]);

	insertion_sort(arr, size);

	printf("\n\nSorted array using insertion sort : ");
	for(i=0; i<size; i++)
	  printf("%d, ", arr[i]);
	printf("\n\n");

	return 0;
}

void insertion_sort(int *arr, int n)
{
	int i, j, key;
	
	for(i=0; i<n; i++)
	{ 
	   key = arr[i];
	   j = i-1;

	   while((j >=0) && (arr[j] >key))
	   {
	    	arr[j+1] = arr[j];	
		j = j-1;	
	   }
	   arr[j+1] = key;	 
        }
}


