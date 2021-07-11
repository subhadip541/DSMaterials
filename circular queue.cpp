#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 6
int rear=-1,front=-1;
int q[max];
void enqueue();
void dequeue();
void display();
int main()
{
	int choice;
	while(1)
	{
		printf("1.Insert\t");
		printf("2.Delete\t");
		printf("3.Display\t");
		printf("4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);

			default:
				printf("Wrong choice\n");
				break;
		}
	}
	return 0;
}
void enqueue()
{
	int n;
	if((front==0 && rear==max-1) || (front==rear+1))
	{
		printf("Queue is Full\n");
	}
	else
	{
		printf("Enter the element to insert : ");
		scanf("%d",&n);
		if(rear==-1)
			front=rear=0;	
		else if(rear==max-1)
			rear=0;
		else
			rear++;
		q[rear]=n;
	}
}
void dequeue()
{
	int a;
	if(front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		a=q[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(front==max-1)
			front=0;
		else
			front++;
		printf("Deleted element is : %d\n",a);
	}
}
void display()
{
	int i,j;
	if(front>rear)
	{
		for(i=front;i<max;i++)
			printf("\t%d",q[i]);
		for(j=0;j<=rear;j++)
			printf("\t%d",q[j]);
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("\t%d",q[i]);
		}
		printf("\n");
	}
}
