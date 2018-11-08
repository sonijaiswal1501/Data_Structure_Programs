/*Write a function is_palindrome which takes a string as argument and returns 1 if True,0 if False.*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top= -1, front= 0;
char string[50];

void push(char );
char pop(void);
int is_palindrome(void);

int main()
{	
	int result = 0;
	
	
	printf("\nEnter an expression :\t");
	scanf("%s", string);
	
	result = is_palindrome(); 

	if(result != 0)
	   printf("\n%s is not palindrome..\n", string); 
	else
	  printf("\n%s is palindrome..\n", string);	
	     
	return 0;
}
int is_palindrome(void)
{
	int i, length=0, flag=0, result = 0;
	char string_rev[50];
	
	length = strlen(string);	

	for(i=0; i<length; i++)	
	    push(string[i]);	 

	for(i=0; i<length; i++)	
	     string_rev[i] = pop();

	result = strcmp(string_rev,string);	
 
	if(result)
	  return 1; 
	else
	  return 0;	
	
}
void push(char ch)
{
	if(top == 50)	
	{
	   printf("\nError: stack overflow..\n");
	   exit(1);
	}

	top++;
	string[top] = ch;
}
char pop(void)
{
	if(top == -1)	
	{
	   printf("\nError: No element to pop ..\n");
	   return 0;
	}

	return (string[top--]);
}
