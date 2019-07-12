	//prime numbers
	#include<stdio.h>
	int main(){
		int N,i;
		char e;
		int isPrime(int);
		do{
		scanf("%d",&N);
			if (isPrime(N))
			{
				printf("%d is prime number.\n",N);
			}
			else{
				printf("%d is not prime number.\n",N);
			}
		}while(N != 1);
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
