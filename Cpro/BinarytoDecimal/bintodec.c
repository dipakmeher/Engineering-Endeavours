#include<stdio.h>
#include<string.h>
int main(){
	char a[20];
	int i=0;
	scanf("%s",a);
	char delim[] = " ";
	char *arr = strtok(a,delim);
	int n = 4;
	int array[20];
	int bin[n];
	int remainder;
	long long binary ;
	int z ;
	int lastdigit;
	 while(arr != NULL)
	{
		printf("'%s'\n", arr);
		arr = strtok(NULL, delim);
	}
// 	while (arr != NULL)
//     {
//         array[i++] = atoi(arr);
//         arr = strtok (NULL, "-");
//     }

// for (i = 0; i < 4; i++)
//   	{
//   		printf("%d ",array[i]);
//   	}

 //    for (i = 0; i < n; i++)
 //    {
 //   		int decimal=0;
	// 	z = 1;
 //    	while(array[i]>0){
	// 		lastdigit = array[i] % 10;
	// 		array[i] = array[i]/10;

	// 		decimal= decimal + lastdigit * z;
	// 		z=z*2;
	// 		bin[i] = decimal;
	// 	}
 //    }
 // for (i = 0; i < n; i++)
 //  	{
 //  		printf("%d. ",bin[i]);
 //  	}

	return 0;	
}   
