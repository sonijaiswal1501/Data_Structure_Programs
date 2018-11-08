/*Develop a Singly Linked list implementation of self-adjusting lists. A self-adjusting list is like a regular list, except that all insertions are performed at the front, and when an element is accessed by the Find, it is moved to the front of the list without changing the relative order of the other items. Implement above functionality as self_adjusting_fnd() for singly linked lists.*/


#include<stdio.h>
#include<stdlib.h>

struct node* insert_beg(struct node *head, int );
struct node* self_adjusting_fnd(struct node *head, int );
void display(struct node *);

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
	 printf("\n\n\n-----------Self Adjusting Linked List------------:\n");
	 printf("\n\n1. Insert at beg.\n");	 
	 printf("\n2. self-adjusting.\n");	 
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

	   case 2:printf("\nEnter the value ");
		  scanf(" %d", &data);
		  head = self_adjusting_fnd(head, data);
		  display(head);
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

struct node* insert_beg(struct node *head, int val)
{
	struct node *temp = (struct node* )malloc(sizeof(struct node));

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


struct node* self_adjusting_fnd(struct node *head, int val)
{
	struct node *temp;
	int flag=0;

	
	temp = head; 	
	while(temp->next != NULL)
        {	    
	  if(temp->next->val == val)
	  {	     
	     temp->next = temp->next->next;
	     head = insert_beg(head, val);
	     flag++;
	     break;
	  }
	  temp = temp->next;		
	}
	if(flag == 1)
	  return head;
	else
	   return NULL;
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



