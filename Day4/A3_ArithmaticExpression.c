//Balancing parentheses in an Arithmetic Expression.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 100
int top = -1;
int expression[size];

void push(char);
char pop(void);
void find_top(void);
int check_paranthesis(char *);

int main()
{
	int i, val=0;
	char expression[size];
	
	printf("\nEnter an expression :\t");
	scanf("%s", expression);

	val = check_paranthesis(expression);	

	if(val == 1)
	   printf("\nExpression is valid and balanced\n");
	
	else
           printf("\nExpression is invalid and unbalanced\n");
        

	return 0;
}

int match_paranthesis(char a, char b)
{
	if(a == '[' && b == ']')
	   return 1;
	else if(a == '{' && b == '}')
	   return 1;
	else if(a == '(' && b == ')')
	    return 1;

	return 0;
}
int check_paranthesis(char *expression)
{
	int i;
	char temp;
	
	for(i=0; i < strlen(expression); i++)
	{
		if((expression[i] == '(') || (expression[i] == '{') || (expression[i] == '['))
		   push(expression[i]);

		if((expression[i] == ')') || (expression[i] == '}') || (expression[i] == ']'))
		{
		   if(top == -1)
		   {
		      printf("\nThe right paranthesis are more than the left paranthesis..\n");
		      return 0;
		   }
		   else
         	   { 
		     temp = pop();
		     if(!match_paranthesis(temp, expression[i]))
         	     	return 0;
		    }
		 }
	 }
	if(top == -1)
	  return 1;	 
	else
          return 0;
        		  
}

void push(char a)
{
	if(top == size-1)	
	{
	   printf("\nError: expression overflow..\n");
	   return;
	}

	top++;		
	expression[top] = a;
	
}
char pop(void)
{
	if(top == -1)	
	{
	   printf("\nstack is empty\n");
	   exit(1);
	}
	else
	 
	return (expression[top--]);
}	

