//Change the ip address from dotted to binary
#include<stdio.h>
#include<string.h>
int main(){
	char a[20];
	int i=0;
	scanf("%s",a);
	char *arr = strtok(a,".");
	int n = 4;
	int array[20];
	int bin[n];
	int remainder;
	long long binary ;
	int z ;
	while (arr != NULL)
    {
        array[i++] = atoi(arr);
        arr = strtok (NULL, ".");
    }

    // int n = sizeof(array)/sizeof(int);

    for (i = 0; i < n; i++)
    {
   		binary = 0;
   		z=1;
   		if (array[i]>255)
   		{
   			printf("Enter digit less than 255.\n");
   			return 0;
   		}
    	while(array[i] > 0){
    		remainder = array[i]%2;
    		array[i] = array[i]/2;
    		binary += remainder*z;
      		z *= 10;
      		bin[i] = binary;
    	}
    }
  
  	for (i = 0; i < n; i++)
  	{
  		printf("%d ",bin[i]);
  		printf("\n");
  	}

	return 0;	
}
