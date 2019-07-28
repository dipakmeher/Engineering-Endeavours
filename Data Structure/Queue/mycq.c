#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int front = -1,rear = -1;
int arr[SIZE];
int isfull(){
	if ((front == rear+ 1)||(front == 0 && rear == SIZE -1))
	{
		return 1;
	}
	return 0;
}
int isEmpty(){
	if(front == -1){
		return 1;
	}
	return 0;
}
void enqueue(){
	int data;
    printf("Enter Data: ");
    scanf("%d",&data);

	if(isfull()){
		printf("Queue is full\n");
	}
	else{
		if(front == -1){
			front = 0;
		}
		rear++;
		arr[rear] = data;
	}
}
void dequeue(){
	int del;
	if(isEmpty()){
		printf("Queue is empty.\n");
	}
	else{
		if (front == rear)
		{
			front =-1;
			rear = -1;
		}
		del = arr[front];
		front++;
		printf("Deleted element is %d.\n",del);
	}
}

void print(){
	if (isEmpty())
	{
		printf("Empty Queue");
	}
	else{
		printf("Front: %d\n",front);
		printf("Items: ");
		for (int i = front; i <= rear; i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
		printf("Rear: %d\n",rear);
	}
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