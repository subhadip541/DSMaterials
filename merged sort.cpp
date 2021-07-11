#include<stdio.h>
#include<conio.h>
void merge(int arr[],int left,int middle,int right)
{
	int i,j,k;
	int n1=middle-left+1;
	int n2=right-middle;
	int brr[n1];
	int crr[n2];
	for(i=0;i<n1;i++)
		brr[i]=arr[left+i];
	for(j=0;j<n2;j++)
		crr[j]=arr[middle+1+j];
	i=0;
	j=0;k=left;
	while(i<n1 && j<n2)
	{
		if(brr[i]<=crr[j])
		{
			arr[k]=brr[i];
			i++;
		}
		else
		{
			arr[k]=crr[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=brr[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=crr[j];
		j++;
		k++;
	}
}
void merge_sort(int arr[],int left,int right)
{
	if(left<right)
	{
		int i;
		int middle=(left+(right-1))/2;
		merge_sort(arr,left,middle);
		merge_sort(arr,middle+1,right);
		merge(arr,left,middle,right);
		
	}	
}
int main()
{
	int arr[10],i,n;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	printf("Sorted array ------\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
	return 0;
} 
