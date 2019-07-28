#include<stdio.h>
#include<stdlib.h>
#define size 5
int front=-1;
int rear = -1;
int arr[size];

int enqueue(){
	int data;
	printf("Enter Data: ");
	scanf("%d",&data);

	if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
	{
		printf("Queue is full\n");
		return;
	}
	else if(front = -1){//Inserting first element
		front=rear = 0;
		arr[rear] = data;
	}
	else if(front != 0 && rear == size - 1){
		rear = 0;
		arr[rear] = data;
	}
	else{
		rear++;
		arr[rear]=data;
	}
	print();
}

int dequeue(){
	int data;
	if (front = -1)
	{
		printf("Queue is empty\n");
		return ;
	}
	data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear == -1;
	}
	else if(front == size -1){
		front = 0;
	}
	else{
		front++;
	}
	print();
	printf("The deleted element is: %d.\n",data);
}

int print(){
	
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",arr[i]); 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            printf("%d ", arr[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf("%d ", arr[i]); 
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