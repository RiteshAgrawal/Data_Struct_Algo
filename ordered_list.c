/*
	Data Structure : Ordered Linked list
	Insert integer value in the linked list in ascending order

*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node node;

node* getnode()
{
	node* p;
	p=(node*)malloc(sizeof(node));
	p->next=NULL;
	return p;
}
int insert(node** head,int val)
{
	node* temp,*q,*p;
	p=q=*head;
	temp=getnode();
	temp->info=val;
	if ( p==NULL)
	{
		*head=temp;
		return 0;
	}
	else
	{
		if (p->info > val)
		{
			temp->next=p;
			*head=temp;
			return 1;
		}
		while(p->info < val )
		{
			q=p;
			p=p->next;
			if(p==NULL)
				break;
		}
		temp->next=q->next;
		q->next=temp;
		return 0;
	}
}

int delete(node **head,int val)
{
	node *p,*q;
	p=q=*head;
	if (*head==NULL)
		return 1;
	else
	{
		if (p->info==val)
		{
			*head=p->next;
			free(p);
			return 0;
		}
		while(p!=NULL)
		{
			if (p->info == val)
			{
				q->next=p->next;
				free(p);
				return 0;
			}
			q=p;
			p=p->next;
		}

	}
	return 1;
}


void display(node* head)
{
	node*p;
	p=head;
	printf("\n");
	while(p!=NULL)
	{
		printf("%d->",p->info);
		p=p->next;
		//if (p==NULL)
		//	printf("\ndone\n");
		//printf("%d",head->info);
	}
	printf("\b\b");
}	


int main()
{
	node* head=NULL;
	int operation,vali,vald,t;
	do
	{
		printf("\nPlease select any operation which you want to perform on ordered Linked List\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&operation);
		switch(operation)
		{
			case 1:
				printf("\nEnter the value which you want to insert: ");
				scanf("%d",&vali);
				insert(&head,vali);
				break;
			case 2:
				printf("\nEnter value which you want to delete: ");
				scanf("%d",&vald);
				t=delete(&head,vald);
				if (t)
					printf("\nValue not in list\n");
				break;

			case 3:
				display(head);
				break;

			case 4:
				
				break;

			default:
				printf("\nPlease select valid input");
				break;
		}
	}while(operation!=4);
	return 0;

}

