#include<stdio.h>
int main(){
	int i,currentstreak, beststreak,n,d,e;

	printf("Enter no. of element in array: \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements in array:");

	for ( i = 0; i < n; i++)
	{
		printf("a[%d] =",i);
		scanf("%d",&a[i]);
	}
	currentstreak=beststreak = a[0];
	d=0;
	for(i=0;i<n;i++){
		if(currentstreak>=0){
			currentstreak = currentstreak+a[i];
		}
		else
		{
			currentstreak = a[i];  //if currentstreak = -3 & a[i]=4; make currentstreak = 4 directly
			d=i;
		}
		if(beststreak<currentstreak){
			beststreak = currentstreak;
			e=i;
		}
	}
	printf("beststreak= %d\n", beststreak);
	printf("a = %d b= %d \n", d,e);
	return 0;
}