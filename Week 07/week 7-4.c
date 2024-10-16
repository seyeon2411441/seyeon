#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int factorial (int n)
{
	int res=1;
	for (int i=1;i<=n;i++){
		res=res*i;
	}
	return res;
}

int combination(int n,int r)
{
	return factorial(n)/(factorial(r)*factorial(n-r));
}

int get_integer()
{
	int i;
	printf("Enter the value: ");
	scanf("%d",&i);
	return i;
}

int main (void)
{
	int x,y;
	x=get_integer();
	y=get_integer();
	printf("The result of C(%d, %d) is %d",x,y,combination(x,y) );
	return 0;
}
	
