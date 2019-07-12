#include<stdio.h>
#define NTERMS 100
int  main()
{
	int a=4, d=2,i;
	int terms = a;
	for(i = 0; i < NTERMS;i++)
	{
		printf("%d ", terms);
		terms = terms + d;
	}
	return 0;
}
