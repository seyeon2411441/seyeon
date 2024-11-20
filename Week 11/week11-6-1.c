#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(void) 
{
    FILE *fp = NULL;
    char c;
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
        printf("Cannot open file.\n");

    while ((c = fgetc(fp)) != EOF) 
        putchar(c); 

    fclose(fp);
}