#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,sum;
	printf("Enter a number: ");
	scanf ("%d",&i);
	
	for (sum=0;i>0;i--){
		sum +=i;
	}
	
	printf("The result is %d\n",sum);
	return 0;
}