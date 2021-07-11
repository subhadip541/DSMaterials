#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *prev;
	struct node *next;
};
struct node *insertany(struct node *start,int item,int position);
struct node *insertend(struct node *start,int item);
struct node *del(struct node *start,int item);
void display(struct node *start);
int main()
{
	struct node *start=NULL;
	int choice,position,item;
	printf("-----DOUBLE LINKED LIST-----");
	while(1)
	{
		printf("\n");
		printf("1.INSERT AT ANY \t");
		printf("2.INSERT AT END \t");
		printf("3.DELETE\t");
		printf("4.DISPLAY\t");
		printf("5.EXIT\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the position to insert : ");
				scanf("%d",&position);
				printf("Enter the element to insert : ");
				scanf("%d",&item);
				start=insertany(start, item,position);
				break;
			case 2:
				printf("Enter the element to insert : ");
				scanf("%d",&item);
				start=insertend(start, item);
				break;
			case 3:
				printf("Enter the element to delete : ");
				scanf("%d",&item);
				start=del(start,item);
				break;
			case 4:
				display(start);
				break;
			case 5:
				exit(0);
				break;
			default :
				printf("WRONG CHOICE \n");
				break;
		}
	}
	return 0;
	getch();
}
struct node *insertany(struct node *start,int item,int position)
{
	struct node *temp,*p;
	int i;
	temp=(struct node*)malloc(sizeof(struct node)); 
	if(position == 0)
		printf("Enter the valid position\n");
	if(position==1)
	{
		if(start==NULL)
		{
			temp->info=item;
			temp->prev=NULL;
			temp->next=NULL;
			start=temp;
			return start;
		}
		else
		{
			temp->info=item;
			temp->prev=NULL;
			temp->next=start;
			start->prev=temp;
			start=temp;
			return start;
		}
	}
	else
	{
		int count;
		p=start;
		for(i=1;i<=position && p->next!=NULL;i++)
		{
			p=p->next;
		}
		temp->info=item;
		temp->prev=p->prev;
		temp->next=p;
		p->prev->next=temp;
		p->prev=temp;
		return start;
	}
}
struct node *insertend(struct node *start,int item)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	temp->info=item;

	temp->next=NULL;
	temp->prev=p;
		p->next=temp;
	return start;	
}
void display(struct node *start)
{
	struct node *p;
	int count=0;
	p=start;
	printf("-----LIST IS-----\n");
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->next;
		count++;
	}
	printf("\nNumber of nodes : %d",count);
	printf("\n");
}
struct node *del(struct node *start,int item)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	if(start->next==NULL)//Delition of only node
	{
		if(start->info==item)
		{
			temp=start;
			start=NULL;
			free(temp);
			return start;
		}
		else
		{
			printf("%d not found\n",item);
			return start;
		}
	}
	if(start->info==item)//1st node
	{
		temp=start;
		start=start->next;
		start->prev=NULL;
		free(temp);
		return start;
	}
	temp=start->next;
	while(temp->next!=NULL)//n node
	{
		if(temp->info==item)
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			return start;
		}
		temp=temp->next;
	}
	if(temp->info==item)//Last node
		{
		temp->prev->next=NULL;
		free(temp);
		return start;
		}
}

