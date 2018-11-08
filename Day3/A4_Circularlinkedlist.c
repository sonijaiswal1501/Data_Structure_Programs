/*Write an Implementation of Circular Linked insert_front, insert_end and display functions.*/

#include<stdio.h>
#include<stdlib.h>


struct node *insert_beg(struct node *, int);
struct node *insert_end(struct node *, int );
void display(struct node *);

struct node{
	int val;
	struct node *next;
};

int main()
{
	int i, n, ch, data;
	struct node *head = NULL;

	do
	{
	 printf("\n\n\n-----------Circular Linked List------------:\n");
	 printf("\n\n1. Insert at beg.\n");	 
	 printf("\n2. Insert_end.\n");	 
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
	   	    printf("\nEnter the value ");
	   	    scanf(" %d", &data);
	   	    head = insert_beg(head, data);	
	   	    display(head);
	 	  }
		  break;	 

	   case 2:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
		  {
	   	    printf("\nEnter the value ");
	   	    scanf(" %d", &data);
	   	    head = insert_end(head, data);	
	   	    display(head);
	 	  }
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
struct node *insert_beg(struct node *head, int val)
{
	struct node *current = NULL;
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->val = val;
	temp->next = NULL;

	if(head == NULL)	
	{
	  head = temp;
	  head->next = temp;
	  return head;
	}

	current = head;
	while(current->next != head)
	   current = current->next;

	current->next = temp;
	temp->next = head;
	head = temp;	

	return head;
	
}
struct node *insert_end(struct node *head, int val)
{
	struct node *current = NULL;
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->val = val;
	temp->next = NULL;

	if(head == NULL)	
	{
	  head = temp;
	  head->next = temp;
	  return head;
	}

	current = head;
	while(current->next != head)
	   current = current->next;

	current->next = temp;
	temp->next = head;
	
	return head;	
}

void display(struct node *head)
{
	struct node *temp = head;

	if(head == NULL)
	 printf("\nList is empty\n");
	
	printf("\nValue is :: ");
	while(temp->next != head)
	{
	  printf("%d\t", temp->val);
	  temp = temp->next;
	}
	printf("%d\t", temp->val);
}





