#include<stdio.h>
#include<stdlib.h>
int main()
{
	char c;
	int isVowel(char);
	scanf("%c",&c);
	if (isVowel(c)==1)
	{
		printf("V\n");
	}
	else{
		printf("C\n");
	}
	return 0;
}
int isVowel(char c){
		switch(c){
			case 'a':case 'o':case 'i':case 'e':case 'u':
			case 'A':case 'O':case 'I':case 'E':case 'U': return 1;
		}
		return 0;
}