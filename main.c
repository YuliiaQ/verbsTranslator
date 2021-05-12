#include"translate.h"
#include"inputCheckChange.h"
#include<windows.h>

int main()
{
	char lang,file1[8]="ukr.txt",file2[8]="eng.txt",key,ESC=27;
	struct Word *ukr,*eng;
	FILE *fpu,*fpe;	
	
	ukr=(struct Word*)malloc(sizeof(struct Word));
	eng=(struct Word*)malloc(sizeof(struct Word));
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	do{	
		printf("\n������� ����: � - ���������, � - ���������. ����� � �������� - ESC\n(Choose language: U - Ukraine, E - English. Exit - ESC):  ");
		do{
			lang=getch();
			if(lang==ESC) break;		
			if(lang=='�'||lang=='�'||lang=='U'||lang=='u'){
				printf("%c\n",lang);
				char language1[4]="���";
				char language2[4]="eng";			
				inputAndCheck(file1,file2,ukr,eng,fpu,fpe,language1,language2);	
				break;
			}				
			if(lang=='E'||lang=='e'||lang=='�'||lang=='�'){
				printf("%c\n",lang);
				char language1[4]="eng";
				char language2[4]="���";			
				inputAndCheck(file2,file1,eng,ukr,fpe,fpu,language1,language2);
				break;	
			}			
		}while(lang!='�'||lang!='�'||lang!='U'||lang!='u'||lang!='E'||lang!='e'||lang!='�'||lang!='�'||lang!=27);
		if(lang==ESC) break;
	
		printf("\n����������? ESC - �, ���� ������ - ���\n(Continue? ESC - no, other key - yes):   ");
		key=getch();		
	}while(key!=ESC);
	
	return 0;
}
