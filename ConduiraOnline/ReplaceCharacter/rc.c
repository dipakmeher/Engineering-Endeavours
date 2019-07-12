//Replace a e f with b k l
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
int main(){
	char str[SIZE];
	int i,len;

	fgets(str, SIZE, stdin);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		switch(str[i])
		{
			case 'a': printf("b");break;
			case 'e': printf("k");break;
			case 'f': printf("l");break;
			default: printf("%c",str[i]);
		}
	}

	return 0;
}