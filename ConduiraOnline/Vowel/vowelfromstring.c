#include<stdio.h>
#include<stdlib.h>

int main()
{
	char c;
	int Vcount=0, Ccount = 0;
	int isVowel(char);
	int isConsonant(char);
	// scanf("%c",&c);

	do{
		c=getchar();
		if (isConsonant(c))
		{
			Ccount++;
		}
		if (isVowel(c)){
			Vcount++;
		}

	}while(c != '\n'); 
	printf("%d %d\n",Vcount, Ccount);
	return 0;
}
int isVowel(char c){
		switch(c){
			case 'a':case 'o':case 'i':case 'e':case 'u':
			case 'A':case 'O':case 'I':case 'E':case 'U': return 1;
		}
		return 0;
}
int isConsonant(char c){
	if((c>='a' && c<='z') || (c>= 'A' && c<='Z')){
		if (isVowel(c)==1)
			return 0;
		return 1;
	}
	return 0;// I made mistake previously here.
}
