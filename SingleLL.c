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
int insertAfter(int prevdata, int data)
{
	struct Node *currentNode = Header, *ptr= newNode();
	while(currentNode->next != NULL && currentNode->data != prevdata)
		currentNode= currentNode->next;
	if(currentNode->data != prevdata)
		printf("Node not found\nInsertion Failed \n");
	else 
	{
		ptr->next = currentNode->next;
		ptr->data = data;
		currentNode->next = ptr;
	}
	return (0);

}
int append(int data)
{
	struct Node *newptr = newNode(), *currentNode = Header;

	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}

	newptr->next = currentNode->next;
	newptr->data = data;
	currentNode->next = newptr;
	return (0);
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
		printf("1. Insert at Front\n");
		printf("2. Insert after\n");
		printf("3. Insert at End\n");
		printf("4. Delete node\n");
		printf("5. Delete all\n");
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
				printf("Enter the data after which node is to be created and the data to be inserted:");
				scanf("%d %d",&prevdata,&data);
				insertAfter(prevdata,data);
				printlist();
				break;
			}
			case 3:
			{
		
				printf("Enter the data to insert:");
				scanf("%d",&data);
				append(data);
				printlist();
				break;
			}
			case 4:
			{
				printf("Enter data to be deleted : ");
				scanf("%d", &data);
				DeleteNode(data);
				printlist();
				break;	
			}
			case 5:
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
