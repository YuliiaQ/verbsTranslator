#include"translate.h"
#include"inputCheckChange.h"

void inputVerb(FILE *fp,char file[],struct Word *lang1,int count,char language[])
{	
	char tmp[20];
	
	fclose(fp);
	fp=fopen(file,"a");													
	printf("\nВведіть інфінітив (Input infinitive)(%s):   ",language);
	scanf("%s",lang1->infinitive);
	printf("Введіть минулий час (Input past)(%s):   ",language);
	scanf("%s",lang1->past);								
	printf("Введіть майбутній час (Input future)(%s):   ",language);
	getchar();
	gets(tmp);
	changeGapsUnderscore(tmp,' ','_');	
	strcpy(lang1->future,tmp);
	lang1->identifier=count;
	printf("\n%s %s %s %i\n",lang1->infinitive,lang1->past,lang1->future,lang1->identifier);
	fprintf(fp,"\n%s %s %s %i",lang1->infinitive,lang1->past,lang1->future,lang1->identifier);
	fclose(fp);	
}

char requestAnswer()//request for input new verb in s dictionary
{
	char answer;
	printf("\nВнести слово в словник? 1 - так, 2 - ні\n(Insert the word in the dictionary? 1 - yes, 2 - no):   ");
	do{
		answer=getch();
		if(answer!='1'&&answer!='2'){
			continue;
		}							
	}while(answer!='1'&&answer!='2');
	printf("%c\n",answer);
	return answer;
}

void findTranslate(FILE *fp1,FILE *fp2,struct Word *lang1,struct Word *lang2,char verb[],char file1[],char file2[],char language1[],char language2[])
{
	char answer;
	int count=0;
	while(1){
			if(EOF==fscanf(fp1,"%s%s%s%i",lang1->infinitive,lang1->past,lang1->future,&lang1->identifier)){
				printf("\nСлово відсутнє (The word is absent)\n");
				answer=requestAnswer();
				if(answer=='2'){
					break;
				}
				else{					
					inputVerb(fp1,file1,lang1,count+1,language1);				
					inputVerb(fp2,file2,lang2,count+1,language2);
				}
				break;
			}		    
			else{
			count++;						
				if(strcmp(verb,lang1->infinitive)==0){
					while(1){
						if(EOF==fscanf(fp2,"%s%s%s%i",lang2->infinitive,lang2->past,lang2->future,&lang2->identifier)){
							printf("\nПереклад відсутній (No translation)\n");
							answer=requestAnswer();												
							if(answer=='2'){
								break;
							}
							else{							
								inputVerb(fp2,file2,lang2,count,language2);																					
							}
							break;						
						}
						else{										
							if(lang1->identifier==lang2->identifier){
								changeGapsUnderscore(lang2->future,'_',' ');
								printf("\nПереклад (Translate):   %s - %s - %s\n",lang2->infinitive,lang2->past,lang2->future);
								break;
							}
							else{
								continue;
							}
						}						
					}					
				}
				else{
					if(strcmp(verb,lang1->past)==0){
						while(1){
							if(EOF==fscanf(fp2,"%s%s%s%i",lang2->infinitive,lang2->past,lang2->future,&lang2->identifier)){
								printf("\nПереклад відсутній (No translation)\n");
								answer=requestAnswer();												
								if(answer=='2'){
									break;
								}
								else{							
									inputVerb(fp2,file2,lang2,count,language2);														
								}
								break;						
							}
							else{										
								if(lang1->identifier==lang2->identifier){
									printf("\nПереклад (Translate):   %s\n",lang2->past);
									break;
								}
								else{
									continue;
								}
							}											
						}
					break;	
					}
					else{
						if(strcmp(verb,lang1->future)==0){
							while(1){
								if(EOF==fscanf(fp2,"%s%s%s%i",lang2->infinitive,lang2->past,lang2->future,&lang2->identifier)){
									printf("\nПереклад відсутній\n");
									answer=requestAnswer();												
									if(answer=='2'){
										break;
									}
									else{							
										inputVerb(fp2,file2,lang2,count,language2);														
									}
									break;						
								}
								else{										
									if(lang1->identifier==lang2->identifier){
										changeGapsUnderscore(lang2->future,'_',' ');
										printf("\nПереклад (Translate):   %s\n",lang2->future);
										break;
									}
									else{
										continue;
									}
								}						
							}
							break;		
						}
					}
					continue;
				}
										
			}
			break;		
		}		
}

