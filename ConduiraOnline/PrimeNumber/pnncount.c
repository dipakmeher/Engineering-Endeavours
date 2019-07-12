	//print prime numbers till N number count

	#include<stdio.h>
	int main(){
		int N,K,i,count=0;
		char e;
		int isPrime(int);
		scanf("%d",&K);
		scanf("%d",&N);
		for(i = K+1;count<N;i++){
			if (isPrime(i))
			{
				printf("%d ",i);
				count++;
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
