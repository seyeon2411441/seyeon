#include <stdio.h>
#include <stdlib.h>
#define STUDENTNUM 4

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	int ID;
	int score;
};
void main(void){
	struct student s[STUDENTNUM];
	int total_score=0;
	int max_score=0;
	int max_ID=0;
	
	for(int i=0;i<STUDENTNUM;i++){
		printf("Input the ID: ");
		scanf("%d",&s[i].ID);
		printf("Input the score: ");
		scanf("%d",&s[i].score);
		
		total_score += s[i].score;
		
		if(s[i].score>max_score){
			max_score=s[i].score;
			max_ID=s[i].ID;
		}
		
    }
    double average=total_score/(float)STUDENTNUM;
    
	printf("The average of the score: %f",average);
	printf("The highest score - ID:%d, score:%d",max_ID,max_score);
	
}