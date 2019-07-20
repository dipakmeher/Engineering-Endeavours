#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h> 
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
struct node *newnode(int a){
	struct node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = a;
	temp->left = temp-> right = NULL;
	return temp;
}

bool areMirror(node *t1, node *t2){
	if(t1 == NULL && t2 == NULL){
		return 1;
	}
	

	if(t1 == NULL || t2 == NULL){
		return 0;
	}

	return t1->data = t2->data &&
			areMirror(t1->left,t2->right)&&
			areMirror(t1->right,t2->left);

}

int main(){
	struct node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(2);

	root->left->left = newnode(3);
	root->right->right = newnode(3);
	struct node *t1 = root;
	struct node *t2 = root;

	areMirror(t1,t2)? printf("Yes"): printf("No");
	return 0;
}