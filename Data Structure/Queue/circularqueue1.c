#include <stdio.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear =-1;
int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}
int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}
void enQueue()
{
    int data;
    printf("Enter Data: ");
    scanf("%d",&data);
    if(isFull()) printf("\n Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = data;
    }
}
int deQueue()
{
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else {
            front = (front + 1) % SIZE;
            
        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}
void print()
{
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
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
            enQueue();
            break;
        case 2:
            deQueue();
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