#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	int ID;
	char name[100];
	double grade;
};

int main(void){
	struct student s1={2411441,"Seyeon",4.2};
	s1.ID=24;
	strcpy(s1.name,"Eunju");
	s1.grade=4.3;
	
	printf("ID: %d\n",s1.ID);
	printf("Name:%s\n",s1.name);
	printf("Grade:%.2f\n",s1.grade);
	
	
}
	