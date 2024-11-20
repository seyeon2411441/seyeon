#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void){
	FILE*fp;
	char ch[100];
	int i;
	
	fp=fopen("sample.txt","w");
	
	for (i=0;i<3;i++){
		printf("input a word: ");
		scanf("%s",ch);
		fprintf(fp,"%s\n",ch);
	}
	fclose(fp);
	
	return 0;
}