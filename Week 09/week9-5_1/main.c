#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int all_flies;

extern void sub();

int main(void)
{
	sub();
	printf("%d\n",all_flies);
	return 0;
}

