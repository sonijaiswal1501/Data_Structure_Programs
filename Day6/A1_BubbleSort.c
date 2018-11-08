//Write a function “bubble_sort” to implement Bubble sort. Pass array “arr” and size “n” as arguments from main.


#include<stdio.h>


void bubble_sort(int *, int );
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

	bubble_sort(arr, size);

	printf("\n\nSorted array using bubble sort : ");
	for(i=0; i<size; i++)
	  printf("%d, ", arr[i]);
	printf("\n\n");

	return 0;
}

void bubble_sort(int *arr, int n)
{
	int i, j, temp;
	int swapflag=0;

	for(i=0; i<n; i++)
	{ 
	  for(j=0; j<(n-i-1); j++)
	  {
	    if(arr[j] > arr[j+1])
	    {
	        swapflag = 1;
	        swap(&arr[j], &arr[j+1]);
		
            }
	  }	
	  if(swapflag == 0)
	  break;
        }
}
void swap(int *a, int *b)
{
	int temp=0;
	
	temp = *a;	
	*a = *b;	
	*b = temp;
	
}
