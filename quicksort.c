#include<stdio.h>

int partition(int *,int,int);
int quicksort(int *,int,int);

int main(int argc, char const *argv[])
{
	int a[10],i,j,n;
	printf("Enter number of elements of array (less than 10)\n");
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		printf("Enter element number %d: ", i+1);
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("\n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

int quicksort(int *a,int l,int r)
{
	int j;
	if(r<=0 || l>=r)
		return;
	j= partition(a,l,r);
	quicksort(a,l,j-1);
	quicksort(a,j+1,r);
}

int partition(int *a,int l,int r)
{
	int piviot,i,j,temp,flag=0;
	piviot = *(a+l);
	i=l+1;
	j=r;
	while(i<=j)
	{
		flag =0;
		while(*(a+i) < piviot && i<r)
		{
			i++;							//Add condition if already sorted array is inserted in reverse order
		}
		while(*(a+j) > piviot && j>l)
		{
			j--;
			if(j<i)
			{
				flag =1;
				break;
			}
		}
		if(flag == 0 && j!=i)
		{
			temp = *(a+i);
			*(a+i) = *(a+j);
			*(a+j) = temp;
		}
		if(j==i)
			break;
	}
	if(l!=j)
	{
		temp = *(a+l);
		*(a+l) = *(a+j);
		*(a+j) = temp;
	}
	//printf("\n");
	//printf("%d\n",j );
	return j;
}
