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
	int item;
	if(rear==max-1)
	{
		printf("QUEUE IS FULL\n");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		printf("Enter the element to insert: ");
		scanf("%d",&item);
		rear++;
		q[rear]=item;
	}
}
void dequeue()
{
	if(front==-1 || front>rear)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		printf("Element deleted is : %d\n",q[front]);
		front++;
	}
}
void display()
{
	printf("Now the queue is : ");
	for(int i=front;i<=rear;i++)
	{
		printf("\t%d",q[i]);
	}
	printf("\n");
}

