// here b is difference, c is increment in difference, a intial term
#include<stdio.h>
#define NTERMS 100
int  main()
{
	int a,b,c,d,i;
	scanf("%d %d %d",&a, &b, &c);
	int terms = a;
	for(i = 0; i < NTERMS;i++)
	{
		printf("%d ", terms);
		d=b;
		terms = terms + d;
		d = d+b;
		b = b+c;
	}
	return 0;
}//1:12:51
