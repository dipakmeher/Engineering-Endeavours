#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}Node;
struct Node *create(){
	Node *temp;
	printf("Enter data: \n");
	temp = (Node*)malloc(sizeof(Node));
	scanf("%d", &temp->data);
	temp->left=temp->right=NULL;
	return temp;
}

int insert(Node *root, Node *temp){
	if (temp->data<root->data)
	{
		if (root->left != NULL)
		{
			insert(root->left, temp);
		}
		else{
			root->left = temp;
		}
	}

	if (temp->data>root->data)
	{
		if (root->right != NULL)
		{
			insert(root->right, temp);
		}
		else{
			root->right = temp;
		}
	}
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main(){
	char ch;
	Node *root = NULL,*temp;
	do
	{
		temp = create();
		if (root == NULL)
		{
			root = temp;
		}else{
			insert(root,temp);
		}

		printf("Do you want to enter again: \n");
		getchar();
		scanf("%c",&ch);
	}while(ch=='y'| ch=='Y'); 

	printf("TREE: \n");
	preorder(root);
	return 0;
}
