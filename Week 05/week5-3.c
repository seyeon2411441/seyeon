#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int x;
	int a,b;
	
	printf("Input the second: ");
	scanf("%i",&x);
	
	a=x/60;
	b=x-a*60;
	
	printf("The time is %i : %i", a,b);
	return 0;
}