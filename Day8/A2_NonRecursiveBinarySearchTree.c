//Write a non recursive routine to insert an element in binary search tree.

#include<stdio.h>
#include<stdlib.h>
#define count 10

struct node* insert(struct node *, int);
int search(struct node *, int);
void print(struct node *, int);

struct node{
	int val;
	struct node *left;
	struct node *right;
};

int main()
{
	int n, num, i, ch, data, key, flag;	
	struct node *root = NULL;	
		
	do
	{
	 printf("\n-----------Non Recursive BST------------:");
	 printf("\n\n1. Insert.\n");	
	 printf("\n2. Search.\n");	 
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
	   	     scanf(" %d", &num);
	   	     root = insert(root,num);		     
	 	   }
		   print(root, 0);
		   break;	
	
	    case 2:printf("\nEnter the value ");
		   scanf(" %d", &data);
		   flag = search(root, data);
		   if(flag)
			printf("Element is found...");
		   else
			printf("Element is not found...");
		   break;	    
	
	    case 3:print(root, 0);
	 	  break;
	
	    case 0:exit(1);

	    default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);

	printf("\n");	

	return 0; 
}
struct node* insert(struct node *root, int data)
{	
	struct node *t_root = NULL, *curr =root, *prev = root;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	  
	temp->val = data;
		
	if(root == NULL)
	{
	   
	   root = temp;
	   return root;   
	}
	while(curr != NULL)
	{
	 t_root = curr;

	  if(data > root->val)
	    curr = curr->right;	 
	  else
	    curr = curr->left;
	}

	 if(data > root->val)
	    t_root->right = temp;	 
	 else
	    t_root->left = temp;
	     
	return root;
	
}
int search(struct node *root, int key)
{	
	if(root == NULL || root->val == key)
	    return 0;

	while(root != NULL)
	{
	   if(key > root->val)
	     root = root->right;
	   else if(key < root->val)
		root = root->left;
	   else
	      return 1;
	}
	
	return 0;		
}

void print(struct node *root, int space)
{	
	if(root == NULL)
	  return ;
	
	space += count; 

	printf("%d\t", root->val);
	//for(int i = count; i<space; i++)
	    // printf(" ");
	print(root->left, space);
	
	print(root->right,space);
	 //printf("\n");	
}

