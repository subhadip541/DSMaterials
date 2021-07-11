#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *reverse(struct node *start);
struct node *begin(struct node *start,int data);
struct node *end(struct node *start,int data);
struct node *nposition(struct node *start,int data,int position);
struct node *del(struct node *start,int data);
void count(struct node *start);
void display(struct node *start);
int main()
{
	struct node *start=NULL;
	int choice,data,position;
	printf("----------Enter the elements in a linked list----------\n");
	while(1)
	{
		printf("\n");
		printf("1.Reverse\t");
		printf("2.At beginig\t");
		printf("3.At end\t");
		printf("4.At any position\t");
		printf("5.Display\t");
		printf("6.Delete\t");
		printf("7.Count\t");
		printf("8.Exit\n");
		printf("\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				start=reverse(start);
				break;
			case 2 :
				printf("Enter the element to insert : ");
				scanf("%d",&data);
				start=begin(start,data);
				break;
			case 3:
				printf("Enter the element to insert : ");
				scanf("%d",&data);
				start= end(start,data);
				break;
			case 4:
				printf("Enter the position to insert : ");
				scanf("%d",&position);
				printf("Enter the element to insert : ");
				scanf("%d",&data);
				start= nposition(start,data,position);
				break;
			case 5:
				display(start);
				break;
			case 6 :
				printf("Enter the element to delete : ");
				scanf("%d",&data);
				start=del(start,data);
				break;
			case  7 :
				count(start);
				break;
			case  8 :
				exit(0);
				break;
			default :
				printf("-----Wrong choice-----\n");
		}
	}
	return 0;
}
struct node *reverse(struct node *start)
{
	struct node *prev,*next,*ptr;
	ptr=start;
	prev=NULL;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}	
	start=prev;
	return start;
}
struct node *begin(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
}
struct node *end(struct node *start,int data)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p->link != NULL)
	{
		p=p->link;	
	}
	p->link=temp;
	temp->link=NULL;
	return start;
}
struct node *nposition(struct node *start,int data,int position)
{
	int i;
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	if(position==1)
	{
		temp->link=start;
		start=temp;
		return start;
	}
	p=start;
	for( i=1;i<position-1 && p!=NULL;i++)
	{
		p=p->link;
	}
	if(p==NULL)
	{
		printf("-----There is less than elements than %d----- \n",position);
	}
	else
	{
		temp->link=p->link;
		p->link=temp;
	}
	return start;	
}
void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("-----The list is empty-----\n");
	}
	else
	{
		p=start;
		printf("-----List is ----- \n");
		while(p!=NULL)
		{
			printf("%d\t",p->info);
			p=p->link;
		}
		printf("\n");
	}
}
struct node *del(struct node *start,int data)
{
	struct node *p,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("list is empty\n");
	}
	if(start->info==data)//deletion of 1st node
	{
		temp=start;
		start=start->link;
		free(temp);
		return start;	
	}
	p=start;
	while(p!=NULL)//delete of nth node
	{
		if(p->link->info==data)
		{
			temp=p->link;
			p->link=temp->link;
			free(temp);
			return start;
		}
		p=p->link;
	}
}
void count(struct node *start)
{
	struct node *p;
	int i,count=0,sum=0;
	p=start;
	printf("Even number nodes are : ");
	while(p!=NULL)
	{
		count++;
		
		if(count%2==0)
		{
			printf("%d\t",p->info);
		}
		sum+=p->info;
		p=p->link;
	}
	printf("\nNumber of nodes : %d\n",count);
	printf("sum of nodes is : %d\n",sum);
}

