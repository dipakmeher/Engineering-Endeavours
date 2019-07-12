#include<stdio.h>
// #include<stdlib.h>
#include<limits.h>


int max(int a[], int n){
	int max = INT_MIN;

	for (int i = 0; i < n;i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

int LargeSum(int a[], int n){
	int max_end;
	int max_so_far;
	max_end = max_so_far =0;

	for (int i = 0; i < n; i++)
	{
		max_end = max_end + a[i];
		if (max_so_far < max_end)
		{
			max_so_far = max_end;
		}

		if(max_end < 0)
			max_end = 0;
	}
	if(max_so_far == 0){
		return max(a,n);
	}else{
		return max_so_far;
	}
}



int main(){
	int n;
	printf("Enter the no. of elements:\n");
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]= ",i);
		scanf("%d;\n",&a[i]);
	}
	printf("Max sub array is:%d",LargeSum(a,n));
	return 0;

}