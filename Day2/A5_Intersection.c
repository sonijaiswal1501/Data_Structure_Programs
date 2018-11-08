/*Given two sorted linked lists L1 and L2 by data, perform L1 ∩ L2.
Write a function intersect(L1, L2). Store the result of operation in L3.
(Hint: For simplicity, take unique data elements in both lists).*/


#include<stdio.h>
#include<stdlib.h>

struct node* insert(struct node *, int );
struct node* intersection(struct node *, struct node *, struct node *);
void display(struct node *);

struct node{
	int val;
	struct node *next;
};

int main()
{
	int i, n, ch, data, pos;
	struct node *head, *head1, *head2;
	head = head1 = head2 = NULL;

	do
	{
	 printf("\n\n\n-----------Intersection------------:\n");
	 printf("\n\n1. Insert first sorted list L1.\n");
	 printf("\n2. Insert second sorted list L2.\n");
	 printf("\n3. Intersect of L3 .\n");	
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
	             head1 = insert(head1, data);
		     display(head1);
		   }
		   break;
		
	   case 2:printf("\nEnter the number n : ");
		   scanf("%d", &n);
		   for(i=0; i<n; i++)
	 	   {
	   	     printf("\nEnter the value of element : ");
		     scanf(" %d", &data);
	             head2 = insert(head2, data);
		     display(head2);
		   }
		   break;
		
	   case 3:head = intersection(head, head1, head2);
		  display(head);
		  break;
	   case 0:exit(1);

	   default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);
	printf("\n");

	return 0;
}
struct node* intersection(struct node *head, struct node *head1, struct node *head2)
{
	int flag=0;		
	struct node *p = head1, *q = head2;
	
	while(q != NULL)
	{
	  p = head1;
	  while(p != NULL)
	  {
	    flag = 0;
	    if(p->val == q->val)	    
	      flag++;	   
	  
	    if(flag == 1)
	      head = insert(head, p->val); 
	       
	    p = p->next;
	  }
	  q = q->next;
	}
	
	return head;
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

void display(struct node *head)
{
	if(head == NULL)
	 printf("\nList is empty\n");
	
	printf("\nValue is :: ");
	while(head != NULL)
	{
	  printf("\t%d", head->val);
	  head = head->next;
	 }
}


