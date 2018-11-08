/*Write a function reverse() to reverse a Linked List.*/



#include<stdio.h>
#include<stdlib.h>

struct node* insert(struct node *head, int );
void display(struct node *);
struct node* reverse(struct node *head);

struct node{
	int val;
	struct node *next;
};

int main()
{
	int ch, data, pos;
	struct node *head = NULL;

	do
	{
	 printf("\n\n\n-----------Reverse Function of Linked List------------:\n");
	 printf("\n\n1. Insert ...\n");
	 printf("\n2. Reverse a linked list.\n");
	 printf("\n3. Display.\n");
	 printf("\n0. Exit\n");
	
	 printf("\nEnter the choice :");
	 scanf("%d", &ch);

	 switch(ch)
	 {
	   case 1:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
	 	  {
	   	     printf("\nEnter the value of element : ");
		     scanf(" %d", &data);
	             head = insert(head, data);
		  }s
		  break;
		
	   case 2:printf("\nReverse a linked list::\n");
		  head = reverse(head);
		  break;

	   case 3:display(head);
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}

struct node* insert(struct node *head, int val)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->val = val;
	temp->next = NULL;

	if(head == NULL)	
	{
	  head = temp;
	  return head;
	}

	temp->next = head;
	head = temp;	

	return head;
} 

struct node* reverse(struct node *head)
{
	struct node *prev, *curr, *n_next;
	
	prev = NULL;
	curr = head;
	
	while(curr != NULL)
	{
	    n_next = curr->next;	
	    curr->next = prev;
	    prev = curr;
	    curr = n_next;
	}
	
	head = prev;
	
	return head;
}
void display(struct node *head)
{
	if(head == NULL)
	 printf("\nList is empty\n");
	
	printf("\nValue is ");
	while(head != NULL)
	{
	  printf("%d\t", head->val);
	  head = head->next;
	}
}

	 
