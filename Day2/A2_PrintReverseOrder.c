/*Write a function print_reverse() for printing the elements of a linked
list in the REVERSE ORDER.*/

#include<stdio.h>
#include<stdlib.h>

struct node* insert(struct node *head, int );
void print_reverse(struct node *);

struct node{
	int val;
	struct node *next;
};

int main()
{
	int ch, data;
	struct node *head = NULL;
	
	
	do
	{
	 printf("\n\n\n-----------Reverse Order of Linked List------------:\n");
	 printf("\n\n1. Insert ...\n");	 
	 printf("\n2. Print reverse display.\n");
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
		  }
		  break;
	
	   case 2:printf("\nValue is :: ");
	          print_reverse(head);
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

void print_reverse(struct node *head)
{
	if(head == NULL)
	  return ;

	 print_reverse(head->next);	
	 printf("\t%d", head->val);
	
}

