//Write a program to implement Queue using Linked List.


#include<stdio.h>
#include<stdlib.h>

struct Qnode{
	int key;
	struct Qnode *next;
}*front=NULL, *rear=NULL;

void enqueue(int );
void dequeue(void);
void display();


int main()
{	
	int i, n, ch, data;
		
	do
	{
	 printf("\n-----------Queue using linked list------------:");
	 printf("\n\n1. Enqueue the element.\n");
	 printf("\n2. Dequeue the element.\n");
	 printf("\n3. Display\n");
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
		    scanf(" %d", &data);
	            enqueue(data);
		  }
		   display();
		   break;
		
	   case 2:dequeue();
		  display();
		  break;
	
	   case 3:display();
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}

void enqueue(int k)
{
	struct Qnode *temp = (struct Qnode*)malloc(sizeof(struct Qnode));

	if(rear == NULL)
	{
	   temp->key = k;
	   temp->next = NULL;
	   front = rear = temp;
	   return;
	}
	else
	{
	   rear->next = temp;
	   temp->key = k;
	   temp->next = NULL;	   
	   rear = temp;
	}

}

void dequeue(void)
{	
	struct Qnode *t_front = front;
	
	if(front == NULL)
	  printf("\nQueue underflow\n");
	else if(front->next != NULL)
	{
	    t_front = front->next;	
	    printf("\nDequeue value is %d\n", t_front->key);
	    free(front);
	    front = t_front;
	}
	else
	{	   	
	    printf("\nDequeue value is %d\n", t_front->key);
	    free(front);
	    front = NULL;
	    rear = NULL;
	}
	
}
void display()
{	
	struct Qnode *t_front = front;

	if((t_front == NULL) && (rear == NULL))
	 printf("\nQueue is empty\n");	
	
	printf("\nValue is :: ");
	while(t_front != rear)
	{
	      printf("%d\t", t_front->key);
	      t_front = t_front->next;
	}
	if(t_front == rear)
	  printf("%d\t", t_front->key);
}
