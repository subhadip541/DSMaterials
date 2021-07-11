#include<stdio.h>
#include<conio.h>
#define max 10
int stack[max];
int top=-1;
void push(int item);
int pop(int item);
void display();
int main()
{
	int item,choice ;
	while(1)
	{
		printf("1.Push elements into stack :\t");
		printf("2.Pop elements from stack :\t");
		printf("3.Display elements of stack : \n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1 :
					printf("enter the element to push : ");
					scanf("%d",&item);
					push(item);
					break;
				case 2 :
					item=pop(item);
					printf("elemnt pop from stack is : %d\n",item);
					break;
				case 3 :
					display();
					break;
				default :
					printf("wrong dicision ");
					printf("\n");
			}
	}
	return 0;
}
void push(int item)
{
	if(top==max-1)
	{
		printf("stack is full");
	}
	else
	{
		top=top+1;
		stack[top]=item;
	}
}
int pop(int item)
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else
	{
		item=stack[top];
		top=top-1;
		return item;
	}
}
void display()
{
	printf("Now the stack is : \n");
	for(int i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
	printf("\n");
}


