#include"translate.h"
#include"inputCheckChange.h"

void inputAndCheck(char file1[],char file2[],struct Word *lang1,struct Word *lang2,FILE *fp1,FILE *fp2,char language1[],char language2[])
{
	char verb[20];	
	
	printf("\nВведіть слово:   ");	
	gets(verb);
	changeGapsUnderscore(verb,' ','_');
		
	fp1=fopen(file1,"r");
	fp2=fopen(file2,"r");
	if(fp1==NULL){
		printf("Файл %s не відкрився",file1);
		return;
	}
	if(fp2==NULL){
		printf("Файл %s не відкрився",file2);
		return;
	}		
	findTranslate(fp1,fp2,lang1,lang2,verb,file1,file2,language1,language2);	
}

void changeGapsUnderscore(char verb[],char symb1,char symb2)
{
	int i;
	for(i=0;verb[i]!='\0';i++){
		if(verb[i]==symb1){
			verb[i]=symb2;
		}
	}
}
