/*Create an AVL tree by including functionality for inserting, singlerotationleft, singlerotationright, doublerotationleft & doublerotationright.*/


#include<stdio.h>
#include<stdlib.h>

struct node{
	int val, height;
	struct node *left;
	struct node *right;
};


struct node* insert(struct node *, int);
struct node *left_rotate(struct node *);
struct node *right_rotate(struct node *);
void preorder_traversal(struct node *);
struct node *newnode( int);
int get_balance(struct node *);
int height(struct node *);
int max(int, int);

int main()
{
	int n, num, i, ch, data, val;	
	struct node *root = NULL;	
		
	do
	{
	 printf("\n\n\n-----------AVL Tree------------:\n");
	 printf("\n\n1. Insert.\n");
	 printf("\n2. Single rotation left.\n");
	 printf("\n3. Single rotation right.\n");
	 printf("\n4. Double rotation left.\n");
	 printf("\n5. Double rotation right.\n");	 
	 printf("\n6. Preorder traversal.\n");
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
		   preorder_traversal(root);
		   break;
		
	    case 2:root = left_rotate(root);
		   preorder_traversal(root);
		   break;
		
	    case 3:root = right_rotate(root);
		   preorder_traversal(root);
		   break;
	
	    case 4:
		   break;

	    case 5:
		   preorder_traversal(root);
		   break;

	    case 6:printf("\nAfter preorder_traversal : \n");
		   preorder_traversal(root);
		   break;

	    case 0:exit(1);

	    default :printf("\nInvalid Input\n");

	  }

	}while(ch > 0);

	printf("\n");	

	return 0; 
}
int height(struct node *root)
{
	if(root == NULL)
	  return 0;

	return root->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
struct node *newnode( int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	newnode->val = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 1;

	return newnode;
}

struct node *left_rotate(struct node *root)
{
	struct node *temp = root->right;
	struct node *t_root = temp->left;

	temp->left = root;
	root->right = t_root;

	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;

	return temp;
}

struct node *right_rotate(struct node *root)
{
	struct node *temp = root->left;
	struct node *t_root = temp->right;

	temp->right = root;
	root->left = t_root;

	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;

	return temp;
}

int get_balance(struct node *root)
{
	if(root == NULL)
	  return 0;

	return (height(root->left) - height(root->right));
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

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = get_balance(root);

	if((balance > 1) && (data < root->left->val))  
	  return right_rotate(root);

	
	if((balance < -1) && (data > root->right->val))  
	  return left_rotate(root);

	
	if((balance > 1) && (data > root->left->val))  
	{
	    root->left = left_rotate(root->left);

	    return right_rotate(root);
	}

	if((balance < -1) && (data < root->right->val))  
	{
	    root->right = right_rotate(root->right);

	    return left_rotate(root);
	}
	
	return root;

}

void preorder_traversal(struct node *root)
{
	if(root != NULL)
	{
	  printf("\t%d", root->val);
	  preorder_traversal(root->left);
	  preorder_traversal(root->right);
	}
}	

