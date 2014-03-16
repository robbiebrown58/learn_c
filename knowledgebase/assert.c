#include <assert.h>
#include <stdio.h>

//turn off assertions -DNDEBUG

int main()
{
   int a;
   char str[50];
	 
   printf("Enter an integer value: ");
   scanf("%d\n", &a);
   assert(a >= 10);
   printf("Integer entered is %d\n", a);
    
   printf("Enter string: ");
   scanf("%s\n", str);
   assert(str != NULL);
   printf("String entered is: %s\n", str);
	
   return(0);
}
