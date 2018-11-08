//Write a program to Implement Evaluation of postfx expression.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 100
int top = -1;
int stack[size];
char postfix_exp[size];

void push(int);
int pop(void);
int isempty(void);
int postfix_evaluation(void);
int power(int, int);


int main()
{
	int result;

	printf("\nEnter an expression in postfix format:\t");
	scanf("%[^\n]s", postfix_exp);
	
	printf("\nExpression in postfix format:\t %s \n", postfix_exp);
	
	result = postfix_evaluation();

	printf("\nEvaluation of postfix expression\t%d\n", result);

	return 0;
}

int postfix_evaluation(void)
{
	int x, y, temp, value;
	int i;
	
	for(i=0; i < strlen(postfix_exp); i++)
	{
	  if(postfix_exp[i] <= '9' && postfix_exp[i] >= '0')
		push(postfix_exp[i] - '0');
	  else
	  {
	        x = pop();
		y = pop();
	
	        switch(postfix_exp[i])
	        {
		  case '+': temp = y + x;
			    break;
		  case '-': temp = y - x;
			    break;
		  case '*': temp = y * x;
			    break;
		  case '/': temp = y / x;
			    break;
		  case '%': temp = y % x;
			    break;
		  case '^': temp = power(y, x);
			    break;
	          default:  printf("Invalid");
		}
		push(temp);
	   }
        }
	value = pop();

	return value;
}

void push(int ch)
{
	if(top == size)	
	{
	   printf("\nError: stack overflow..\n");
	   exit(1);
	}

	top++;
	stack[top] = ch;
}
int pop(void)
{
	if(isempty())	
	{
	   printf("\nError: No element to pop ..\n");
	   exit(1);
	}
	return(stack[top--]);
}
int isempty(void)
{
	if(top == -1)	
	  return 1;
	else
	  return 0;
}
int power(int y, int x)
{
	if(x)
	{
	  return (y*power(y, x-1));
	}
	
	return 1;
}
	  


		

