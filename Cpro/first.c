#include<stdio.h>
char array[10][20];
int main(){
	int i;
	for(i=0;i<3;i++)
   		scanf("%s",array[i]);

   	for(i=0;i<3;i++)
   		printf("a[%d]=%d",i,array[i]);

   	return 0;
}