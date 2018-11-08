/*Write a program to swap two pointers.

a) Write a function 'swap' which takes two arguments as integer
pointers and doesn't return any thing. Swap the contents of these
two pointers in 'swap' function.

b) Print the contents of two pointers in main before & after call of
'swap' function.*/


#include<stdio.h>

void swap(int *, int *);

int main()
{
	int a, b;
	
	printf("\nEnter the first number a = ");
	scanf("%d", &a);
	
	printf("Enter the second number b = ");
	scanf("%d", &b);

	printf("\nBefore swapping the values of a = %d and b = %d", a, b);

	swap(&a, &b);

	printf("\nAfter swapping the values of a = %d and b = %d\n", a, b);

	return 0;
}

void swap(int *a, int *b)
{
	int temp=0;
	
	temp = *a;	
	*a = *b;	
	*b = temp;
	
}
