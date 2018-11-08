/*Implement a Circular Queue using array implementation with
functions: enqueue, dequeue. Write a function display_queue to print
all elements.*/


#include<stdio.h>
#include<stdlib.h>

#define size 20

int front = -1;
int rear = -1;

void insertq(int *, int);
void deleteq(int *);
void display(int *);

int main()
{	
	int i, n, ch, data, queue[size];
		
	do
	{
	 printf("\n\n\n-----------Circular Queue------------:\n");
	 printf("\n\n1. Insert.\n");
	 printf("\n2. Delete.\n");
	 printf("\n3. Display\n");
	 printf("\n0. Exit\n");

	 printf("\n-----------Circular Queue------------\n");
	
	 printf("\nEnter the choice :");
	 scanf("%d", &ch);

	 switch(ch)
	 {
	   case 1:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  printf("\nEnter the value to be insert: ");
		  for(i=0; i<n; i++)
	 	  {		    
		    scanf(" %d", &data);
	            insertq(queue, data);
		  }
		    display(queue);
		    break;
		
	   case 2:deleteq(queue);
		  display(queue);
		  break;
	
	   case 3:display(queue);
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}
void insertq(int *q, int val)
{
	if(((front == 0) && (rear == size-1)) || (front == rear+1))
	{
	  printf("\nQueue is full\n");
	  return;
	}
	else if(rear == -1)
	{	   
	   front++;
	   rear++;
	}
	else if((front > 0) && (rear == size-1))
	   rear = 0;
	else
	   rear++;

	q[rear] = val;	
	
}

void deleteq(int *q)
{
	if(front == -1)
	  printf("\nQueue is empty\n");
	else if(front == rear)
	{
	   printf("\n %d deleted", q[front]);
	   front = -1;
	   rear = -1;
	}
	else
	{
	  printf("\n %d deleted", q[front]);
	   front++;
	}	
}

void display(int *q)
{	
	int i;
	printf("\nElement(s) in circular queue are : ");
	if(front > rear)
	{
	    for(i= front; i<size; i++)
	   	printf("\t%d", q[i]);
	
	    for(i= 0; i<=rear; i++)
	   	printf("\t%d", q[i]);	
	}
	else
	{
	     for(i= front; i<=rear; i++)
	   	printf("\t%d", q[i]);
	
	}
	
}
