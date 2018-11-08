/*Write a function “quick_sort” to implement Quick Sort. Pass array
“arr” and size “n” as arguments from main.*/

#include<stdio.h>


void quick_sort(int [], int, int);


int main()
{
	int i, size, list[50];

	printf("\nEnter the number of elements : ");
	scanf("%d", &size);

	printf("\nEnter the elements to be sorted : ");
	for(i=0; i<size; i++)
	  scanf("%d", &list[i]);

	quick_sort(list, 0, size-1);


	printf("\nAfter quick sort : \n");
	for(i=0; i<size; i++)
	  printf("%d\t ", list[i]);

	printf("\n");
	
	return 0;
}

void quick_sort(int list[], int low, int high)
{
	int pivot, i, j, temp;
	
	if(low < high)
	{
	   pivot = low;
           i = low;
	   j = high;
	   while(i < j)
	   {
	     while(list[i] <= list[pivot] && i <= high)
	          i++;
	     while(list[j] > list[pivot] && j >= low)
		  j--;
	     if(i < j)
	     {
	         temp = list[i];
	         list[i] = list[j];
		 list[j] = temp;
	     }
	   }
   	   temp = list[j];
	   list[j] = list[pivot];
	   list[pivot] = temp;
	   quick_sort(list, low, j-1);
	   quick_sort(list, j+1, high);
	 }
}
	






