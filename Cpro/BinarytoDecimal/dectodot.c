#include<stdio.h>
int dectodot(int n){
	int decimal=0;
	int temp = n;
	int lastdigit;
	int z = 1;
	while(temp){
		lastdigit = temp % 10;
		temp = temp/10;

		decimal= decimal + lastdigit * z;
		z=z*2;
	}
	return decimal;
}
int main(){
	int num = 1010;
	printf("Number is: %d", dectodot(num));
}