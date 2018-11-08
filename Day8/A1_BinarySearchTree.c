/*1. Create Binary Search Tree(BST) with the following functions
1. insert_into_bst
2. deletion_from_bst
3. fnd_in_bst
4. fnd_min_in_bst
5. fnd_max_in_bst*/


#include<stdio.h>
#include<stdlib.h>
#define count 10

struct node{
	int val;
	struct node *left;
	struct node *right;
};

struct node* insert(struct node *, int);
struct node* deletion(struct node *, int);
struct node* find(struct node *, int);
int find_min(struct node *);
int find_max(struct node *);
void print(struct node *, int);

int main()
{
	int n, num, i, ch, data, min, max;	
	struct node *root = NULL;	
		
	do
	{
	 printf("\n-----------Binary Search Tree------------:");
	 printf("\n\n1. Insert.\n");
	 printf("\n2. Delete.\n");
	 printf("\n3. find.\n");
	 printf("\n4. find min.\n");
	 printf("\n5. find max.\n");	 
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
	   	     scanf(" %d", &num);
	   	     root = insert(root,num);
	 	   }
		   print(root, 0);
		   break;
		
	    case 2:printf("\nEnter the value ");
		   scanf(" %d", &data);
		   root = deletion(root, data);
		   print(root, 0);
		   break;
	
	    case 3:printf("\nEnter the value ");
		   scanf(" %d", &data);
		   if(find(root, data))
			printf("Element is found...");
		   else
			printf("Element is not found...");
		   break;

	    case 4:min = find_min(root);
		   printf("\nMinimum number in list is %d", min);
		   break;

	    case 5:max = find_max(root);
		   printf("\nMaximum number in list is %d", max);
		   break;

	    case 6:print(root, 0);
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
	if(root == NULL)
	{
	   struct node *temp = (struct node *)malloc(sizeof(struct node));
	  
	   temp->val = data;
	   temp->left = temp->right = NULL;
	   root= temp;
	}
	if(data < root->val)
	  root->left = insert(root->left, data);

	else if(data > root->val)
	  root->right = insert(root->right, data);	

	return root;
}
struct node* find(struct node *root, int key)
{	
	if(root == NULL || root->val == key)
	    return root;	
	 
	if(key < root->val)
	  return find(root->left, key);
	else
	  return find(root->right, key);		
}
struct node* deletion(struct node *root, int data)
{
	if(root == NULL)
	   return root; 
	if(data < root->val)
	  root->left = deletion(root->left, data);
	else if(data > root->val)
	  root->right = deletion(root->right, data);	
	else 
	{
	   if(root->left == NULL)
	   {
	      struct node *temp = root->right;
	      free(root);
	      return temp;
	   }
	   else
	   {
	      struct node *temp = root->right;
	      free(root);
	      return temp;
	   }	

	}

	return root;
}

int find_min(struct node *root)
{
	struct node *current = root;

	while(current->left != NULL)	
	     current = current->left;

	return current->val;
}
int find_max(struct node *root)
{
	struct node *current = root;

	while(current->right != NULL)	
	     current = current->right;

	return current->val;
}

void print(struct node *root, int space)
{	
	if(root == NULL)
	  return ;
	
	space += count; 

      	printf("\t%d", root->val);
	//printf("\n");
	for(int i = count; i<space; i++)
	    printf(" ");
	 
	print(root->left, space);
	print(root->right,space);
	 
}


