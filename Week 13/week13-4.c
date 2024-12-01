#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct point{
	int x;
	int y;
};

int getarea(struct point p1, struct point p2){
	return abs(p2.x-p1.x)*abs(p2.y-p1.y);
}

int main(int argc, char*argv[]){
	struct point p1,p2;
	struct point *pPtr1, *pPtr2;
	
	int area;
	pPtr1=&p1;
	pPtr2=&p2;
	
	printf("Input the coordinate p1 (x,y): ");
	scanf("%d %d",&p1.x,&p1.y);
	printf("Input the coordinate p1 (x,y): ");
	scanf("%d %d",&p2.x,&p2.y);
	
	area=getarea(*pPtr1,*pPtr2);
	
	printf("The area of the rectangle is: %d\n",area);
	
	return 0;
}