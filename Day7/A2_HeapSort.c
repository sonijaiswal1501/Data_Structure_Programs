//Write C program to sort 'n' numbers using Heap Sort.

#include<stdio.h>

void max_heap(int [], int);
void heap_sort(int [], int);


int main()
{
	int i, size, a, root, temp;
	
	printf("\nEnter the size of the array: ");
	scanf("%d", &size);

	int arr[size];

	printf("\nEnter the elements of array: ");
	for(i=0; i<size; i++)
	   scanf(" %d", &arr[i]);

	printf("\n\nEntered elements of array are: ");
	for(i=0; i<size; i++)
	   printf("%d, ", arr[i]);

	printf("\n\nMax array are: ");
	max_heap(arr, size);
	for(i=0; i<size; i++)
	   printf("%d, ", arr[i]);
	
	printf("\n\nSorted array are: ");
	heap_sort(arr, size);
	for(i=0; i<size; i++)
	   printf("%d, ", arr[i]);

	printf("\n\n");

	return 0;
}

void max_heap(int arr[], int n)
{
	int i, a, root, temp;

	for(i=0; i<n; i++)
	{
	  a=i;
	  do
	  {
	    root = (a-1)/2;
	    if(arr[root] < arr[a])
	    {
	      temp = arr[root];
	      arr[root] = arr[a];
	      arr[a] = temp;
	    }
	    a = root;
	  }while(a != 0);
	}
}

void heap_sort(int arr[], int n)
{
	int j, temp;

	for(int i=n-1; i>=0; i--,j++)
	{
	  temp = arr[0];
	  arr[0] = arr[i];
	  arr[i] = temp;
	  max_heap(arr, i);
	}
}
