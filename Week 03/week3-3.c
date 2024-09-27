#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	char x,y;
	
	printf("enter a character :");
	scanf("%c",&x);
	
	y=x+1;
	printf("the next character of %c(%i) is %c(%i)",x,x,y,y);
	
	return 0;
}