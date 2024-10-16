#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sumTwo(int a,int b)
{
	int result;
	result=a+b;
	return result;
}

int square(int n)
{
	int result;
	result=n*n;
	return result;
}

int get_max(int x,int y)
{
	int result;
	if (x>y){
		result=x;
	}else {
		result=y;
	}
	return result;
	
}
int main(void){
	
	int c,d;
	int result1,result2,result3;
	printf("Enter the integers: ");
	scanf("%d %d", &c ,&d);
	
	result1 =sumTwo(c,d);
	result2 =square(c);
	result3 =get_max(c,d);	
	printf("Result - Sum:%d, Square:%d, Max: %d\n",result1, result2,result3);
	
	return 0;
}
