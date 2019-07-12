#include<stdio.h>
int Maxdivide(int a, int b){
	while(a%b == 0){
		a = a/b;
	}
	return a;
}
int isUgly(int no){
	no = Maxdivide(no, 2);
	no = Maxdivide(no, 3);
	no = Maxdivide(no, 5);

	return (no == 1)? 1:0;
}
int CheckNthuglyno(int n){
	int i =1;
	int count = 1;
	while(n > count){
		i++;
		if(isUgly(i)){
			count++;
		}
	}
	return i;
}
int main(){
		unsigned no = CheckNthuglyno(150);
		printf("%d\n", no);
		return 0;
}