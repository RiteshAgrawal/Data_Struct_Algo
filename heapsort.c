/*
	Heap sort Algorithm
*/
#include<stdio.h>
//Fn To swap two functions
void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	printf("%d%d\n",*x,*y);
}
//Fn to heapify a given node
int MaxHeapify(int *a,int i, int n)
{
	int large=i,l=i,r=i;
	//l=r=large=i;
	
		l=2*i;
	
		r=2*i+1;
	if (l<=n && a[l]>a[i])
		large=l;
	if (r<= n && a[r]>a[large])
		large=r;
//	printf("l= %d r=%d i=%d and large=%d\n",l,r,i,large);
	if (i!=large)
	{
		printf("\nloop\n");
		swap(&a[i],&a[large]);
		printf("%d\n",large);
		MaxHeapify(a,large,n);
	}
	return 0;
}
void heapsort(int *a,int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		MaxHeapify(a,1,n-i);
		swap(&a[1],&a[n-i]);
	}

}

int main()
{
	int a[20]={0},i,no;
	printf("Enter number of elements: ");
	scanf("%d",&no);
	for(i=1;i<=no;i++)
	{
		scanf("%d",&a[i]);
	}
	//swap(&a[1],&a[2]);
	for(i=no/2;i>=1;i--)
		MaxHeapify(a,i,no);
	//MaxHeapify(a,1,no);
	heapsort(a,no);
	for(i=1;i<=no;i++)
		printf("%d",a[i]);
	return 0;
}


