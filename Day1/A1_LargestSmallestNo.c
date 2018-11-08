//Write a program to find largest and smallest of n numbers without sorting.


#include<stdio.h>


int main()
{
	int i, num, stemp=0, ltemp=0;

	printf("\nEnter the n numbers : ");
	scanf("%d", &num);

	int arr[num];

	printf("\nEnter the n elements : ");
	for(i=0; i<num; i++)
	 scanf("%d", &arr[i]);
	
	for(i=0; i<num; i++)
	 {
	   if(arr[i] > ltemp)
	     ltemp = arr[i];
	   else 
	     stemp = arr[i];
	 }

	printf("\nLargest number is %d\n", ltemp);
	printf("\nSmallest number is %d\n",stemp);

	return 0;
}
