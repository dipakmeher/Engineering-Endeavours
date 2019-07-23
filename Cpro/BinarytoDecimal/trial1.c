#include <stdio.h>
#include <string.h>

int main()
{
	
	char str[20];
	scanf("%[^\n]s",str);

	int init_size = strlen(str);
	char delim[] = " ";

	char *ptr = strtok(str, delim);

	int n = 4;
	int array[20];
	int bin[n];
	int remainder;
	long long binary ;
	int z ;
	int lastdigit;
	int i=0;
	while (ptr != NULL)
    {
        array[i++] = atoi(ptr);
        ptr = strtok (NULL, delim);
    }

    for (i = 0; i < n; i++)
    {
   		int decimal=0;
		z = 1;
    	while(array[i]>0){
			lastdigit = array[i] % 10;
			array[i] = array[i]/10;

			decimal= decimal + lastdigit * z;
			z=z*2;
			bin[i] = decimal;
		}
    }
 printf("%d.%d.%d.%d ",bin[0],bin[1],bin[2],bin[3]);

	return 0;	
}   
