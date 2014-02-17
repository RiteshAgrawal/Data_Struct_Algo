/*
Data Structure : Linked List

*/
#include<stdio.h>
#include<stdlib.h>

//Structure for a single node
struct node
{
	int info;
	struct node *next;
	struct node* back;
};
typedef struct node node;		// Changing structure name from "struct node" to "node"

int Display(node*);			//Prototype for Display function

node* Getnode()				//This function provide a node
{
	node* p;
	p= ((node*)malloc(sizeof(struct node)));
	return p;
}

node* Assign_node(int val)		//Initialise the node (not for doubly)
{
	node *n;
	n=Getnode();
	n->info = val;
	n->next = NULL;
	return n; 
}


void Insert_begin(node** head, int val)		//Insert node at the begining of the linked list
{
	node*  temp;
	temp=Assign_node(val);
	if (*head==NULL)
		*head=temp;
	else
	{
		temp->next=*head;
		*head=temp;
	}
}

void insert_end_doubly(node **head,int val)	//To insert at the end of doubly linked list
{
	node* temp,*p;
	temp = Getnode();
	temp->info = val;
	if (*head == NULL)
	{
		*head = temp;
		temp->next = temp->back = temp;
	}
	else
	{
		p=*head;
		while(p->next != *head)
			p=p->next;
		p->next = temp;
		temp->back = p;
		temp->next = *head;
		(*head)->back = temp;
	}
}
void Insert_end(node** head,int val)		//Insert at end for singly linked list
{
	node* temp,*p;
	p=*head;
	temp=Assign_node(val);
	if (*head==NULL)
		*head=temp;
	else
	{
		while(p->next!=NULL)
			p=p->next;
		
		p->next=temp;
	}
}


int Delete_position(node**head,int pos)		//Delete node by giving position in singly linked list
{
	int i=1;
	node *p;
	p=*head;
	p=p->next;
	if (pos==1)
	{
		free(*head);
		*head=p;
		return 0;
	}
	p=*head;
	while(i<pos-1)
	{
		p=p->next;
		i++;
	}
	free(p->next);
	p->next=p->next->next;
	return 0;

}

int Delete_value (node **head,int val)		//Delete node by value in singly linked list
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


int Display(node *head)					//To display linked list
{
	int n=0;
	node* p;
	p=head;
	printf("\n");
	if (head==NULL)
	{
		printf("No element to display\n");
		return 0;
	}
	while(1)
	{
		printf("%d->",p->info);
		
		p=p->next;
		if (p == head )			//p==head for doubly and p==NULL for singly linked list
		{	
			break;
			
		}
		

	n++;
	}
	
	printf("\n");
}

void delete_doubly(node** head,int val)		//Delete node by value in doubly linked list
{
	node *p;
	int flag2=0;
	p=*head;
	do
	{
		if(p->info==val)
		{
			flag2=1;
			break;
		}
		p=p->next;
	}while(p!=*head);
	if(flag2)
	{
		p->back->next = p->next;
		p->next->back = p->back;
		
		if (p==*head)
		{
			if(p->next==*head)
				*head=NULL;
			else
				*head=p->next;
		}
		free(p);
	}
	else
		printf("Element not found");
	
}



int main()
{
	node* head=NULL;
	int i;
	printf("Enter the number:");
	scanf("%d",&i);
	while(i<1)					//Testing
	{
		insert_end_doubly(&head,i);
		i++;
	}
	delete_doubly(&head,0);
	Display(head);
	//Delete_position(&head,5);
	//insert_end_doubly(&head,5);
	//Display(head);
	//head = head->next->next;
	//printf("%d %d %d ",head->back->info,head->info,head->next->info);
}
