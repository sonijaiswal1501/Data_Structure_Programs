/*Create a Stack using array implementation with functions: push(),
pop and tos. Write a function display_stack to print all elements.*/


#include<stdio.h>
#include<stdlib.h>

#define size 100
int top = -1;

int push(int *, int);
void pop(void);
int tos(int *);
void display(int *);


int main()
{
	int i, n, ch, num, data, arr[size], value=0;  
	
	do
	{
	 printf("\n\n\n-----------Stack using array------------:");
	 printf("\n\n1. Push the element.\n");
	 printf("\n2. Pop the element.\n");
	 printf("\n3. top of stack\n");
	 printf("\n4. Display\n");
	 printf("\n0. Exit\n");	
	
	 printf("\nEnter the choice :");
	 scanf("%d", &ch);

	 switch(ch)
	 {
	   case 1:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
	 	  {
		    printf("\nEnter the value to be insert: ");
		    scanf(" %d", &num);
	            value = push(arr, num);
		  }
		  display(arr);
		  break;
		
	   case 2:pop();
		  display(arr);
		  break;
	
	   case 3:data =tos(arr);
		  printf("\nThe element at top is %d.\n", data);
		  break;

	   case 4:display(arr);
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}

int push(int *arr, int num)
{
	if(top == size)	
	{
	   printf("\nError: stack overflow..\n");
	   exit(1);
	}

	top++;
	arr[top] = num;

	return top;
}
void pop(void)
{
	if(top == -1)	
	{
	   printf("\nError: No element to pop ..\n");
	   exit(1);
	}

	top--;
}
int tos(int *arr)
{
	return arr[top];
}
void display(int *arr)
{	
	if(top == -1)
	 printf("\nStack is empty\n");	
	else
	{
	   printf("\nStack element(s) are :: ");
	   for(int i = top; i>=0; i--)
	       printf(" %d\t", arr[i]);
	}

	
}


		
