/*Implement a doubly linked list program with functions:
insert_at_beg, insert_at_end, delete_at_beg, delete_at_end & search.*/


#include<stdio.h>
#include<stdlib.h>

struct node * insert_beg(struct node *, int );
struct node * insert_end(struct node *, int );
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
struct node * search(struct node *, int );
void display(struct node *);

struct node{
	int val;
	struct node *next;
	struct node *prev;
};

int main()
{
	int i, n, ch, data, pos;
	struct node *head = NULL;

	do
	{
	 printf("\n\n\n-----------Doubly Linked List------------:\n");
	 printf("\n\n1. Insert at beg.\n");
	 printf("\n2. Insert at end.\n");
	 printf("\n3. Delete at beg.\n");
	 printf("\n4. Delete at end.\n");
	 printf("\n5. Search.\n");	
	 printf("\n6. Display.\n");
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
	             head = insert_beg(head, data);
		     display(head);
		  }
		  break;
		
	   case 2:printf("\nEnter the number n : ");
		  scanf("%d", &n);
		  for(i=0; i<n; i++)
	 	  {
	   	     printf("\nEnter the value of element : ");
		     scanf(" %d", &data);
		     head = insert_end(head, data);
		     display(head);
		  }		 
		  break;
	
	   case 3:head = delete_beg(head);
		  display(head);
		  break;

	   case 4:head = delete_end(head);
		  display(head);
		  break;

	   case 5:printf("\nEnter the value ");
		  scanf(" %d", &data);
		  search(head, data);
		  break;
	   
	   case 6:display(head);
		  break;
	
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}


struct node * insert_beg(struct node *head, int val)
{
	struct node *temp = head;
	struct node *newnode = (struct node*)malloc(sizeof(struct node));

	newnode->val = val;	
	newnode->prev = NULL;

	if(head == NULL)	
	  newnode->next = NULL;
		
	else 
	{ 	  
	   newnode->next = head;
	   head->prev = newnode;
	}
	head = newnode;	

	return head;

}
struct node * insert_end(struct node *head,int val)
{
	struct node *trav = head;

	struct node *newnode =  (struct node*)malloc(sizeof(struct node));
	newnode->val = val;
	newnode->next = NULL;	

	if(head == NULL)	
	  newnode->prev = NULL;	  
	 
	else
	{
	    while(trav->next != NULL)	
	      trav = trav->next;
	
	  trav->next = newnode;
	  newnode->prev = trav;	
	}
	 return head;

}
struct node * delete_beg(struct node *head)
{
	struct node *temp=NULL, *t_head;
	

	if(head == NULL)	
	  printf("\nList is empty\n");
	else
	{
	  temp=head;
	  head = temp->next;	   
	  head->prev = NULL;
	  free(temp);	
	}
	
	return head;
}
struct node * delete_end(struct node *head)
{
	
	struct node *temp, *thead;

	if(head == NULL)	
	{
	  printf("\nList is empty\n");
	  return head;
	}
	
	thead = head;
	while(thead->next != NULL)
	{
	  temp = thead;
	  thead = thead->next;	
	}
		
	free(temp->next);
	temp->next = NULL;
	
	return head;
}


struct node * search(struct node *head, int val)
{
	struct node *temp;

	temp = head; 	
	while(temp != NULL)
        {	    
	  if(temp->val == val)
	  {
	     printf("\nElement %d is found in the list \n", val);
	     return head;
	  }
	   temp = temp->next;		
	}
	printf("\nElement %d is not found in the list \n", val);
}

void display(struct node *head)
{
	struct node *trav = head;
	
	
	if(trav == NULL)
	{
	  printf("\nList is empty\n");
	  
	}
	
	printf("\nTraversal in Forward direction :: ");
	
	while(trav != NULL)
	{
	  printf("%d\t", trav->val);	 
	  trav = trav->next;
	}
	
	printf("\n");
}





