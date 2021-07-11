#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BST{
	int data;
	struct BST* left;
	struct BST* right;
};
typedef struct BST node;
node* createnode(int n)
{
	node* nodenew;
	nodenew=(node*)malloc(sizeof(node));
	nodenew->data=n;
	nodenew->left=nodenew->right=NULL;
	return nodenew;	
}
node* insert(node* root,int n)
{
	if(root==NULL)
	{
		root=createnode(n);
	}
	else if(n<= root->data)
	{
		root->left=insert(root->left, n);
	}
	else
	{
		root->right=insert(root->right, n);
	}
	return root;
}

int search(node* root,int sn)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(sn== root->data)
	{
		return 1; 
	}
	else if(sn<=root->data)
	{
		return search(root->left,sn);
	}
	else
	{
		return search(root->right,sn);
	}
//return root;
}
int main()
{
	int choice,n,sn;
	node* root=NULL;
	while(1)
	{
		printf("1.Insert\t");
		printf("2.Search\t");
		printf("3.Exit\n");
		printf("Enter  yout choice : ");
		scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			printf("Enter a number to insert : ");
			scanf("%d",&n);
			root=insert(root,n);
			break;
		case 2 :
			printf("Enter a number to search : ");
			scanf("%d",&sn);
			if(search(root,sn)==0)
			{
				printf("Element NOT found\n");
			}
			else
			{
				printf("Element Found\n");
			}
		case 3 : 
			exit(0);
		}
	}
	getch();
	return 0;
}

