#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	int arr[argc];
	if (argc < 2)
	{
		printf("Enter input\n");
		return -1;
	}
	else{
		for (int i = 1; i < argc; i++)
		{
			arr[i-1] = atoi(argv[i]);
			printf("arr[%d] =%d\n",i-1,arr[i-1]);
		}
	}
}