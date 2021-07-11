#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char str[10];
int top=-1;
void push(int item);
int pop();
int main()
{
	int i=0,item,val1,val2,val3;
	printf("Enter the Expression : ");
	gets(str);
	while(str[i]!='\0')
	{
		if(str[i]>='0' && str[i]<='9')
		{

			item=str[i]-48;
			//printf("%d\t",item);
			push(item);
		}
		else
		{
			val1=pop();
			val2=pop();
			switch(str[i])
			{
				case '+':
					val3=val1+val2;
					push(val3);
					break;
				case '-':
					val3=val2-val1;
				
					push(val3);
					break;
				case '*':
					val3=val1*val2;
					
					push(val3);
					break;
				case '/':
					val3=val2/val1;
				
					push(val3);
					break;
			}
		}
		i++;
	}
	printf("Expression will be :%d ",pop());
//	int p=pop();
	//printf("%d",pop());
	return 0;
}
void push(int item)
{
	top=top+1;
	str[top]=item;
}
int pop()
{
	int item=str[top];
	top=top-1;
	return item;
}
