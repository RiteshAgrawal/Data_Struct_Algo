/*
	Data Structure : Stack
	Dynamic memory allocation
*/
#include<stdio.h>
#include<stdlib.h>
#define TYPE int

struct stack			
{
	TYPE *array;
	int top;
	int size;
};
typedef struct stack stack;

int IsFull(stack* s)			//To check full condition
{
	return (s->top==(s->size-1));
}

//To check empty condition
int IsEmpty(stack* s)			
{
	return (s->top==-1);
}
//Push element into the stack
void Push(stack* s,TYPE element)
{
	if (IsFull(s))
		s->array=realloc(s->array,sizeof(TYPE)*++s->size);	//If stack is full then reallocate stack size
	s->array[++s->top]=element;
}
//Pop element from the stack
TYPE Pop(stack* s)
{
	if (IsEmpty(s))
	{
		printf("\nStack is empty\n");
		return 0;	
	}
	else
		return (s->array[s->top--]);
}

//To initialize the stack parameters
void Initialise(stack* s)
{
	s->size=1;
	s->array=(TYPE*)malloc(sizeof(TYPE)*s->size);
	s->top=-1;
}
int main()
{
	stack s;
	Initialise(&s);
	int i,chk,element;
	do
	{
		printf("Select any poeration fron the given list\n1.Push\n2.Pop\n3.Exit\n");
		scanf("%d",&chk);
		switch(chk)
		{
			case 1:
				printf("\nEnter element\n");
				scanf("%d",&element);
				Push(&s,element);
				break;
			
			case 2:
				element=Pop(&s);
				printf("\nThe poped element is %d.\n",element);
				break;
			case 3:
				break;
			default:
				printf("\n****Please provide valid input****\n");
		}

	}while(chk!=3);
}


