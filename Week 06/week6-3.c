#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char c;
	int i=0;
	printf("Input a string: ");
	
	while ((c=getchar()) != '\n') {
		if (c>='0'&& c<='9'){
			i++;
		}
	}
	
	printf("The number of digits is %d",i);
	return 0;
}