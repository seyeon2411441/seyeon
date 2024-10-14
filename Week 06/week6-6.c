#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int answer=50;
	int i;
	int attempt=0;
	
	do {
		printf("Geuss a number: ");
		scanf("%d", &i);
		attempt++;
		
		if (i<answer) {
			printf("Low!\n");
		} else if (i>answer){
			printf("High!\n");
		} else {
			printf("Congratulation! Trials: %d\n",attempt);
		}
	} while(i != answer);
	
	return 0;
}