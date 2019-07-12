#include<stdio.h>
#include<stdlib.h>
int even_no_sum(int a[],int n){
	int i,sum=0;
	for(i=0;i<n;i++){
		if(a[i]%2 == 0){
			sum += a[i]; 
		}
	}
	return sum;
}
int main(){
	int *a,i,n;
	printf("Size of an array: \n");
	scanf("%d",&n);

	a = (int *)malloc(sizeof(int) * n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",even_no_sum(a,n));
	return 0;
}