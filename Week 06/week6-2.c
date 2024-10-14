#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i;
	printf("Enter an integer: ");
	scanf("%d",&i);
	
	if (i<0) {
		printf("%d",-i);
	}else {
		printf("%d",i);
	}return 0;
}