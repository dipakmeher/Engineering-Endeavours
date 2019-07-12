
//Tower of Hanoi
#include<stdio.h>

void TOH(int n, char from_disk, char to_disk, char aux_disk){
	if(n==1){
		printf("Move disk from %c to %c \n",from_disk,to_disk );
		return;	
	}
	TOH(n-1,from_disk,aux_disk,to_disk);
	printf("Move disk from %c to %c \n",from_disk,to_disk);
	TOH(n-1,aux_disk,to_disk,from_disk);
}
int main(){
	int disk = 4;
	TOH(disk,'A','C','B');
	return 0;
}