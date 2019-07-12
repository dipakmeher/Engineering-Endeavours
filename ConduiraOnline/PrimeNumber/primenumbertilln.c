	//prime numbers
	#include<stdio.h>
	int main(){
		int N,i;
		char e;
		int isPrime(int);
		scanf("%d",&N);
		for(i = 2;i<=N;i++){
			if (isPrime(i))
			{
				printf("%d ",i);
			}
			// else{
			// 	printf("%d ",i);
			// }
		}
	}


	int isPrime(int a){
		int i;
		if(a<2)
			return 0;

		for (int i = 2; i < a; i++)
		{
			if (a%i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
