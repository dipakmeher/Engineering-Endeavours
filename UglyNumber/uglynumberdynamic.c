//Source: G4G
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int max(unsigned a, unsigned b,unsigned c){
	int largest = a; 

	if(b > largest)
		largest = b;

	if(c > largest)
		largest = c;

	return largest;
}

int min(unsigned a, unsigned b,unsigned c){
	int smallest = a; 

	if(b < smallest)
		smallest = b;

	if(c < smallest)
		smallest = c;

	return smallest;
}

unsigned GetnthUglyNo(unsigned n){
	unsigned ugly[n];
	ugly[0]=1;
	unsigned i2,i3,i5;
	i2=i3=i5=0;
	unsigned next2 = 2;
	unsigned next3 = 3;
	unsigned next5 = 5;
	unsigned next_ugly_no = 1;

	for (int i = 1; i < n; i++)
	{
		next_ugly_no = min(next2,next3,next5);
		ugly[i] = next_ugly_no;

		if (next_ugly_no == next2)
		{
			i2 = i2 + 1;
			next2 = ugly[i2]*2;
		}

		if (next_ugly_no == next3)
		{
			i3 = i3 + 1;
			next3 = ugly[i3]*3;
		}

		if (next_ugly_no == next5)
		{
			i5 = i5 + 1;
			next5 = ugly[i5]*5;
		}
	}
	return next_ugly_no;
}
int main(){
	unsigned no = 150;
	printf("%d\n", GetnthUglyNo(no));
	return 0;
}