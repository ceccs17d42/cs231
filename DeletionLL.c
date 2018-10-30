#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*Header;
int DeleteAll()
{
	struct Node *ptr=Header, *prevprt;
	while(ptr!=NULL)
	{
		prevprt=ptr;
		ptr=ptr->next;
		free(prevprt);
	}
}
struct Node *newNode()
{
	struct Node *newptr = malloc(sizeof(struct Node));
	if (newptr == NULL)
	{
		printf("Memory Overflow");
		DeleteAll();
		exit(0);
	}
	return (newptr);
};
int DeleteNode(int data)
{
	struct Node *currentNode= Header,*prevNode;
	while(currentNode->data != data && currentNode->next!= NULL)
	{
		prevNode= currentNode;
		currentNode = currentNode->next;
	}	
	if (currentNode->data !=data)
		printf("Node not found.\n Deletion Failed \n" );
	else
		{
			prevNode->next=currentNode->next;
			free(currentNode);
		}
}
int insert(int data)
{
	struct Node *ptr = newNode();
	ptr->next =Header->next;
	ptr->data = data;
	Header->next= ptr;
}
int printlist() {
	struct Node *currentNode = Header->next;
	printf("\nLinked List\nHeader->");
	while (currentNode != NULL) {
		printf("%d->", currentNode->data);
		currentNode = currentNode->next;
	}
	return (0);
}
int ShowMenu()
{
	int i=1,data,prevdata;
	while(i!=0)
	{	
		printf("\n\tLINKED LIST\n");
		printf("1. Insert\n");
		printf("2. Delete node\n");
		printf("3. Delete all\n");
		printf("0. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&i);
		
		switch(i)
		{
			case 1:
			{	
				printf("Enter the data to insert:");
				scanf("%d",&data);
				insert(data);
				printlist();
			
				break;
	
			}
			
			case 2:
			{
				printf("Enter data to be deleted : ");
				scanf("%d", &data);
				DeleteNode(data);
				printlist();
				break;	
			}
			case 3:
			{
				DeleteAll();
				break;
			}

			case 0:
			{	
				i=0;
				break;
			}
		}
	}	
	return 0;
}

int main()
{
	Header = malloc(sizeof(struct Node));
	Header->data = 0;
	Header->next = NULL;
	ShowMenu();
	return (0);
}