#include<stdio.h>
#define NTERMS 100
int  main()
{
	int a,b,d=2,i;
	scanf("%d %d",&a, &b);
	int terms = a;
	for(i = 0; i < NTERMS;i++)
	{
		printf("%d ", terms);
		terms = terms + d;
		d = d + b;
	}
	return 0;
}
