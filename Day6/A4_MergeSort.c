/*Write a function “merge_sort” to implement Merge sort. Pass array
“arr” and size “n” as arguments from main.*/

#include<stdio.h>


void merge_sort(int [], int, int, int);
void partition(int [], int, int);


int main()
{
	int i, size;
 
	printf("\nEnter total number of elements : ");
	scanf("%d", &size);
	int list[size];

	printf("\nEnter the elements : ");
	for(i=0; i<size; i++)
	  scanf("%d", &list[i]);

	partition(list, 0, size-1);


	printf("\nAfter merge sort : \n");
	for(i=0; i<size; i++)
	  printf("%d\t ", list[i]);

	printf("\n");
	
	return 0;
}

void partition(int list[], int left, int right)
{
	int mid;

	if(left < right)
	{
	    mid = (left + right) / 2;
	    partition(list, left, mid);
	    partition(list, mid+1, right);
	    merge_sort(list, left, mid, right);
	}
}

void merge_sort(int list[], int left, int mid, int right)
{
	int i, mi, k, lo, temp[50];

	lo = left;
	i = left;
	mi = mid + 1;	

	while((lo <= mid) && (mi <= right))
	{
	   if(list[lo] <= list[mi])
	   { 
	      temp[i]  = list[lo];
	      lo++;
           }
	   else
	   {
	      temp[i] = list[mi];
	      mi++;
	   }
	      i++;
	}

	if(lo > mid)
	{
	    for(k=mi; k<=right; k++)
	    {
	       temp[i] = list[k];
	       i++;
	    }
	}

	else
	{
	     for(k=lo; k<=mid; k++)
	     {
	       temp[i] = list[k];
	       i++;
	     }
		
	}

	for(k=left; k<=right; k++)
	{
	    list[k] = temp[k];
	}
}










  










