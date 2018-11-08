/*Write a function “selection_sort” to implement Selection Sort. Pass
array “arr” and size “n” as arguments from main.*/

#include<stdio.h>


void selection_sort(int *, int );
void swap(int *, int *);


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

	selection_sort(arr, size);

	printf("\n\nSorted array using selection sort : ");
	for(i=0; i<size; i++)
	  printf("%d, ", arr[i]);
	printf("\n\n");

	return 0;
}

void selection_sort(int *arr, int n)
{
	int i, j, i_min=0, temp;	

	for(i=0; i<n-1; i++)
	{ 
	  i_min = i;
	  for(j=i+1; j<n; j++)
	  {	
	    if(arr[j] < arr[i_min])
	       i_min = j;
	
	    if(i != i_min)
	     swap(&arr[i], &arr[i_min]); 
	     	
	   }	
	}

}
void swap(int *a, int *b)
{
	int temp=0;
	
	temp = *a;	
	*a = *b;	
	*b = temp;
}

