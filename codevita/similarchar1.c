#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int i,j,N,P;
	scanf("%d",&N);
	char s[N];
	scanf("%s", s); 
	int Q;
	scanf("%d",&Q);
	int value[Q];
	int count = 0;

	
	while(count < Q){
		scanf("%d",&P);
		char find = s[P-1];
		int freq = 0;
		for (int i = 0; i < P-1; i++)
		{
			if(s[i] == find){
				freq++;
			}
		}
		printf("%d\n",freq);
		count++;
	}
	
	return 0;
}