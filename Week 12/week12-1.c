#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void){
	int i=10;
	char c='a';
	
	int *iptr;
	char *cptr;
	int *iptr2;
	
	iptr=&i;
	cptr=&c;
	
	iptr2=iptr;
	
	printf("i: %p\n%p(size:%i)\n",iptr,&i,sizeof(iptr));
	printf("c's reference : %p \n %p\n (size : %i)\n", cptr, &c, sizeof(cptr));
	printf("iptr2 : %p \n %i\n ", iptr2, *iptr2);
}