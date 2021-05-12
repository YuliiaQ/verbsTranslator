struct Word{
	char infinitive[20];
	char past[20];
	char future[20];	
	int identifier;
}; 

void inputAndCheck(char file1[],char file2[],struct Word *lang1,struct Word *lang2,FILE *fp1,FILE *fp2,char language1[],char language2[]);
void changeGapsUnderscore(char verb[],char symb1,char symb2);

