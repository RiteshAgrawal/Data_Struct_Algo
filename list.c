/*
	Data Structre : Linked List
	In this insert at beginning and insert at end both functionality works.

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
	p= ((node*)malloc(sizeof(struct node)));
	return p;
}

node* insert_node(int val)
{
	node *n;
	n=getnode();
	n->info = val;
	n->next = NULL;
	return n; 
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



void display(node *head)
{
	node* p;
	p=head;
	printf("\n");
	while(p!=NULL)
	{
		printf("%d->",p->info);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	int op,val,number,i;
	node *head=NULL,*temp,*p;
	do
	{
		printf("\nPlease select any operation which you want to perform\n1.Insert at begining\n2.Insert at end\n3.Display\n4.Exit\n");
		scanf("%d",&op);
		if (op==1 || op==2)
		{
			printf("\nPlease enter value which you want to perform\n");
			scanf("%d",&val);
		}
		switch(op)
		{
			case 1:
				if(head==NULL)
					head=insert_node(val);
				else
				{
					temp=insert_node(val);
					temp->next=head;
					head=temp;
				}
				break;

			case 2:
				if (head==NULL)
					head=insert_node(val);
				else
				{
					temp=insert_node(val);
					p=head;
					while(p->next!=NULL)
					{
						p=p->next;
					}
					p->next = temp;
					temp->next = NULL;
				}
				break;

			case 3:
				display(head);
				break;

			case 4:
				break;
			default:
				printf("\n****INVALID INPUT****\n");
				break;
		}
	}while(op!=4);
	return 0;
}

