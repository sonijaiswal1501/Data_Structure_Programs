/*1. Add following functions to Binary Search Tree(BST)
1) height_of_tree
2) mirror_image
3) number_of_ nodes
4) inorder_traversal
5) preorder_traversal
6) postorder_traversal*/


#include<stdio.h>
#include<stdlib.h>


struct node{
	int val;
	struct node *left;
	struct node *right;
};

struct node* insert(struct node *, int);
int height(struct node *);
void mirror(struct node *);
int number_of_nodes(struct node *);
void inorder_traversal(struct node *);
void preorder_traversal(struct node *);
void postorder_traversal(struct node *);
void print(struct node *, int );

int main()
{
	int n, num, i, ch, data, val;	
	struct node *root = NULL;	
		
	do
	{
	 printf("\n\n\n-----------BST Tree------------:\n");
	 printf("\n\n1. Insert.\n");
	 printf("\n2. Height_of_tree.\n");
	 printf("\n3. Mirror_image.\n");
	 printf("\n4. number_of_ nodes.\n");
	 printf("\n5. inorder_traversal.\n");
	 printf("\n6. preorder_traversal.\n");	 
	 printf("\n7. postorder_traversal.\n");
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
		
	    case 2:val = height(root);
		   printf("\nNumber of height are %d.\n", val);
		   break;
		
	    case 3:mirror(root);
		   print(root, 0);
		   break;
	
	    case 4:val = number_of_nodes(root);
		   printf("\nNumber of nodes are %d.\n", val);
		   break;

	    case 5:printf("\nAfter inorder_traversal : \n");
		   inorder_traversal(root);
		   break;

	    case 6:printf("\nAfter preorder_traversal : \n");
		   preorder_traversal(root);
		   break;

	    case 7:printf("\nAfter postorder_traversal : \n");
		   postorder_traversal(root);
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

int height(struct node *root)
{
	static int max_left=0,  max_right=0;

	if(root->left != NULL)
	{
	  max_left++;
	  height(root->left);
	}
	if(root->right != NULL)
	{ 
	   max_right++;
	   height(root->right);
	}
	 
	if(max_left >  max_right)
	    return (max_left+1);
	else
	    return  (max_right+1);
	
}

void mirror(struct node *root)
{
	if(root == NULL)
	  return;
	else
	{
	   struct node* temp;

	   mirror(root->left);
	   mirror(root->right);

	   temp = root->left;
	   root->left = root->right;
	   root->right = temp;
	}
}

int number_of_nodes(struct node *root)
{
	int i=1;

	if(root == NULL)
	   return 0;
	else
	{
	   i += number_of_nodes(root->left);
	   i += number_of_nodes(root->right);
	   return i;
	}
}

void inorder_traversal(struct node *root)
{
	if(root == NULL)
	  return;

	inorder_traversal(root->left);
	printf("\t%d", root->val);
	inorder_traversal(root->right);
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

void postorder_traversal(struct node *root)
{
	if(root == NULL)
	  return;

	postorder_traversal(root->left);
	printf("\t%d", root->val);
	postorder_traversal(root->right);
}	
void print(struct node *root, int space)
{	
	int count=10;	
	
	if(root == NULL)
	  return ;
	
	space += count; 
	printf("..%d\t", root->val);	
		
	print(root->left, space);
	for(int i = count; i>space; i++)
	    printf("-- ");
	print(root->right, space); 
	printf("\n");
	
}








