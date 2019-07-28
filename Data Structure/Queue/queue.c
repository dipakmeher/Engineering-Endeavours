#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5
int queue[MAXSIZE];
int rear = -1;
int front = 0;

int enqueue(){
	int data;
	scanf("%d",&data);
	if(rear == MAXSIZE-1){
		printf("Overflow\n");
	}	
	else{
		rear = rear+1;
		queue[rear] = data;
	}
	return;
}
int dequeue(){
	int del;
	if(front == rear){
		printf("Queue is empty.\n");
	}
	else{
		del = queue[front];
		front = front+1;
	}
	printf("Dequeued element is:%d.\n",del);
	return;
}
int print(){
	for (int i = front; i <= rear; ++i)
	{
		printf("%d ",queue[i]);	
	}
	return;
}
int main(){
	int d;
	char ch;
	do{
	printf("1.Insert\t2.Delete\t3.Print\t4.Break\n");
	scanf("%d",&d);
	switch(d){
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			print();
			break;
		case 4:
			exit(0);
			break;


		default:
			printf("Loop ends here.....\n");
	}
	printf("Do you want to perform more operation.\n");
	getchar();
	scanf("%c",&ch);
}while(ch == 'y' || ch == 'Y');
	return 0;
}