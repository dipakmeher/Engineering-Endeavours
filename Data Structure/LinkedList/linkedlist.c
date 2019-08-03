#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head;

struct node *create(){
	int data;
	struct node *temp;
	printf("Enter data: ");
	scanf("%d",&data);
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
void Insert(){
	struct node *newnode = create();
	if (head == NULL)
	{
		head = newnode;
	}
	else{
		struct node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void Delete(){
	struct node *temp = head, *prev;
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	if (temp != NULL && temp->data == data)
	{
		head = temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL && temp->data!=data){
		prev = temp;
		temp=temp->next;
		if(prev->next->next == NULL && temp->data != data){
			printf("Element not found\n");
			return;			
		}
	}
	if (temp == NULL){
		return;
	}

	prev->next = temp->next;
	free(temp);
}

void Display(){
	struct node *temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
void main(){
int ch;
printf("\n---------------------------Linked List Operation-----------------------------------------    \n");
    printf("Enter your choice for following operation:\n");
    printf(" 1->Insert() \t 2->Delete() \t 3->Display()\t 4->InsertAtAnyPosition()\t 5->exit()\t \n");
    printf("------------------------------------------------------------------------------------------\n");
do{
printf("EnterOperation no. you want to perform: ");
scanf("%d",&ch);
switch(ch){
case 1:
   Insert();
   break;

case 2:
   Delete();
   break;
case 3:
   Display();
   break;

default:
   printf("Invalid Data");
   break;
}
}while(ch!=4);
}