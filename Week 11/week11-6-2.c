#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(void){
	
	char c[100];
	FILE *fp=NULL;
	fp=fopen("sample.txt", "r");
	

	if (fp==NULL)
		printf("Cannot open file\n");
		
	while(fscanf(fp, "%s", c)!=EOF){
		printf("%s\n", c);
	}
	
	fclose(fp);
	
	return 0;
}