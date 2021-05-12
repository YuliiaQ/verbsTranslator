#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

extern struct Word *lang1, *lang2;

void inputVerb(FILE *fp,char file[],struct Word *lang1,int count,char language[]);
char requestAnswer();
void findTranslate(FILE *fp1,FILE *fp2,struct Word *lang1,struct Word *lang2,char verb[],char file1[],char file2[],char language1[],char language2[]);
