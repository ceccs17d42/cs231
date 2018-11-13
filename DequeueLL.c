#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

void main()
{
    struct node *head,*temp,*tem;
    int cho,ele=0;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=NULL;
    head->llink=NULL;
    head->rlink=NULL;
    do
    {
        printf("\nMENU\n1.Insertion(FRONT)\n2.Deletion(FRONT)\n3.Insertion(END)\n4.Deletion(END)\n5.Display\nEnter choice: ");
        scanf("%d",&cho);

        if(cho==1)
        {
            
            printf("Enter element: ");
            scanf("%d",&ele); 
/*            if(head->rlink==NULL)
            {
                temp=(struct node*)malloc(sizeof(struct node));
            temp->data=ele;
            temp->llink=head;
            temp->rlink=NULL;
            head->rlink=temp;
            }
*/

            tem=head->rlink;
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=ele;
            temp->llink=head;
            temp->rlink=tem;
            head->rlink=temp;
            tem->llink=temp;
            break;
            
        }           

        else if(cho==2)
        {            
            if(head->rlink==NULL)
            {
                printf("\nQueue is EMPTY\n");
            }
            else
            {
                tem=head->rlink;
                temp=tem->rlink;
                head->rlink=temp;
                temp->llink=head;
                printf("\nDELETED %d ",tem->data);
                free(tem);
            }
            break;
        }
        else if(cho==3)
        {
            printf("Enter element: ");
            scanf("%d",&ele);
            tem=head->rlink;
            while(tem->rlink!=NULL)
            {
                tem=tem->rlink;
            }
                    
            temp=(struct node*)malloc(sizeof(struct node));
            temp->llink=tem;
            temp->rlink=NULL;
            tem->rlink=temp;
            temp->data=ele;
            break;
        }            
        else if(cho==4)
        {
            if(head->rlink==NULL)
            {
                printf("\nQueue is EMPTY\n");
            }
            else
            {
                tem=head->rlink;
                while(tem->rlink!=NULL)
                {
                    tem=tem->rlink;
                }
                temp=tem->llink;
                temp->rlink=NULL;
                printf("\nDELETED %d ",tem->data);
                free(tem);
            }
            break;
        }
        else if(cho==5)
        {
            if(head->rlink==NULL)
            {
                printf("\nQueue is EMPTY\n");
            }
            else
            {
                temp=head->rlink;
                while(temp!=NULL)
                {
                    printf("%d <-",temp->data);
                    temp=temp->rlink;
                }
                printf(" NULL\n");
            }
            break;
        }
    }while(cho==1 || cho==2 || cho==3 || cho==4 || cho==5);
}
