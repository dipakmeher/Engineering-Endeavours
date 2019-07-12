//m - is a no of rounds
//pile[]- take care of no of piles
//N - index of the number we want at last
#include<stdio.h>
int main(){
	int i,m;
	scanf("%d\n",&m);
	int pile[m];
	for (i = 0; i < m; i++)
	{
		scanf("%d",&pile[i]);
	}
	int N;
	scanf("%d",&N);
	int numbers[100];
	int num = 1;
	for(i=0;i<100;i++){
		numbers[i]=num++;
	}
	int arr[100][100];
	int count=0;
	while(count<m){
		int r = pile[count];
		int c = 100/pile[count];
		if(pile[count]%2 != 0){
			c = c+1;
		}
		int x;
		int num = 0;
		for (int i = 0; i < r; i++)
		{
			num = x;
			for (int j = 0; j < c; j++)
			{
				if(j==0){
					arr[i][j] = numbers[num];
					num = num + pile[count];
				}
				else{
					int val = numbers[num];
					num = num + pile[count];
					if (val >0)
					{
						break;
					}
					else{
						arr[i][j] = val;
					}

				}
			}
			x++;
		}
		int index = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j]!=0)
				{
					numbers[index++]=arr[i][j];
				}
			}
		}
		count++;
	}
	printf("%d\n",numbers[N-1]);
}