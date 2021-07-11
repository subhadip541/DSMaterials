#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BST{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST node;
node *createnode(int n)
{
	node* nodenew;
	nodenew=(node*)malloc(sizeof(node));
	nodenew->data=n;
	nodenew->left=nodenew->right=NULL;
	return nodenew;	
}
node *insert(node* root,int n)
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
void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d -> ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d -> ",root->data);
	inorder(root->right);
}
void postorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d -> ",root->data);
}
int main()
{
	int choice,n,sn;
	node* root=NULL;
	while(1)
	{
		printf("1.Insert\t");
		printf("2.Pre-order trversal\t");
		printf("3.In-order trversal\t");
		printf("4.Post-order trversal\t");
		printf("5.Exit\n");
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
			printf("Pre-order trversal : ");
			preorder(root);
			printf("\n");
			break;
		case 3 :
			printf("In-order trversal : ");
			inorder(root);
			printf("\n");
			break;
		case 4 :
			printf("Post-order trversal : ");
			postorder(root);
			printf("\n"); 
			break;
		case 5 : 
			exit(0);
			break;
		}
	}
	getch();
	return 0;
}

