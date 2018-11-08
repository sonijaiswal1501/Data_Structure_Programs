/*Swap two adjacent elements by adjusting only the pointers(and not the data).(Hint: Create any linked list of n+3 nodes where n ≥ 0. swap 2nd and 3rd nodes)*/



#include<stdio.h>
#include<stdlib.h>

struct node* push(struct node *, int );
struct node* swap(struct node *);
void display(struct node *);

struct node{
	int val;
	struct node *next;
};

int main()
{
	int ch, data, pos;
	struct node *head;
	head = NULL;

	do
	{
	 printf("\n\n\n-----------Swap Linked List------------:\n");
	 printf("\n\n1. Insert list .\n");
	 printf("\n2. Swapping of linked list.\n");	
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
	             head = push(head, data);
		     display(head);
		   }
		   break;
	
	   case 2:head = swap(head);
		  display(head);
		  break;
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}
struct node* swap(struct node *head)
{
	int i=0;
	struct node *temp = head;
	struct node *new = NULL;
	
	/*while(temp->next != NULL)
	{
	  i++;
	  temp = temp->next;
	  if(i == 1)
	    break;
	}*/

	new = temp->next;	
	temp->next = new->next;	
	new->next = new->next->next;
	temp->next->next = new;

	return head;
	
}
struct node* push(struct node *head, int val)
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

void display(struct node *head)
{
	if(head == NULL)
	 printf("\nList is empty\n");
	
	printf("\nValue is ");
	while(head != NULL)
	{
	  printf("%d\t", head->val);
	  head = head->next;
	ss}
}

