#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
void insert( struct Node **head_ref, int new_data)
{
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void insertAfter (struct Node *prev_node, int new_data)
{
	if(prev_node == NULL)
	{
		printf("Previous node cannot be NULL");
		return;	
	}
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void append (struct Node **head_ref, int new_data)
{
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref=new_node;
		return;
	}
	while(last->next != NULL)
		last=last->next;
	last->next = new_node;
	return;
}
void printlist(struct Node *node)
{
	while(node!=NULL)
	{
		printf("%d ",node->data);
		node=node->next;
	}
}
int search(struct Node *head,int x)
{
	struct Node *current=head;
	int count = 0;
	while(current != NULL)
	{
		if( current->data ==x)
			return count;
		count++;
		current=current->next;
	}
}
int main()
{
	struct Node *head = NULL;
	int i,flag=1;
	while(flag!=0)
	{	
		printf("Wants to insert at beginning, inbetwwen,end(1/2/3) or NO (0):");
		scanf("%d",&i);
		
		switch(i)
		{
			case 1:
			{	
				int key;
				printf("Enter the key to insert:");
				scanf("%d",&key);
				insert(&head,key);
				printf("Created Linked List:");
				printlist(head);
			
				break;
	
			}
			case 2:
			{	
				int key,x,n;
				printf("Enter the key to insert and after which element:");
				scanf("%d %d",&key,&x);
				n=search(head,x);
				insertAfter(n,key);
				printf("Created Linked List:");
				printlist(head);
				break;
			}
			case 3:
			{
				int key;
				printf("Enter the key to insert:");
				scanf("%d",&key);
				append(&head,key);
				printf("Created Linked List:");
				printlist(head);
				break;
			}
			case 0:
			{	
				flag=0;
				break;
			}
		}
	}
	
	
	return 0;
}

