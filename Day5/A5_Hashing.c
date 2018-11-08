/*Implement Hashing technique using Open addressing and Separate Chaining.*/

#include<stdio.h>

int main()
{
	int n, value, temp, hash, a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("\nEnter the value of n(table size): ");
	scanf("%d", &n);

	do
	{
	   printf("\nEnter the hash value: ");
	   scanf("%d", &value);

	   hash = value % n;

	   if(a[hash] == 0)
	   {
	     a[hash] = value;
	     printf("\na[%d]the value %d is stored", hash, value);
	   }
	   else
	   {
	       for(hash++; hash<n; hash++)
	       {
	         if (a[hash] == 0)
	         {
	           printf("\nSpace is allocated give other value");
	           a[hash] = value;
	           printf("\na[%d]the value %d is stored", hash, value);
	           goto menu;
	         } 
	       }
	       for(hash=0; hash<n; hash++)
	       {
	         if (a[hash] == 0)
	         {
	           printf("\nSpace is allocated give other value");
	           a[hash] = value;
	           printf("\na[%d]the value %d is stored", hash, value);
	           goto menu;
	         }
	       } 

	       printf("\n\nERROR\n");
	       printf("\nEnter '0' and press 'Enter key' twice to exit");

	   }

	   menu:
	
	   printf("\nDo you want enter more");
	   scanf("%d", &temp);
	}while(temp == 1);

	return 0;
}

