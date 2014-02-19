#include<stdio.h>
void print(char src,char dest)
{
	printf("Move %c to %c\n",src,dest);
}
void Tower(int n,char src,char dest,char temp)
{
	if (n==1)
		print(src,dest);
	else
	{
		Tower(n-1,src,temp,dest);
		Tower(1,src,dest,temp);
		Tower(n-1,temp,dest,src);
	}
}

int main()
{
	int n;
	char src[3];
	printf("\nEnter the number of stacks which you want to move\n");
	scanf("%d",&n);
	printf("\nEnter source name destination name and spare name (only single character per name with no spaces in between eg.abc)\n");
	scanf("%s",src);
	printf("\n\n");
	Tower(n,src[0],src[1],src[2]);
	return 0;
}

